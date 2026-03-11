#include <bits/stdc++.h>
#pragma once
#pragma GCC optimize("O3")
#pragma omp parallel

using namespace std;

vector<int> adj[200010];
int pai[200010], nivel[200010], heavy[200010], head[200010], pos[200010];
int cur_pos;
int seg[800010];
int aux1, aux2;

int dfs (int x, int p) {
    pai[x] = p;
    int sub_max = 0;
    int size = 1;
    for (int u : adj[x]) {
        if (u == p) continue;
        nivel[u] = nivel[x] + 1;
        int aux = dfs(u, x);
        size += aux;
        if (sub_max < aux) {
            sub_max = aux;
            heavy[x] = u;
        }
    }
    return size;
}

void decompose (int x, int h) {
    head[x] = h;
    pos[x] = ++cur_pos;
    if (heavy[x] != 0) {
        decompose (heavy[x], h);
    }
    for (int u : adj[x]) {
        if (u == pai[x]) continue;
        if (u == heavy[x]) continue;
        decompose (u, u);
    }
    return;
}

void seg_tree_update (int node, int l, int r, int l0, int r0) {
    if (l >= l0 && r <= r0) {
        seg[node] += 1;
        //cout<<l<<" "<<r<<" "<<aux1<<" "<<aux2<<endl;
        return;
    }
    if (l == r) return;
    if (l > r0 || r < l0) return;
    int mid = (l+r)/2;
    seg_tree_update(2*node, l, mid, l0, r0);
    seg_tree_update(2*node+1, mid+1, r, l0, r0);
}

void query (int a, int b) {
    for (; head[a] != head[b]; b = pai[head[b]]) {
        if (nivel[head[a]] > nivel[head[b]]) swap(a, b);
        //cout<<a<<" "<<b<<endl;
        seg_tree_update(1, 1, cur_pos, pos[head[b]], pos[b]);
    }
    if (nivel[a] > nivel[b]) swap(a, b);
    seg_tree_update(1, 1, cur_pos, pos[a], pos[b]);
    //cout<<a<<" "<<b<<endl;
    return;
}

int seg_tree_query(int node, int l, int r, int k) {
    if (l == r) {
        return seg[node];
    }
    int mid = (l+r)/2;
    if (k <= mid) return seg[node] + seg_tree_query(2*node, l, mid, k);
    else return seg[node] + seg_tree_query(2*node + 1, mid + 1, r, k);
}

void print_seg (int node, int l, int r) {
    if (l == r) {
        cout<<l<<" "<<r<<" "<<seg[node]<<endl;
        return;
    }
    int mid = (l+r)/2;
    cout<<l<<" "<<r<<" "<<seg[node]<<endl;
    print_seg(2*node, l, mid);
    print_seg(2*node+1, mid+1, r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    decompose(1, 1);
    while (m--) {
        int a, b;
        cin>>a>>b;
        aux1 = a, aux2 = b;
        query(a, b);
    }
    for (int i=1; i<=n; i++) {
        //cout<<nivel[i]<<endl;
        cout<<seg_tree_query(1, 1, cur_pos, pos[i])<<" ";
    }
    cout<<endl;
    //print_seg(1, 1, cur_pos);
    return 0;
}