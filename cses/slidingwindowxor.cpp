#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main () {
    int n, k;
    cin>>n>>k;
    int x, a, b, c;
    cin>>x>>a>>b>>c;
    int ini = x;
    int x_at = x;
    int xor_at = x;
    int xor_do_xor = 0;
    for (int i=1; i<k; i++) {
        x_at = ((x_at * a)%c + b)%c;
        xor_at ^= x_at;
    }
    xor_do_xor = xor_at;
    for (int i=k+1; i<=n; i++) {
        xor_at ^= ini;
        ini = ((ini * a)%c + b)%c;
        x_at = ((x_at * a)%c + b)%c;
        xor_at ^= x_at;
        xor_do_xor ^= xor_at;
    }
    cout<<xor_do_xor<<endl;
    return 0;
}