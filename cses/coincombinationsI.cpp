#include <bits/stdc++.h>
#define MAXN 110
#define MAXV (int)1e6 + 10

using namespace std;

const int mod = (int)1e9 + 7;

int main () {
    int n, x;
    scanf ("%d%d", &n, &x);
    int moedas[MAXN], dp[MAXV];
    for (int i=1; i<=n; i++) scanf ("%d", &moedas[i]);
    sort (moedas+1, moedas+n+1);
    dp[0] = 1;
    for (int i=1; i<=x; i++) {
        dp[i] = 0;
        for (int j=1; j<=n; j++) {
            if (moedas[j]>i) break;
            dp[i] += dp[i-moedas[j]];
            dp[i] = dp[i]%mod;
        }
    }
    printf ("%d\n", dp[x]);
    return 0;
}