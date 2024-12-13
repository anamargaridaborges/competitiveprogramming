#include <bits/stdc++.h>
#define MAXN 110
#define MAXW (int)1e5 + 10

using namespace std;

int p[MAXN];
long long int v[MAXN];
long long int dp[MAXW][MAXN];

int main () {
    int n, w;
    scanf ("%d%d", &n, &w);
    for (int i=1; i<=n; i++) scanf ("%d%lld", &p[i], &v[i]);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=w; j++) {
            if (p[i]>j) dp[j][i] = dp[j][i-1];
            else dp[j][i] = max(dp[j][i-1], dp[j-p[i]][i-1]+v[i]);
        }
    }
    printf ("%lld\n", dp[w][n]);
    return 0;
}