#include <bits/stdc++.h>
#define MAXN 110
#define MAXV (int)1e5 + 10

using namespace std;

long long int dp[MAXV][MAXN];
// dp[i][j] é o menor peso que eu consigo o valor i usando os j primeiros objetos

const int inf = 2*(int)1e9;

int main () {
    int n, w;
    scanf ("%d%d", &n, &w);
    long long int p[MAXN], v[MAXN];
    long long int soma = 0;
    for (int i=1; i<=n; i++) {
        scanf ("%lld%lld", &p[i], &v[i]);
        soma += v[i];
    }
    for (int i=1; i<=soma; i++) dp[i][0] = inf;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=soma; j++) {
            if (j-v[i]>=0) dp[j][i] = min(dp[j][i-1], dp[j-v[i]][i-1]+p[i]);
            else dp[j][i] = dp[j][i-1];
        }
    }
    long long int ans = 0;
    for (int i=1; i<=soma; i++) {
        if (dp[i][n]<=w) ans = i;
    }
    printf ("%lld\n", ans);
    return 0;
}