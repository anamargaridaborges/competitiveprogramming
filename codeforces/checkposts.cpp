#include <bits/stdc++.h>
#define MAXN (int)(1e5+10)
#define int long long

using namespace std;

vector<int> adj[MAXN], inv[MAXN];
stack<int> ordem;
int visitado[MAXN];
int comp[MAXN];
int c;
const int mod = (int)(1e9+7);
int min_comp[MAXN];
int qtd[MAXN];

void dfs(int x) {
    visitado[x] = 1;
    for (int i=0; i<(int)adj[x].size(); i++) {
        int at = adj[x][i];
        if (!visitado[at]) dfs(at);
    }
    ordem.push(x);
    return;
}

void atribuir (int x) {
    visitado[x] = 1;
    for (int i=0; i<(int)inv[x].size(); i++) {
        int at = inv[x][i];
        if (!visitado[at]) {
            comp[at] = c;
            atribuir(at);
        }
    }
    return;
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int vet[MAXN];
    for (int i=1; i<=n; i++) cin>>vet[i];
    int m;
    cin>>m;
    while (m--) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        inv[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        if (!visitado[i]) dfs(i);
    }
    for (int i=1; i<=n; i++) {
        visitado[i] = 0;
    }
    while (!ordem.empty()) {
        int at = ordem.top();
        ordem.pop();
        if (!visitado[at] && !comp[at]) {
            comp[at] = ++c;
            atribuir(at);
        }
    }
    for (int i=1; i<=n; i++) min_comp[i] = (int)(1e9+10);
    for (int i=1; i<=n; i++) {
        min_comp[comp[i]] = min(min_comp[comp[i]], vet[i]);
        //cout<<comp[i]<<' ';
    }
    int ans = 0;
    for (int i=1; i<=c; i++) {
        ans += min_comp[i];
        //cout<<min_comp[i]<<' ';
    }
    for (int i=1; i<=n; i++) {
        if (vet[i] == min_comp[comp[i]]) {
            qtd[comp[i]]++;
        }
    }
    int ans_2 = 1;
    for (int i=1; i<=c; i++) {
        ans_2 = (ans_2*qtd[i])%mod;
    }
    cout<<ans<<' '<<ans_2<<endl;
    return 0;
}