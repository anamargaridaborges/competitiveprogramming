#include <bits/stdc++.h>
#define int long long 
#define MAXN (int)(2e5+10)

using namespace std;

vector<int> adj[MAXN], inv[MAXN], switches[MAXN];
int comp[MAXN];
int c, ord;
int visitado[MAXN];
int vet[MAXN];
stack<int> ordem;

void dfs (int x) {
    visitado[x] = 1;
    for (int i=0; i<(int)adj[x].size(); i++) {
        int at = adj[x][i];
        if (!visitado[at]) dfs(at);
    }
    ordem.push(x);
}

void scc (int x) {
    comp[x] = c;
    for (int i=0; i<(int)adj[x].size(); i++) {
        int at = adj[x][i];
        if (!comp[at]) scc(at);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>vet[i];
    for (int i=1; i<=m; i++) {
        int k;
        cin>>k;
        for (int j=1; j<=k; j++) {
            int x;
            cin>>x;
            switches[x].push_back(i);
        }
    }
    for (int i=1; i<=n; i++) {
        int a = switches[i][0], b = switches[i][1];
        if (vet[i] == 1) {
            adj[a].push_back(b);
            adj[b].push_back(a);
            adj[a+m].push_back(b+m);
            adj[b+m].push_back(a+m);
        }
        else {
            adj[a].push_back(b+m);
            adj[b+m].push_back(a);
            adj[a+m].push_back(b);
            adj[b].push_back(a+m);
        }
    }
    for (int i=1; i<=2*m; i++) {
        if (!visitado[i]) dfs(i);
    }
    while (!ordem.empty()) {
        int x = ordem.top();
        ordem.pop();
        if (!comp[x]) {
            comp[x] = ++c;
            scc(x);
        }
    }
    bool check = true;
    for (int i=1; i<=m; i++) {
        if (comp[i] == comp[i+m]) check = false;
    }
    if (check) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}