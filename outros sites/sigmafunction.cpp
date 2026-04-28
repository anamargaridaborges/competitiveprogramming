#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main () {
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        int n;
        cin>>n;
        int impares = 0;
        impares += sqrt(n);
        impares += sqrt(n/2);
        cout<<"Case "<<i<<": "<<n-impares<<"\n";
    }
    return 0;
}