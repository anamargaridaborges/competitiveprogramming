#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main () {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int l = 0, r = (n/2) - 1, mid;
        int ans1 = -1;
        while (l <= r) {
            mid = (l+r)/2;
            int l_novo = 1 + mid;
            int r_novo = n - mid;
            if (x1 >= l_novo && x1 <= r_novo && y1 >= l_novo && y1 <= r_novo) {
                ans1 = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        l = 0, r = (n/2) - 1;
        int ans2 = -1;
        while (l <= r) {
            mid = (l+r)/2;
            int l_novo = 1 + mid;
            int r_novo = n - mid;
            if (x2 >= l_novo && x2 <= r_novo && y2 >= l_novo && y2 <= r_novo) {
                ans2 = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout<<abs(ans1-ans2)<<endl;
    }
    return 0;
}