#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> adj[200010];
int sum_subtree[200010], sum_fora[200010], tam[200010], sum_perto[200010];

void dfs (int x, int p) {
    tam[x] = 1;
    for (auto u : adj[x]) {
        if (u == p) continue;
        dfs(u, x);
        tam[x] += tam[u];
        sum_subtree[x] += sum_subtree[u] + tam[u];
    }
}

void dfs2 (int x, int p) {
    if (x!=1) {
        sum_fora[x] = sum_fora[p] + sum_subtree[p] - (sum_subtree[x] + tam[x]) + tam[1] - tam[p] + (tam[p]-tam[x]);
    }
    for (auto u : adj[x]) {
        if (u == p) continue;
        dfs2(u, x);
    }
}

int32_t main () {
    int n;
    cin>>n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 0);
    for (int i=1; i<=n; i++) cout<<sum_subtree[i]+sum_fora[i]<<" ";
    cout<<endl;
    return 0;
}