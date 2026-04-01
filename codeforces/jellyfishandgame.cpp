#include <iostream>
#define int long long

using namespace std;

int32_t main () {
    int t;
    cin>>t;
    while (t--) {
        int n, m, k;
        cin>>n>>m>>k;
        int max1 = 0, min1 = (int)(1e9 + 10), max2 = 0, min2 = (int)(1e9 + 10);
        int soma1 = 0, soma2 = 0;
        for (int i=1; i<=n; i++) {
            int x;
            cin>>x;
            soma1 += x;
            max1 = max(max1, x);
            min1 = min(min1, x);
        }
        for (int i=1; i<=m; i++) {
            int x;
            cin>>x;
            soma2 += x;
            max2 = max(max2, x);
            min2 = min(min2, x);
        }
        if (k % 2 == 1) {
            if (min1 < max2) {
                soma1 = soma1 - min1 + max2;
            }
        }
        else {
            if (min1 > max2) {
                soma1 = soma1 - max1 + min2;
            }
            else if (min1 > min2 && max1 <= max2) {
                soma1 = soma1 + min2 - min1;
            } 
            else if (min1 > min2 && max1 > max2) {
                soma1 = max(soma1 - max1 + min2, soma1 + min2 + max2 - min1 - max1);
            }
            else if (min1 <= min2 && max1 > max2) {
                soma1 = soma1 - max1 + max2;
            }
        }
        cout<<soma1<<endl;
    }
}