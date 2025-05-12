#include <bits/stdc++.h>
#define int long long 
#define MAXN (int)(1e5+10)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        int metade = m/2;
        if (m%2 == 1) metade++;
        int at = 0;
        while (m--) {
            int a, b;
            cin>>a>>b;
            if (a<b) at++;
        }
        if (at>=metade) {
            for (int i=1; i<=n; i++) cout<<i<<' ';
            cout<<endl;
        }
        else {
            for (int i=n; i>=1; i--) cout<<i<<' ';
            cout<<endl;
        }
    }
    return 0;
}