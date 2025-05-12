#include <bits/stdc++.h>
#define int long long 
#define MAXN (int)(2e5+10)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int vet[30];
    for (int i=0; i<n; i++) cin>>vet[i];
    int dif_min = (int)(1e9);
    for (int i=0; i<(1<<n); i++) {
        int g1 = 0, g2 = 0;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) g1 += vet[j];
            else g2 += vet[j];
        }
        dif_min = min(dif_min, abs(g1-g2));
    }
    cout<<dif_min<<endl;
    return 0;
}