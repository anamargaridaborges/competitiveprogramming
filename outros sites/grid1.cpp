#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;
int dp[MAXN][MAXN];

const int mod = (int)1e9 + 7;

int main () {
    int n, m;
    char mat[MAXN][MAXN];
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) scanf (" %c", &mat[i][j]);
    }
    dp[1][1] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (mat[i][j] == '#') continue;
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
            dp[i][j] = dp[i][j]%mod;
        }
    }
    printf ("%d\n", dp[n][m]);
    return 0;
}