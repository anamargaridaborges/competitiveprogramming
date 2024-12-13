#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main () {
    for (int cont=1; ; cont++) {
        lli z, i, m, l;
        scanf ("%lld%lld%lld%lld", &z, &i, &m, &l);
        if (z==0 && i==0 && m==0 && l==0) break;
        map<lli, int> ciclo;
        lli atual = l;
        for (lli j=1; ; j++) {
            if (ciclo.find(atual)!=ciclo.end()) {
                printf ("Case %d: %lld\n", cont, j-ciclo[atual]);
                break;
            }
            ciclo[atual] = j;
            atual = (z*atual+i)%m;
        }
        ciclo.clear();
    }
    return 0;
}