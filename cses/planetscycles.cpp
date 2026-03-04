#include <bits/stdc++.h>

using namespace std;

int prox[200010];
int ans[200010];
int vis[200010];
int pai[200010];

void dfs (int v) {
    if (ans[v] != 0) return;
    vis[v] = 1;
    int u = prox[v];
    pai[u] = v;
    if (vis[u] == 1) {
        // achei ciclo, calculo tamanho
        int aux = v;
        int aux2 = 1;
        while (aux != u) {
            aux2++;
            aux = pai[aux];
        }
        aux = v;
        while (aux != u) {
            ans[aux] = aux2;
            aux = pai[aux];
        }
        ans[u] = aux2;
    }
    else if (vis[u] == 2) {
        ans[v] = ans[u] + 1;
    }
    else {
        dfs(u);
        if (ans[v] == 0) ans[v] = ans[u] + 1;
    }
    vis[v] = 2;
}

int main () {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) cin>>prox[i];
    for (int i=1; i<=n; i++) {
        if (!vis[i]) dfs(i);
    }
    for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}