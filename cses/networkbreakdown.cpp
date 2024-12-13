#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int comp[MAXN], tam[MAXN];
vector<pair<int, int>> conexoes, removidos;
map<pair<int, int>, int> tirados;

int find (int x) {
    if (x == comp[x]) return x;
    return comp[x] = find(comp[x]);
}

int join (int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y) return 0;
    if (tam[x]>tam[y]) {
        comp[y] = x;
        tam[x] += tam[y];
    }
    else {
        comp[x] = y;
        tam[y] += tam[x];
    }
    return 1;
}

int main () {
    int n, m, k;
    scanf ("%d%d%d", &n, &m, &k);
    for (int i=1; i<=n; i++) {
        comp[i] = i;
        tam[i] = 1;
    }
    for (int i=0; i<m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        conexoes.push_back({a, b});
    }
    int componentes = n;
    for (int i=0; i<k; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        removidos.push_back({a, b});
        tirados[{a, b}] = tirados[{b, a}] = 1;
    }
    for (int i=0; i<m; i++) {
        int a = conexoes[i].first;
        int b = conexoes[i].second;
        if (tirados.find({a, b}) != tirados.end()) continue;
        componentes -= join(a, b);
    }
    vector<int> ans;
    for (int i=k-1; i>=0; i--) {
        ans.push_back(componentes);
        int a = removidos[i].first;
        int b = removidos[i].second;
        componentes -= join(a, b);
    }
    for (int i=(int)ans.size()-1; i>=0; i--) printf ("%d ", ans[i]);
    printf ("\n");
    return 0;
}