#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100010];
int cor[100010];
bool ciclo = false;
int ini_ciclo = -1, fim_ciclo = -1;
stack<int> ans;
int pai[100010];

void dfs (int v) {
    cor[v] = 1;
    if (ciclo) return;
    for (int i=0; i<(int)adj[v].size(); i++) {
        int u = adj[v][i];
        if (cor[u] == 1 && !ciclo) {
            ciclo = true;
            int aux = v;
            ans.push(u);
            while (aux != u) {
                ans.push(aux);
                aux = pai[aux];
            }
            ans.push(u);
            return;
        }
        else if (cor[u] == 0) {
            pai[u] = v;
            dfs(u);
        }
        if (ciclo) return;
    }
    cor[v] = 2;
}

int main () {
    int n, m;
    cin>>n>>m;
    while (m--) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        if (!cor[i]) dfs(i);
    }
    if (!ciclo) cout<<"IMPOSSIBLE"<<endl;
    else {
        cout<<(int)ans.size()<<endl;
        while (!ans.empty()) {
            int v = ans.top();
            cout<<v<<" ";
            ans.pop();
        }
        cout<<endl;
    }
    return 0;
}