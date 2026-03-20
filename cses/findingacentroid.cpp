#include <bits/stdc++.h>

using namespace std;

int tam[200010];
vector<int> adj[200010];
int n;

void dfs (int v, int p) {
    tam[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        tam[v] += tam[u];
    }
}

int centroid (int v, int p) {
    for (int u : adj[v]) {
        if (u == p) continue;
        if (tam[u] * 2 > n) return centroid(u, v);
    }
    return v;
}

int main () {
    cin>>n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout<<centroid(1, 0)<<endl;
    return 0;
}