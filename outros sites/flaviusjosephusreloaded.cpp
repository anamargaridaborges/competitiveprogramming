#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main () {
    while (true) {
        lli n, a, b;
        scanf ("%lld", &n);
        if (n==0) break;
        scanf ("%lld%lld", &a, &b);
        map<lli, lli> ciclo;
        lli atual = 0;
        for (lli i=1; ; i++) {
            if (ciclo.find(atual)!=ciclo.end()) {
                printf ("%lld\n", n-(i-ciclo[atual]));
                break;
            }
            ciclo[atual] = i;
            atual = (atual*atual)%n;
            atual = (a*atual)%n;
            atual = (atual+b)%n;
        }
    }
    return 0;
}