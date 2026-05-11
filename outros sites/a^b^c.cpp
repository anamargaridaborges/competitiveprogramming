#include <bits/stdc++.h>
#define int long long

using namespace std;

int fast_exp (int a, int b, int mod) {
    if (b == 0) return 1ll;
    int aux = fast_exp(a, b/2, mod);
    int resp = (aux*aux)%mod;
    if (b%2 == 1) resp = (resp*a)%mod;
    return resp;
}

int32_t main () {
    int a, b, c;
    cin>>a>>b>>c;
    int x = fast_exp(b, c, 4);
    if (x == 0) x = 4;
    cout<<fast_exp(a, x, 10)<<endl;
    return 0;
}