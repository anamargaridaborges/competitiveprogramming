#include <bits/stdc++.h>
#define int long long

using namespace std;

int comp[5010], tam[5010];
vector<pair<int, double>> adj[5010];
int lca[5010][15], tin[5010], tout[5010];
int t;
double max_aresta[5010][15];

int find (int a) {
    if (comp[a] == a) return a;
    else return comp[a] = find(comp[a]);
}

void join (int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (tam[a] >= tam[b]) {
        comp[b] = a;
        tam[a] += tam[b];
    }
    else {
        comp[a] = b;
        tam[b] += tam[a];
    }
}

void dfs (int x, int p) {
    tin[x] = ++t;
    for (auto [u, dist] : adj[x]) {
        if (u == p) continue;
        lca[u][0] = x;
        max_aresta[u][0] = dist;
        dfs(u, x);
    }
    tout[x] = ++t;
}

void calc_lca (int n) {
    for (int j=1; j<15; j++) {
        for (int i=1; i<=n; i++) {
            lca[i][j] = lca[lca[i][j-1]][j-1];
            max_aresta[i][j] = max(max_aresta[i][j-1], max_aresta[lca[i][j-1]][j-1]);
        }
    }
}

bool anc (int a, int d) {
    return (tin[a] < tin[d] && tout[a] > tout[d]);
}

double max_caminho (int a, int d) {
    double maxi = 0;
    int aux = d;
    for (int i=14; i>=0; i--) {
        if (lca[aux][i] == 0) continue;
        if (anc(lca[aux][i], a)) continue;
        maxi = max(maxi, max_aresta[aux][i]);
        aux = lca[aux][i];
    }
    return maxi;
}

double query (int x, int y) {
    if (x == y) return 0;
    int lca_xy;
    if (anc(x, y)) {
        lca_xy = x;
    }
    else if (anc(y, x)) {
        lca_xy = y;
    }
    else {
        int aux = x;
        for (int i=14; i>=0; i--) {
            if (lca[aux][i] == 0) continue;
            if (anc(lca[aux][i], y)) continue;
            aux = lca[aux][i];
        }
        lca_xy = lca[aux][0];
    }
    return max(max_caminho(lca_xy, x), max_caminho(lca_xy, y));
}

int32_t main () {
    int n;
    cin>>n;
    vector<pair<int, int>> vet;
    for (int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        vet.push_back({x, y});
    }
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            double dist = sqrt((vet[i].first - vet[j].first)*(vet[i].first - vet[j].first) + (vet[i].second - vet[j].second)*(vet[i].second - vet[j].second));
            pq.push({dist, i+1, j+1});
        }
    }
    for (int i=1; i<=n; i++) {
        comp[i] = i;
        tam[i] = 1;
    }
    int arestas = 0;
    while (arestas < n-1) {
        auto [dist, x, y] = pq.top();
        pq.pop();
        if (find(x) == find(y)) continue;
        arestas++;
        adj[x].push_back({y, dist});
        adj[y].push_back({x, dist});
        join(x, y);
    }
    // calcular lca e max aresta no caminho
    dfs(1, 0);
    calc_lca(n);
    int q;
    cin>>q;
    while (q--) {
        int x, y;
        cin>>x>>y;
        cout<<fixed<<setprecision(10)<<query(x, y)<<endl;
    }
    return 0;
}