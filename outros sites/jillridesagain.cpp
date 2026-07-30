#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main () {
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        int n;
        cin>>n;
        int l = -1, r = -1, maxi = 0, at = 0, l_at = 1;
        for (int j=1; j<n; j++) {
            int x;
            cin>>x;
            if (at + x >= 0) {
                at = at+x;
            }
            else {
                at = 0;
                l_at = j+1;
            }
            if (at > maxi) {
                maxi = at;
                r = j+1;
                l = l_at;
            }
            else if (at == maxi) {
                if (r-l+1 < (j+1)-l_at+1) {
                    r = j+1;
                    l = l_at;
                }
            }
        }
        if (l != -1 && r != -1) {
            cout<<"The nicest part of route "<<i<<" is between stops "<<l<<" and "<<r<<endl;
        }
        else cout<<"Route "<<i<<" has no nice parts"<<endl;
    }
    return 0;
}