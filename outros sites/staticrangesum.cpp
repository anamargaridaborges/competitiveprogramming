#include <bits/stdc++.h>
#define int long long

using namespace std;

int vet[500010], pref[500010];

int32_t main() {
    int n, q;
    cin>>n>>q;
    for (int i=0; i<n; i++) cin>>vet[i];
    pref[0] = vet[0];
    for (int i=1; i<n; i++) pref[i] = pref[i-1] + vet[i];
    while (q--) {
        int l, r;
        cin>>l>>r;
        int soma = pref[r-1];
        if (l != 0) soma -= pref[l-1];
        cout<<soma<<endl;
    }
    return 0;
}