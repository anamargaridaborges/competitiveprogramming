#include <bits/stdc++.h>
#define MAXN (int)1e6 + 10
#define MAXM 110

using namespace std;

int main () {
    int x;
    int dp[MAXN], moedas[MAXM];
    int n;
    scanf ("%d%d", &n, &x);
    for (int i=1; i<=n; i++) scanf ("%d", &moedas[i]);
    sort (moedas+1, moedas+n+1);
    dp[0] = 0;
    for (int i=1; i<=x; i++) {
        int ans_atual = -1;
        for (int j=1; j<=n; j++) {
            if (moedas[j]>i) break;
            if (dp[i-moedas[j]] == -1) continue;
            if (ans_atual == -1) ans_atual = dp[i-moedas[j]]+1;
            else ans_atual = min(dp[i-moedas[j]]+1, ans_atual);
        }
        dp[i] = ans_atual;
    }
    printf ("%d\n", dp[x]);
    return 0;
}