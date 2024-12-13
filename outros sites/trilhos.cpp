#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int main () {
    while (true) {
        int n;
        scanf ("%d", &n);
        if (n == 0) break;
        int vet[MAXN];
        while (true) {
            scanf ("%d", &vet[1]);
            if (vet[1] == 0) break;
            for (int i=2; i<=n; i++) scanf ("%d", &vet[i]);
            stack<int> p;
            int usado[MAXN];
            for (int i=1; i<=n; i++) usado[i] = 0;
            for (int i=1; i<=n; i++) {
                if (p.empty() || vet[i] != p.top()) {
                    int lim_inf = 0;
                    for (int j=vet[i]; j>=1; j--) {
                        if (usado[j] == 1) {
                            lim_inf = j;
                            break;
                        }
                    }
                    for (int j = lim_inf+1; j<=vet[i]; j++) {
                        p.push(j);
                        usado[j] = 1;
                    }
                }
                if (vet[i] != p.top()) {
                    printf ("No\n");
                    break;
                }
                else {
                    p.pop();
                    if (i == n) printf ("Yes\n");
                }
            }
            while (!p.empty()) p.pop();
        }
        printf ("\n");
    }
    return 0;
}