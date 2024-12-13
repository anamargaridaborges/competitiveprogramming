#include <bits/stdc++.h>
#define MAXN 110
#define MAXK (int)1e5 + 10

using namespace std;

int main () {
    int n, k;
    scanf ("%d%d", &n, &k);
    int vet[MAXN];
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    int dp[MAXK];
    dp[0] = 2;
    for (int i=1; i<=k; i++) {
        int ans_atual = 2;
        for (int j=1; j<=n; j++) {
            if (vet[j]>i) continue;
            if (dp[i-vet[j]] == 2) {
                ans_atual = 1;
                break;
            }
        }
        dp[i] = ans_atual;
    }
    if (dp[k] == 1) printf ("First\n");
    else printf ("Second\n");
    return 0;
}