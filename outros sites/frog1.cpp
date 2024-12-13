#include <bits/stdc++.h>
#define MAXN (int)1e5 + 10

using namespace std;

int main () {
    int n;
    scanf ("%d", &n);
    int h[MAXN];
    h[0] = 0;
    for (int i=1; i<=n; i++) scanf ("%d", &h[i]);
    int dp[MAXN];
    dp[1] = 0;
    dp[0] = 0;
    dp[2] = abs(h[1]-h[2]);
    for (int i=3; i<=n; i++) {
        dp[i] = min(dp[i-1]+abs(h[i-1]-h[i]), dp[i-2]+abs(h[i-2]-h[i]));
    }
    printf ("%d\n", dp[n]);
    return 0;
}