#include <bits/stdc++.h>
#define int long long

using namespace std;

int vet[1010];

int exp (int a, int b, int mod) {
    if (b == 0) return 1ll;
    int aux = exp(a, b/2, mod);
    int ans = (aux*aux)%mod;
    if (b % 2 == 1) ans = (ans*a)%mod;
    return ans;
}

int32_t main() {
    int t;
    cin>>t;
    for (int j=1; j<=t; j++) {
        int n, k, mod;
        cin>>n>>k>>mod;
        for (int i=1; i<=n; i++) cin>>vet[i];
        int mult = (exp(n, k-1, mod) * k)%mod;
        int ans = 0;
        for (int i=1; i<=n; i++) {
            ans = (ans + (vet[i]*mult)%mod)%mod;
        }
        cout<<"Case "<<j<<": "<<ans<<endl;
    }
    return 0;
}