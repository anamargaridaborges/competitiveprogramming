#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int ans = -1;
        for (int i=1; i<2*n-1; i+=2) {
            cout<<"? "<<i<<" "<<i+1<<endl;
            cout.flush();
            int x;
            cin>>x;
            if (x == 1) {
                ans = i;
                break;
            }
        }
        if (ans == -1) {
            cout<<"? "<<2*n-1<<" "<<2*n-2<<endl;
            cout.flush();
            int x;
            cin>>x;
            if (x == 1) {
                ans = 2*n-1;
            }
            else {
                cout<<"? "<<2*n-1<<" "<<2*n-3<<endl;
                cout.flush();
                cin>>x;
                if (x == 1) {
                    ans = 2*n-1;
                }
                else {
                    ans = 2*n;
                }
            }
        }
        cout<<"! "<<ans<<endl;
        cout.flush();
    }
}