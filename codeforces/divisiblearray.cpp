#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        if (n % 2 == 1) {
            for (int i=1; i<=n; i++) cout<<i<<" ";
            cout<<endl;
        }
        else {
            for (int i=1; i<=n; i++) cout<<2*i<<" ";
            cout<<endl;
        }
    }
    return 0;
}