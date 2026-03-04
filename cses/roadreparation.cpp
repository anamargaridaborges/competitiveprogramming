#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, pair<int, int>>> arestas;
int comp[100010], tam[100010];

int find (int x) {
    if (x == comp[x]) return x;
    return comp[x] = find(comp[x]);
}

void join (int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (tam[x] >= tam[y]) {
        comp[y] = x;
        tam[x] += tam[y];
    }
    else {
        comp[x] = y;
        tam[y] += tam[x];
    }
}

int32_t main () {
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        arestas.push_back({c, {a, b}});
    }
    for (int i=1; i<=n; i++) comp[i] = i, tam[i] = 1;
    sort(arestas.begin(), arestas.end());
    int ans = 0;
    for (int i=0; i<m; i++) {
        int c = arestas[i].first, a = arestas[i].second.first, b = arestas[i].second.second;
        if (find(a) == find(b)) continue;
        join(a, b);
        ans += c;
    }
    bool check = true;
    for (int i=2; i<=n; i++) {
        if (find(1) != find(i)) check = false;
    }
    if (!check) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
    return 0;
}