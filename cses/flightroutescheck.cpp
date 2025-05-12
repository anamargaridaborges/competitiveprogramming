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
        if (!visitado[adj[x][i]]) dfs(adj[x][i]);
    }
    ordem.push(x);
}

void scc (int x) {
    comp[x] = c;
    for (int i=0; i<(int)inv[x].size(); i++) {
        if (!comp[inv[x][i]]) scc(inv[x][i]);
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
    pair<int, int> resp;
    int ant = 0;
    while (!ordem.empty()) {
        int at = ordem.top();
        ordem.pop();
        if (!comp[at]) {
            if (c==1) {
                resp = {at, ant};
            }
            comp[at] = ++c;
            scc(at);
        }
        ant = at;
    }
    if (c == 1) cout<<"YES"<<endl;
    else {
        cout<<"NO"<<endl;
        cout<<resp.first<<' '<<resp.second<<endl;
    }
    return 0;
}