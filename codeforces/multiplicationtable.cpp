#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main () {
    int n, m, k;
    cin>>n>>m>>k;
    int l = 1, r = n*m, mid;
    int ans = -1;
    while (l <= r) {
        mid = (l+r)/2;
        int menores = 0, menores_iguais = 0;
        for (int i=1; i<=n; i++) {
            menores_iguais += min(m, mid/i);
            menores += min(m, (mid % i == 0 ? (mid-1)/i : mid/i));
        }
        if (menores < k && menores_iguais >= k) {
            ans = mid;
            break;
        }
        else if (menores_iguais < k) {
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<ans<<endl;
}