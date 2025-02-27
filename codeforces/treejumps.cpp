#include <bits/stdc++.h>
#define MAXN (int)(3e5+10)

using namespace std;

int dist[MAXN], vis[MAXN];
vector<int> adj[MAXN];
const int inf = 998244353;

void dfs (int x, int d) {
    dist[d]++;
    for (int i=0; i<(int)(adj[x].size()); i++) {
        int at = adj[x][i];
        if (vis[at] != 0) continue;
        vis[at] = d+1;
        dfs(at, d+1);
    }
    return;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);
        for (int i=2; i<=n; i++) {
            int x;
            scanf ("%d", &x);
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        for (int i=0; i<=n; i++) dist[i] = 0, vis[i] = 0;
        vis[1] = 1;
        dfs(1, 0);
        long long int ans = 1;
        for (int i=2; i<=n; i++) {
            if (vis[i] == 1) ans = (ans+1)%inf;
            else {
                ans = (ans+dist[vis[i]-1]-1)%inf;
            }
        }
        for (int i=1; i<=n; i++) adj[i].clear();
        printf ("%lld\n", ans);
    }
    return 0;
}