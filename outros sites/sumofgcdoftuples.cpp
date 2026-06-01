#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = (int)(1e9 + 7);
int resp[100010];

int fast_exp (int a, int b) {
    if (b == 0) return 1ll;
    int aux = fast_exp(a, b/2);
    int ans = (aux*aux)%mod;
    if (b%2==1) ans = (ans*a)%mod;
    return ans;
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    int ans = 0;
    for (int i=k; i>=1; i--) {
        int qtd = k/i;
        qtd = fast_exp(qtd, n);
        resp[i] = qtd;
        for (int j=2*i; j<=k; j+=i) {
            resp[i] = (resp[i] + mod - resp[j]) % mod;
        }
        ans = (ans + (resp[i]*i)%mod) % mod;
    }
    cout<<ans<<endl;
    return 0;
}