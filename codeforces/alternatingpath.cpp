#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200010];
int comp[200010];
int c;
int nivel_par, nivel_impar;
int visitado[200010];
int ciclo_impar[200010];
int nivel[200010];

bool dfs (int x) {
    bool check = false;
    for (int v : adj[x]) {
        if (comp[v] == c) {
            // ciclo
            if (abs(nivel[x]-nivel[v])%2 == 0) {
                //ciclo impar
                check = true;
            }
        }
        else {
            comp[v] = c;
            nivel[v] = nivel[x] + 1;
            check = check | dfs(v);
        }
    }
    return check;
}

void calc_nivel (int x, int nivel) {
    if (nivel % 2 == 0) nivel_par++;
    else nivel_impar++;
    for (int v : adj[x]) {
        if (visitado[v]) continue;
        visitado[v] = 1;
        calc_nivel(v, nivel+1);
    }
    return;
}

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        if (m == 0) {
            cout<<n<<endl;
            continue;
        }
        for (int i=1; i<=n; i++) {
            adj[i].clear();
            comp[i] = 0;
            visitado[i] = 0;
            ciclo_impar[i] = 0;
            nivel[i] = 0;
        }
        c = 0, nivel_impar = 0, nivel_par = 0;
        for (int i=1; i<=m; i++) {
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i=1; i<=n; i++) {
            if (comp[i] == 0) {
                comp[i] = ++c;
                nivel[i] = 1;
                ciclo_impar[c] = dfs(i);
            }
        }
        int ans = 0;
        for (int i=1; i<=n; i++) {
            if (ciclo_impar[comp[i]]) continue;
            if (visitado[i]) continue;
            visitado[i] = 1;
            nivel_impar = 0, nivel_par = 0;
            calc_nivel(i, 0);
            ans += max(nivel_impar, nivel_par);
        }
        cout<<ans<<endl;
    }
    return 0;
}