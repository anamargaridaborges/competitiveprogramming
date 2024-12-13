#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int vet[MAXN], menor[MAXN];

int main () {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    for (int i=2; i<=n; i++) {
        int aux=i-1;
        while (vet[aux]>=vet[i]) aux = menor[aux];
        menor[i]=aux;
    }
    for (int i=1; i<=n; i++) printf ("%d ", menor[i]);
    printf ("\n");
    return 0;
}