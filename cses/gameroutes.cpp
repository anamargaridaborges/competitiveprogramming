#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = (int)(1e9 + 7);

int n, m;
vector<int> adj[100010];
int qtd[100010];
int vis[100010];

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    if (v == n) return;
    for (int i=0; i<(int)adj[v].size(); i++) {
        int u = adj[v][i];
        dfs(u);
        qtd[v] = (qtd[v] + qtd[u]) % mod;
    }
}

int32_t main () {
    cin>>n>>m;
    while (m--) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    qtd[n] = 1;
    dfs(1);
    cout<<qtd[1]<<endl;
    return 0;
}