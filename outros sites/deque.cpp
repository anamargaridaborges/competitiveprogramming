#include <bits/stdc++.h>

using namespace std;

int n;
long long int vet[3010], dp[3010][3010][3];

long long int rec (int jogador, int l, int r) {
    if (dp[l][r][jogador] != -1) return dp[l][r][jogador];
    if (l == r) {
        if (jogador == 1) return dp[l][r][jogador] = vet[l];
        else return dp[l][r][jogador] = -vet[l];
    }
    if (jogador == 1) {
        return dp[l][r][jogador] = max(vet[l] + rec(2, l+1, r), vet[r] + rec(2, l, r-1));
    }
    else return dp[l][r][jogador] = min(-vet[l] + rec(1, l+1, r), -vet[r] + rec(1, l, r-1));
}

int main () {
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%lld", &vet[i]);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) dp[i][j][1] = -1, dp[i][j][2] = -1;
    }
    dp[1][n][1] = rec(1, 1, n);
    printf ("%lld\n", dp[1][n][1]);
    return 0;
}