#include <bits/stdc++.h>
#define MAXN (int)1e5+10

using namespace std;

vector<pair<int, long long int>> adj[MAXN];
long long int dist[MAXN];
int up[MAXN][30];
int tin[MAXN], tout[MAXN];
int nivel[MAXN];
int t;

void dfs (int x) {
    tin[x] = ++t;
    for (int i=0; i<(int)adj[x].size(); i++) {
        int v = adj[x][i].first;
        long long int d = adj[x][i].second;
        if (dist[v] == 0 && v!=0) {
            dist[v] = dist[x]+d;
            up[v][0] = x;
            nivel[v] = nivel[x]+1;
            dfs(v);
        } 
    }
    tout[x] = ++t;
}

bool anc (int a, int d) {
    if (tin[d]>=tin[a] && tout[d]<=tout[a]) return true;
    else return false;
}

void solve (int a, int b) {
    if (anc(a, b) == true) {
        printf ("%lld ", dist[b]-dist[a]);
        return;
    }
    if (anc(b, a) == true) {
        printf ("%lld ", dist[a]-dist[b]);
        return;
    }
    if (nivel[a]<nivel[b]) swap(a, b);
    int u = a;
    for (int i=29; i>=0; i--) {
        if (up[u][i] == -1) continue;
        if (anc(up[u][i], b) == false) u = up[u][i];
    }
    printf ("%lld ", dist[a]+dist[b]-2*dist[up[u][0]]);
}

int main () {
    while (true) {
        int n;
        scanf ("%d", &n);
        if (n == 0) break;
        for (int i=1; i<n; i++) {
            int a;
            long long int d;
            scanf ("%d%lld", &a, &d);
            adj[i].push_back({a, d});
            adj[a].push_back({i, d});
        }
        up[0][0] = -1;
        dist[0] = 0;
        nivel[0] = 0;
        t = 0;
        for (int i=1; i<n; i++) dist[i] = 0;
        dfs(0);
        for (int i=1; i<30; i++) {
            for (int j=0; j<n; j++) {
                if (up[j][i-1] == -1) {
                    up[j][i] = -1;
                    continue;
                }
                up[j][i] = up[up[j][i-1]][i-1];
            }
        }
        int q;
        scanf ("%d", &q);
        while (q--) {
            int a, b;
            scanf ("%d%d", &a, &b);
            solve(a, b);
        }
        printf ("\n");
        for (int i=0; i<n; i++) adj[i].clear();
    }
    return 0;
}