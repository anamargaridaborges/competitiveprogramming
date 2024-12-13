#include <bits/stdc++.h>
#define MAXN (int)1e5 + 10

using namespace std;

const int inf = (int)1e9 + 10;

int main () {
    int n, k;
    scanf ("%d%d", &n, &k);
    int h[MAXN];
    for (int i=1; i<=n; i++) scanf ("%d", &h[i]);
    int dp[MAXN];
    dp[1] = 0;
    dp[2] = abs(h[1]-h[2]);
    for (int i=3; i<=n; i++) {
        dp[i] = inf;
        for (int j=1; j<=k && i-j>=1; j++) dp[i] = min(dp[i], dp[i-j]+abs(h[i-j]-h[i]));
    }
    printf ("%d\n", dp[n]);
    return 0;
}