#include <bits/stdc++.h>
#define int long long 
#define MAXN (int)(1e5+10)

using namespace std;
int vet[MAXN];
vector<int> adj[MAXN], inv[MAXN], comprimido[MAXN];
int comp[MAXN], val_comp[MAXN];
int dp[MAXN];
int visitado[MAXN];
stack<int> ordem;
int c;

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
    val_comp[c] += vet[x];
    for (int i=0; i<(int)inv[x].size(); i++) {
        int at = inv[x][i];
        if (!comp[at]) scc(at);
    }
}

int percorrer_comprimido (int x) {
    if (dp[x] != -1) return dp[x];
    dp[x] = val_comp[x];
    int at = 0;
    for (int i=0; i<(int)comprimido[x].size(); i++) {
        at = max(at, percorrer_comprimido(comprimido[x][i]));
    }
    return dp[x] += at;
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>vet[i];
    while (m--) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        inv[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!visitado[i]) dfs(i);
    }
    while (!ordem.empty()) {
        int at = ordem.top();
        ordem.pop();
        if (!comp[at]) {
            comp[at] = ++c;
            scc(at);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<(int)adj[i].size(); j++) {
            int at = adj[i][j];
            if (comp[at] == comp[i]) continue;
            comprimido[comp[i]].push_back(comp[at]);
        }
    }
    for (int i=1; i<=c; i++) {
        sort(comprimido[i].begin(), comprimido[i].end());
        comprimido[i].erase(unique(comprimido[i].begin(), comprimido[i].end()), comprimido[i].end());
    }
    for (int i=1; i<=c; i++) dp[i] = -1;
    for (int i=1; i<=c; i++) {
        if (dp[i] == -1) percorrer_comprimido(i);
    }
    int ans = 0;
    for (int i=1; i<=c; i++) ans = max(ans, dp[i]);
    cout<<ans<<endl;
    return 0;
}