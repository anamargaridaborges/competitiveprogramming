#include <bits/stdc++.h>

using namespace std;

int primo[1000010], fat_c[1000010];
vector<int> contido;

void crivo() {
    for (int i=2; i<=1000000; i++) {
        if (primo[i]) continue;
        primo[i] = i;
        for (int j=2*i; j<=1000000; j+=i) primo[j] = i;
    }
}

int comb(int pos, vector<int> & fatores, int m) {
    if (pos == (int)fatores.size()) {
        int aux = 1;
        int cont = 0;
        for (int i=0; i<(int)contido.size(); i++) {
            if (contido[i] == 1) {
                aux *= fatores[i];
                cont++;
            }
        }
        if (cont == 0) return 0;
        if (cont%2 == 1) return m/aux;
        else return -m/aux;
    }
    int ans = 0;
    contido.push_back(1);
    ans += comb(pos+1, fatores, m);
    contido.pop_back();
    contido.push_back(0);
    ans += comb(pos+1, fatores, m);
    contido.pop_back();
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    crivo();
    int t;
    cin>>t;
    while (t--) {
        int x, p, k;
        cin>>x>>p>>k;
        vector<int> fatores;
        while (p != 1) {
            int at = primo[p];
            while (p % at == 0) p = p/at;
            fatores.push_back(at);
        }
        int l = x+1, r = (int)(1e9), mid;
        int ans = -1;
        int ans_baixo = x - comb(0, fatores, x);
        while (l <= r) {
            mid = (l+r)/2;
            int ans_alto = mid - comb(0, fatores, mid);
            if (ans_alto - ans_baixo >= k) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout<<ans<<endl;
    }
}