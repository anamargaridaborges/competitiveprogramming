#include <bits/stdc++.h>
#define MAXN 110
#define MAXS (int)1e5 + 10

using namespace std;
int suf[MAXN];
int dp[MAXS];

int main () {
    int n;
    scanf ("%d", &n);
    int vet[MAXN];
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    for (int i=n; i>=1; i--) suf[i] = suf[i+1] + vet[i];
    dp[0] = 1;
    for (int i=n; i>=1; i--) {
        for (int j=suf[i]; j>=vet[i]; j--) {
            if (dp[j-vet[i]] == 1) dp[j] = 1;
        }
    }
    int total = 0;
    for (int i=1; i<=suf[1]; i++) {
        if (dp[i] == 1) total++;
    }
    printf ("%d\n", total);
    for (int i=1; i<=suf[1]; i++) {
        if (dp[i] == 1) printf ("%d ", i);
    }
    printf ("\n");
    return 0;
}