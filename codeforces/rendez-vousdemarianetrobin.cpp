#include <bits/stdc++.h>
#define MAXN 200010
#define lli long long int

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, m, h;
        scanf ("%d%d%d", &n, &m, &h);
        lli dist_m[MAXN][2], dist_r[MAXN][2];
        int cavalo[MAXN];
        vector<pair<lli, int>> grafo[MAXN];
        for (int i=1; i<=n; i++) {
            dist_m[i][0] = pow(10, 18);
            dist_m[i][1] = dist_m[i][0];
            dist_r[i][0] = dist_m[i][0];
            dist_r[i][1] = dist_m[i][0];
            cavalo[i] = 0;
            grafo[i].clear();
        }
        for (int i=1; i<=h; i++) {
            int x;
            scanf ("%d", &x);
            cavalo[x] = 1;
        }
        while (m--) {
            int u, v;
            lli w;
            scanf ("%d%d%lld", &u, &v, &w);
            grafo[u].push_back({w, v});
            grafo[v].push_back({w, u});
        }
        priority_queue<pair<pair<lli, int>, int>, vector<pair<pair<lli, int>, int>>, greater<pair<pair<lli, int>, int>>> pq;
        if (cavalo[1]==1) {
            dist_m[1][1] = 0;
            dist_m[1][0] = 0;
            pq.push({{0, 1}, 1});
        }
        else {
            dist_m[1][0] = 0;
            pq.push({{0, 1}, 0});
        }
        while (!pq.empty()) {
            lli d = pq.top().first.first;
            int u = pq.top().first.second;
            int id = pq.top().second;
            //printf ("m %d %lld %d\n", u, d, id);
            pq.pop();
            if (d>dist_m[u][id]) continue;
            for (int i=0; i<(int)grafo[u].size(); i++) {
                int v = grafo[u][i].second;
                lli dv = grafo[u][i].first;
                if (id == 0) {
                    if (dist_m[v][0]>dist_m[u][0]+dv) {
                        if (cavalo[v]==1) {
                            dist_m[v][0] = dist_m[u][0]+dv;
                            if (dist_m[v][1]>dist_m[u][0]+dv) dist_m[v][1] = dist_m[u][0]+dv;
                            pq.push({{dist_m[v][0], v}, 1});
                        }
                        else {
                            dist_m[v][0] = dist_m[u][0]+dv;
                            pq.push({{dist_m[v][0], v}, 0});
                        }
                    }
                }
                else {
                    if (dist_m[v][1]>dist_m[u][1]+dv/2) {
                        dist_m[v][1] = dist_m[u][1]+dv/2;
                        pq.push({{dist_m[v][1], v}, 1});
                    }
                }
            }
        }
        if (cavalo[n]==1) {
            dist_r[n][1] = 0;
            pq.push({{0, n}, 1});
        }
        else {
            dist_r[n][0] = 0;
            pq.push({{0, n}, 0});
        }
        while (!pq.empty()) {
            lli d = pq.top().first.first;
            int u = pq.top().first.second;
            int id = pq.top().second;
            //printf ("%d %lld %d\n", u, d, id);
            pq.pop();
            if (d>dist_r[u][id]) continue;
            for (int i=0; i<(int)grafo[u].size(); i++) {
                int v = grafo[u][i].second;
                lli dv = grafo[u][i].first;
                if (id == 0) {
                    if (dist_r[v][0]>dist_r[u][0]+dv) {
                        if (cavalo[v]==1) {
                            dist_r[v][0] = dist_r[u][0]+dv;
                            if (dist_r[v][1]>dist_r[u][0]+dv) dist_r[v][1] = dist_r[u][0]+dv;
                            pq.push({{dist_r[v][0], v}, 1});
                        }
                        else {
                            dist_r[v][0] = dist_r[u][0]+dv;
                            pq.push({{dist_r[v][0], v}, 0});
                        }
                    }
                }
                else {
                    if (dist_r[v][1]>dist_r[u][1]+dv/2) {
                        dist_r[v][1] = dist_r[u][1]+dv/2;
                        pq.push({{dist_r[v][1], v}, 1});
                    }
                }
            }
        }
        lli ans = pow(10, 18);
        for (int i=1; i<=n; i++) {
            //printf ("%lld %lld %lld %lld\n", dist_m[i][0], dist_m[i][1], dist_r[i][0], dist_r[i][1]);
            lli marian = min(dist_m[i][0], dist_m[i][1]);
            lli robin = min(dist_r[i][0], dist_r[i][1]);
            if (marian == pow(10, 18) || robin == pow(10, 18)) continue;
            ans = min(ans, max(marian, robin));
        }
        if (ans == pow(10, 18)) printf ("-1\n");
        else printf ("%lld\n", ans);
    }
    return 0;
}