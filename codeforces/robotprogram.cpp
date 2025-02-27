#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, x;
        long long int k;
        scanf ("%d%d%lld", &n, &x, &k);
        int vet[200010];
        for (int i=1; i<=n; i++) {
            char c;
            scanf (" %c", &c);
            if (c == 'L') vet[i] = -1;
            else vet[i] = 1;
        }
        int pos = -1;
        long long int ans;
        if (x == 0) ans = 1;
        else ans = 0;
        for (int i=1; i<=n; i++) {
            x += vet[i];
            if (x == 0) {
                pos=i;
                break;
            }
        }
        if (pos == -1) {
            printf ("%lld\n", ans);
            continue;
        }
        k -= pos;
        ans++;
        x = 0, pos = -1;
        for (int i=1; i<=n; i++) {
            x += vet[i];
            if (x == 0) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            printf ("%lld\n", ans);
            continue;
        }
        printf ("%lld\n", ans+k/pos);
    }
    return 0;
}