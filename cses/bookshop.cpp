#include <bits/stdc++.h>
#define MAXN 1010
#define MAXX 100010
 
using namespace std;
 
int dp[MAXN][MAXX];
 
int main () {
    int n, x;
    int p[MAXN], v[MAXN];
    scanf ("%d%d", &n, &x);
    for (int i=1; i<=n; i++) scanf ("%d", &p[i]);
    for (int i=1; i<=n; i++) scanf ("%d", &v[i]);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=x; j++) {
            if (p[i]>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i]]+v[i]);
        }
    }
    printf ("%d\n", dp[n][x]);
    return 0;
}