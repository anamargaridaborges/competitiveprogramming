#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> adj[200010];
int tin[200010], tout[200010];
int t;
int up[200010][20];
int nivel[200010];

void dfs (int v, int p) {
    tin[v] = ++t;
    up[v][0] = p;
    for (auto u : adj[v]) {
        if (u == p) continue;
        nivel[u] = nivel[v] + 1;
        dfs(u, v);
    }
    tout[v] = ++t;
}

bool anc (int desc, int ances) {
    return (tin[ances] <= tin[desc] && tout[ances] >= tout[desc]);
}

void calc_up (int v, int p) {
    for (int i=1; i<=19; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (auto u : adj[v]) {
        if (u == p) continue;
        calc_up(u, v);
    }
}

int lca (int a, int b) {
    if (a == b) return a;
    if (anc(a, b)) return b;
    if (anc(b, a)) return a;

    int at = a;

    for (int i=19; i>=0; i--) {
        if (up[at][i] == 0) continue;
        if (anc(b, up[at][i])) continue;
        at = up[at][i];
    }

    return up[at][0];

}

int32_t main() {
    int n, q;
    cin>>n>>q;
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    nivel[1] = 1;
    dfs(1, 0);
    calc_up(1, 0);
    while (q--) {
        int a, b;
        cin>>a>>b;
        int aux = lca(a, b);
        cout<<nivel[a]+nivel[b]-2*nivel[aux]<<endl;
    }
    return 0;
}