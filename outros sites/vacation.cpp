#include <bits/stdc++.h>
#define MAXN (int)1e5 + 10

using namespace std;

int dp[MAXN][3];

int main () {
    int n;
    scanf ("%d", &n);
    int vet[MAXN][3];
    for (int i=1; i<=n; i++) scanf ("%d%d%d", &vet[i][0], &vet[i][1], &vet[i][2]);
    for (int i=1; i<=n; i++) {
        dp[i][0] = max(dp[i-1][1]+vet[i][0], dp[i-1][2]+vet[i][0]);
        dp[i][1] = max(dp[i-1][0]+vet[i][1], dp[i-1][2]+vet[i][1]);
        dp[i][2] = max(dp[i-1][1]+vet[i][2], dp[i-1][0]+vet[i][2]);
    }
    printf ("%d\n", max(max(dp[n][0], dp[n][1]), dp[n][2]));
    return 0;
}