#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = (int)(1e9+7);

int fatorial[2000010];
vector<pair<int, int>> traps;
int sub[1010];

int exp (int a, int b) {
    if (b == 0) return 1ll;
    if (b == 1) return a;

    int aux = exp(a, b/2);

    int resp = (aux * aux) % mod;

    if (b%2 == 1) resp = (resp * a) % mod;

    return resp;
}

int32_t main () {
    int n, m;
    cin>>n>>m;
    fatorial[0] = 1;
    fatorial[1] = 1;
    for (int i=2; i<=2*n; i++) fatorial[i] = (fatorial[i-1]*i)%mod;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin>>x>>y;
        traps.push_back({x, y});
    }
    sort(traps.begin(), traps.end());
    int caminhos_ruins = 0;
    for (int i=0; i<m; i++) {
        int x = traps[i].first, y = traps[i].second;
        int ate_trap = fatorial[x+y-2];
        int den_ate_trap = (fatorial[x-1] * fatorial[y-1]) % mod;
        den_ate_trap = exp(den_ate_trap, mod - 2);
        ate_trap = (ate_trap * den_ate_trap) % mod;
        ate_trap = (ate_trap - sub[i] + mod) % mod;
        int ate_fim = fatorial[2*n - x - y];
        int den_ate_fim = (fatorial[n-x] * fatorial[n-y]) % mod;
        den_ate_fim = exp(den_ate_fim, mod - 2);
        ate_fim = (ate_fim * den_ate_fim) % mod;
        caminhos_ruins = (caminhos_ruins + (ate_trap * ate_fim) % mod) % mod;
        for (int j=i+1; j<m; j++) {
            int a = traps[j].first, b = traps[j].second;
            if (a < x || b < y) continue;
            int meio = fatorial[a-x+b-y];
            int den_meio = (fatorial[a-x] * fatorial[b-y]) % mod;
            den_meio = exp(den_meio, mod - 2);
            meio = (meio * den_meio) % mod;
            //
            meio = (ate_trap * meio) % mod;
            sub[j] = (sub[j] + meio) % mod;
        }
    }
    int caminhos_totais = fatorial[2*n - 2];
    int den_caminhos_totais = (fatorial[n-1] * fatorial[n-1]) % mod;
    den_caminhos_totais = exp(den_caminhos_totais, mod - 2);
    caminhos_totais = (caminhos_totais * den_caminhos_totais) % mod;
    cout<<(caminhos_totais - caminhos_ruins + mod)%mod<<endl;
    return 0;
}