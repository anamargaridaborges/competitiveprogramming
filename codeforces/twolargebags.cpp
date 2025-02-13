#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);
        int vet[1010];
        for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
        sort(vet+1, vet+n+1);
        int vet2[1010];
        int ind = 1;
        bool funciona = true;
        for (int i=1; i<=n; i++) {
            if (vet[i] == -1) continue;
            if (i==1) {
                if (vet[1] != vet[2]) {
                    funciona = false;
                    break;
                }
                vet2[ind++] = vet[1];
                vet[2] = -1;
                continue;
            }
            for (int j=1; j<ind; j++) {
                if (vet[i] == vet2[j]) vet[i]++;
            }
            if (vet[i] == vet[i-1]) {
                vet2[ind++] = vet[i];
                vet[i] = -1;
            }
        }
        /*for (int i=1; i<=n; i++) printf ("%d ", vet[i]);
        printf ("\n");
        for (int i=1; i<ind; i++) printf ("%d ", vet2[i]);
        printf ("\n");*/
        ind = 1;
        for (int i=1; i<=n; i++) {
            if (vet[i] == -1) continue;
            if (vet[i] != vet2[ind++]) {
                funciona = false;
            }
        }
        if (funciona) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}