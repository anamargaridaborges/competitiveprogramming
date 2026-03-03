#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100010];
vector<int> inv[100010];
bool ciclo = false;
int vis[100010];
int cor[100010];
stack<int> topo_sort;
int sai[100010];

void dfs (int v) {
    cor[v] = 1;
    for (int i=0; i<(int)adj[v].size(); i++) {
        int u = adj[v][i];
        if (cor[u] == 1) {
            ciclo = true;
        }
        else if (cor[u] == 0) dfs(u);
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
        inv[b].push_back(a);
        sai[a]++;
    }
    for (int i=1; i<=n; i++) {
        if (!cor[i]) dfs(i);
    }
    if (ciclo) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    queue<int> zero;
    for (int i=1; i<=n; i++) {
        if (sai[i] == 0)  zero.push(i);
    }
    while (!zero.empty()) {
        int v = zero.front();
        zero.pop();
        topo_sort.push(v);
        for (int i=0; i<(int)inv[v].size(); i++) {
            sai[inv[v][i]]--;
            if (sai[inv[v][i]] == 0) zero.push(inv[v][i]);
        }
    }
    while (!topo_sort.empty()) {
        int v = topo_sort.top();
        topo_sort.pop();
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}