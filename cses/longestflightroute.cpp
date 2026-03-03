#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100010];
int pai[100010];
int maxi[100010];
int vis[100010];
int n, m;

void dfs (int v) {
    if (vis[v] == 1) return;
    vis[v] = 1;
    if (v == n) return;
    for (int i=0; i<(int)adj[v].size(); i++) {
        int u = adj[v][i];
        dfs(u);
        if (maxi[u] == 0) continue;
        if (maxi[u] + 1 > maxi[v]) {
            pai[v] = u;
            maxi[v] = maxi[u] + 1;
        }
    }
}

int main () {
    cin>>n>>m;
    while (m--) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    maxi[n] = 1;
    dfs(1);
    if (!vis[n]) cout<<"IMPOSSIBLE"<<endl;
    else {
        cout<<maxi[1]<<endl;
        int aux = 1;
        while (aux != n) {
            cout<<aux<<" ";
            aux = pai[aux];
        }
        cout<<n<<endl;
    }
    return 0;
}