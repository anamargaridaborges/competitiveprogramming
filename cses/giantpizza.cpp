#include <bits/stdc++.h>
#define int long long 
#define MAXN (int)(2e5+10)

using namespace std;

vector<int> adj[MAXN], inv[MAXN], comprimido[MAXN];
int comp[MAXN];
int c, ord;
int visitado[MAXN];
stack<int> ordem;
int ans[MAXN];

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
    for (int i=0; i<(int)inv[x].size(); i++) {
        int at = inv[x][i];
        if (!comp[at]) scc(at);
    }
}

void dfs_comprimido (int x) {
    visitado[x] = 1;
    for (int i=0; i<(int)comprimido[x].size(); i++) {
        int at = comprimido[x][i];
        if (!visitado[at]) dfs_comprimido(at);
    }
    ans[x] = ++ord;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        int x1, x2;
        char c1, c2;
        cin>>c1>>x1>>c2>>x2;
        int f1, d1, f2, d2;
        if (c1 == '+') {
            f1 = x1+m;
            d2 = x1;
        }
        else {
            f1 = x1;
            d2 = x1+m;
        }
        if (c2 == '+') {
            d1 = x2;
            f2 = x2+m;
        }
        else {
            d1 = x2+m;
            f2 = x2;
        }
        adj[f1].push_back(d1);
        adj[f2].push_back(d2);
        inv[d1].push_back(f1);
        inv[d2].push_back(f2);
    }
    for (int i=1; i<=2*m; i++) {
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
    bool check = true;
    for (int i=1; i<=m; i++) {
        if (comp[i] == comp[i+m]) check = false;
    }
    if (!check) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for (int i=1; i<=2*m; i++) {
        for (int j=0; j<(int)adj[i].size(); j++) {
            int at = adj[i][j];
            if (comp[i] == comp[at]) continue;
            comprimido[comp[i]].push_back(comp[at]);
        }
        sort(comprimido[i].begin(), comprimido[i].end() );
        comprimido[i].erase(unique(comprimido[i].begin(), comprimido[i].end()), comprimido[i].end());
    }
    for (int i=1; i<=c; i++) {
        visitado[i] = 0;
    }
    for (int i=1; i<=c; i++) {
        if (!visitado[i]) dfs_comprimido(i);
    }
    for (int i=1; i<=m; i++) {
        if (ans[comp[i]]>ans[comp[i+m]]) cout<<"- ";
        else cout<<"+ ";
    }
    cout<<endl;
    return 0; 
}