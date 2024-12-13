#include <bits/stdc++.h>
#define MAXN 10010

using namespace std;

int main () {
    int n;
    scanf ("%d", &n);
    int vet[MAXN], esq[MAXN], dir[MAXN];
    for (int i=1; i<=n; i++) {
        scanf ("%d", &vet[i]);
    }
    for (int i=1; i<=n; i++) {
        esq[i] = i-1;
        while (vet[esq[i]]>=vet[i]) {
            if (i == esq[i]) break;
            esq[i] = esq[esq[i]];
        }
    }
    int ans = 0;
    for (int i=n; i>=1; i--) {
        dir[i] = i+1;
        while (vet[dir[i]]>=vet[i]) {
            if (i == dir[i]) break;
            dir[i] = dir[dir[i]];
        }
        ans = max(ans, vet[i]*(dir[i]-esq[i]-1));
    }
    printf ("%d\n", ans);
    return 0;
}