#include <bits/stdc++.h>
#define int long long

using namespace std;

int vet[500010];
int n, q;
vector<tuple<int, int, int>> t;

int busca_binaria(int qtd_anterior) {
    int l = 1, r = n, mid;
    int ans = 0;
    while (l <= r) {
        mid = (l+r)/2;
        int anterior_piso = 0;
        int anterior_teto = 0;
        for (auto[a, b, c] : t) {
            if (a <= mid && b < mid) {
                // essa sequencia toda ta antes do mid
                anterior_piso += (b-a+1) * c;
                anterior_teto += (b-a+1) * c;
            }
            else if (a <= mid && b >= mid) {
                // o mid ta no meio da sequencia
                anterior_piso += (mid-a) * c;
                anterior_teto += (mid-a+1) * c;
            }
        }
        if (anterior_piso < qtd_anterior && anterior_teto >= qtd_anterior) {
            return vet[mid];
        }
        else if (anterior_piso >= qtd_anterior) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return vet[mid];
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (int i=1; i<=n; i++) cin>>vet[i];
    while (q--) {
        int k;
        cin>>k;
        int total = 0;
        t.clear();
        for (int i=1; i<=k; i++) {
            int a, b, c;
            cin>>a>>b>>c;
            t.push_back({a, b, c});
            total += (b-a+1) * c; 
        }
        if (total == 1) {
            auto[a, b, c] = t[0];
            cout<<vet[a]<<endl;
            continue;
        }
        if (total % 2 == 1) {
            // achar o valor do meio
            cout<<busca_binaria((total/2) + 1)<<endl;
        }
        else {
            // achar os dois valores do meio
            cout<<fixed<<setprecision(10)<<(double)(busca_binaria(total/2) + busca_binaria(total/2 + 1))/2.0<<endl;
        }
    }
}