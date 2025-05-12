#include <bits/stdc++.h>
#define int long long 
#define MAXN (int)(1e5+10)

using namespace std;

vector<int> adj[MAXN], inv[MAXN];
int comp[MAXN];
int c;
int visitado[MAXN];
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
    for (int i=0; i<(int)inv[x].size(); i++) {
        int at = inv[x][i];
        if (!comp[at]) scc(at);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
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
    if (c == 1) cout<<'S'<<endl;
    else cout<<'N'<<endl;
    return 0;
}