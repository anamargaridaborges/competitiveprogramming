#include <bits/stdc++.h>
#define MAXN (int)1e6 + 10

int dp[MAXN];
const int inf = (int)1e9 + 10;

int main () {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=9; i++) dp[i] = 1;
    for (int i=10; i<=n; i++) {
        int ans = inf;
        int aux = i;
        while (aux>0) {
            if (aux%10!=0) {
                if (dp[i-(aux%10)]+1<ans) ans = dp[i-(aux%10)]+1;
            }
            aux = aux/10;
        }
        dp[i] = ans;
    }
    printf ("%d\n", dp[n]);
    return 0;
}