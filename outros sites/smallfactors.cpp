#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    while (true) {
        int m;
        cin>>m;
        if (m == 0) return 0;
        int ans = (int)(1e18);
        for (int i=1; i<=pow(2, 31); i = i*3) {
            int l = 0, r = 31, mid;
            int aux = -1;
            while (l <= r) {
                mid = (l+r)/2;
                if (pow(2, mid) * i >= m) {
                    aux = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if (i*pow(2, aux) - m < ans - m) {
                ans = i*pow(2, aux);
            }
            if (i >= m) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}