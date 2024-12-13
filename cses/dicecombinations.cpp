#include <bits/stdc++.h>
#define MAXN (int)1e6 + 10

using namespace std;

const int mod = (int)1e9 + 7;

int dp[MAXN];

int comb (int x) {
    if (x == 0) return 1;
    if (dp[x] != -1) return dp[x];
    int aux = 0;
    for (int i=1; i<=6; i++) {
        if (i>x) break;
        aux += comb(x-i);
        aux = aux % mod;
    }
    return dp[x] = aux;
}

int main () {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) dp[i] = -1;
    printf ("%d\n", comb(n));
    return 0;
}