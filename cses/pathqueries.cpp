#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200010];
long long val[200010];
int pai[200010], heavy[200010], head[200010], pos[200010], nivel[200010];
long long seg[800010];
int cur_pos;
int inv[200010];

void build (int node, int l, int r) {
    if (l == r) {
        seg[node] = val[inv[l]];
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = seg[2*node] + seg[2*node+1];
}

int dfs (int x, int p) {
    int cur_maxi = 0;
    int tam = 1;
    for (int v : adj[x]) {
        if (v == p) continue;
        nivel[v] = nivel[x] + 1;
        pai[v] = x;
        int aux = dfs(v, x);
        tam += aux;
        if (aux > cur_maxi) {
            cur_maxi = aux;
            heavy[x] = v;
        }
    }
    return tam;
}

void decompose (int x, int h) {
    head[x] = h;
    pos[x] = ++cur_pos;
    inv[cur_pos] = x;
    if (heavy[x] != 0) {
        decompose(heavy[x], h);
    }
    for (int v : adj[x]) {
        if (v == pai[x] || v == heavy[x]) continue;
        decompose(v, v);
    }
}

long long seg_tree_query (int node, int l, int r, int l0, int r0) {
    if (l >= l0 && r <= r0) return seg[node];
    if (l > r0 || r < l0) return 0;
    int mid = (l+r)/2;
    return seg_tree_query(2*node, l, mid, l0, r0) + seg_tree_query(2*node+1, mid+1, r, l0, r0);
}

long long query (int a, int b) {
    long long ans = 0;
    for (; head[a] != head[b]; b = pai[head[b]]) {
        if (nivel[head[a]] > nivel[head[b]]) swap(a, b);
        ans += seg_tree_query(1, 1, cur_pos, pos[head[b]], pos[b]);
    }
    if (nivel[a] > nivel[b]) swap(a, b);
    ans += seg_tree_query(1, 1, cur_pos, pos[a], pos[b]);
    return ans;
}

void seg_tree_update (int node, int l, int r, int k, int val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if (k <= mid) seg_tree_update(2*node, l, mid, k, val);
    else seg_tree_update(2*node+1, mid+1, r, k, val);
    seg[node] = seg[2*node] + seg[2*node+1];
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    decompose(1, 1);
    build(1, 1, n);
    while (q--) {
        int id;
        cin>>id;
        int s, x;
        if (id == 1) {
            cin>>s>>x;
            seg_tree_update(1, 1, cur_pos, pos[s], x);
        }
        else {
            cin>>s;
            cout<<query(1, s)<<endl;
        }
    }
    return 0;
}