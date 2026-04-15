#include <bits/stdc++.h>
#define int long long

using namespace std;

int vet[200010];

int32_t main () {
    int n, k;
    cin>>n>>k;
    for (int i=1; i<=n; i++) cin>>vet[i];
    sort(vet+1, vet+n+1);
    int l = 1, r = (int)(2e9), mid;
    int ans = -1;
    while (l<=r) {
        mid = (l+r)/2;
        // testo pra ver se é possivel conseguir a mediana mid
        int at = 0;
        for (int i=(n/2) + 1; i<=n; i++) {
            if (vet[i] < mid) at += mid - vet[i];
        }
        if (at <= k) {
            // deu certo
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<ans<<endl;
}