#include <bits/stdc++.h>
#define MAXN 50010

using namespace std;

map<int, vector<int>> id;
int n;
int nivel[MAXN], pai[MAXN][20], tin[MAXN], tout[MAXN];
int t;
vector<int> grafo[MAXN];

bool ancestral (int d, int a) {
    if (tin[d]>=tin[a] && tout[a]>=tout[d]) return true;
    else return false;
}

void dfs (int x) {
    tin[x] = ++t;
    for (int i=0; i<(int)grafo[x].size(); i++) {
        int adj = grafo[x][i];
        if (nivel[adj] == 0) {
            nivel[adj] = nivel[x]+1;
            pai[adj][0] = x;
            dfs(adj);
        }
    }
    tout[x] = ++t;
    return;
}

int lca (int u, int v) {
    if (u==v) return u;
    if (ancestral(u, v)) return v;
    if (ancestral(v, u)) return u;
    if (nivel[v]>nivel[u]) swap(v, u);
    for (int i=19; i>=0; i--) {
        if (!ancestral(v, pai[u][i])) u = pai[u][i];
    }
    return pai[u][0];
}

int main () {
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) {
        int x;
        scanf ("%d", &x);
        id[x].push_back(i);
    }
    for (int i=1; i<n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    nivel[1]=1;
    pai[1][0]=1;
    dfs(1);
    for (int i=1; i<20; i++) {
        for (int j=1; j<=n; j++) {
            pai[j][i] = pai[pai[j][i-1]][i-1];
        }
    }
    long long int ans = 0;
    for (int i=1; i<=n/2; i++) {
        int u = id[i][0], v = id[i][1];
        int x = lca(u, v);
        ans += nivel[u]+nivel[v]-2*nivel[x];
    }
    printf ("%lld\n", ans);
    return 0;
}