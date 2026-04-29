#include <bits/stdc++.h>
#define int long long

using namespace std;

int pot5[50];

int32_t main () {
    pot5[0] = 1;
    for (int i=1; i<50; i++) pot5[i] = pot5[i-1] * 5;
    int t;
    cin>>t;
    for (int j=1; j<=t; j++) {
        int q;
        cin>>q;
        int l = 1, r = (int)1e18, mid;
        int resp = -1;
        while (l <= r) {
            mid = (l+r)/2;
            int ans = 0;
            int aux = 0, aux_qtd = 0;
            for (int i=27; i>=1; i--) {
                if (pot5[i] < 0 || pot5[i] > mid) continue;
                aux = (mid/pot5[i]) - aux_qtd;
                aux_qtd += aux;
                ans += aux*i;
            }
            if (ans == q) {
                resp = mid;
                r = mid - 1;
            }
            else if (ans > q) r = mid - 1;
            else if (ans < q) l = mid + 1;
        }
        cout<<"Case "<<j<<": ";
        if (resp == -1) cout<<"impossible"<<endl;
        else cout<<resp<<endl;
    }
    return 0;
}