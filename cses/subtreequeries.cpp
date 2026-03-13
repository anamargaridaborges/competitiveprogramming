#include <bits/stdc++.h>

using namespace std;

int path[200010], subtree[200010], inv[200010];
int cur_pos;
vector<int> adj[200010];
long long val[200010], seg[800010], val_at[200010];

int dfs (int v, int p) {
    path[++cur_pos] = v;
    val_at[cur_pos] = val[v];
    inv[v] = cur_pos;
    subtree[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        subtree[v] += dfs(u, v);
    }
    return subtree[v];
}

void build (int node, int l, int r) {
    if (l == r) {
        seg[node] = val_at[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = seg[2*node] + seg[2*node+1];
}

void update (int node, int l, int r, int k, int val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if (k <= mid) {
        update(2*node, l, mid, k, val);
    }
    else update(2*node+1, mid+1, r, k, val);
    seg[node] = seg[2*node] + seg[2*node+1];
}

long long query (int node, int l, int r, int l0, int r0) {
    if (l >= l0 && r <= r0) return seg[node];
    if (l > r0 || r < l0) return 0;
    int mid = (l+r)/2;
    return query(2*node, l, mid, l0, r0) + query(2*node+1, mid+1, r, l0, r0);
}

int main () {
    int n, q;
    cin>>n>>q;
    for (int i=1; i<=n; i++) cin>>val[i];
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    //for (int i=1; i<=n; i++) cout<<inv[i]<<endl;
    build(1, 1, n);
    while(q--) {
        int id, s, x;
        cin>>id;
        if (id == 1) {
            cin>>s>>x;
            update(1, 1, n, inv[s], x);
        }
        else {
            cin>>s;
            cout<<query(1, 1, n, inv[s], inv[s] + subtree[s] - 1)<<endl;
        }
    }
    return 0;
}