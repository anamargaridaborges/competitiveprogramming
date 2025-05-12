#include <bits/stdc++.h>
#define int long long 
#define MAXN (int)(1e5+10)

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

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
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
        int x = ordem.top();
        ordem.pop();
        if (!comp[x]) {
            comp[x] = ++c;
            scc(x);
        }
    }
    cout<<c<<endl;
    for (int i=1; i<=n; i++) cout<<comp[i]<<' ';
    cout<<endl;
    return 0;
}