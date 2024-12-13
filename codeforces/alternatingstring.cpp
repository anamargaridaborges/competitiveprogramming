#include <bits/stdc++.h>
// a = 97

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        char s[200010];
        int cont[40][2][200010];
        scanf ("%d", &n);
        for (int i=0; i<40; i++) {
            for (int j=1; j<=n; j++) {
                cont[i][0][j] = 0;
                cont[i][1][j] = 0;
            }
        }
        for (int i=1; i<=n; i++) {
            scanf (" %c", &s[i]);
            cont[s[i]-96][i%2][i]++;
        }
        for (int i=3; i<=n; i+=2) {
            for (int j=1; j<=26; j++) {
                cont[j][1][i] += cont[j][1][i-2];
            }
        }
        for (int i=4; i<=n; i+=2) {
            for (int j=1; j<=26; j++) {
                cont[j][0][i] += cont[j][0][i-2];
            }
        }
        int aux1, aux2;
        if (n%2==0) {
            aux1 = n;
            aux2 = n-1;
        }
        else {
            aux1 = n-1;
            aux2 = n;
        }
        if (n%2==0) {
            int ans = 1000000000;
            for (int i=1; i<=26; i++) {
                for (int j=1; j<=26; j++) {
                    ans = min(ans, n-(cont[i][0][aux1]+cont[j][1][aux2]));
                    ans = min(ans, n-(cont[i][1][aux2]+cont[j][0][aux1]));
                }
            }
            printf ("%d\n", ans);
        }
        else {
            // escolher a melhor posicao pra tirar
            int ans = 1000000000;
            for (int i=1; i<=n; i++) {
                int fim1, fim2;
                if (i%2==0) {
                    fim1 = i;
                    fim2 = i-1;
                }
                else {
                    fim1 = i-1;
                    fim2 = i;
                }
                for (int j=1; j<=26; j++) {
                    for (int k=1; k<=26; k++) {
                        //j impar, k par
                        int qtd_j = cont[j][1][fim2] + (cont[j][0][aux1]-cont[j][0][fim1]);
                        int qtd_k = cont[k][0][fim1] + (cont[k][1][aux2]-cont[k][1][fim2]);
                        ans = min(ans, n-(qtd_j+qtd_k));
                    }
                }
            }
            printf ("%d\n", ans);
        }
    }
    return 0;
}