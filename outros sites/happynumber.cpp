#include <bits/stdc++.h>

using namespace std;

map<long long int, int> ans;
map<long long int, int> ciclo;

long long int digitos_ao_quadrado (long long int atual) {
    long long int aux = 0;
    while (atual>0) {
        aux += (atual%10)*(atual%10);
        atual /= 10;
    }
    return aux;
}

int main () {
    int t;
    scanf ("%d", &t);
    for (int i=1; i<=t; i++) {
        long long int x;
        scanf ("%lld", &x);
        long long int atual = x;
        int cont = 0;
        bool happy = true;
        while (true) {
            if (ans.find(atual)!=ans.end()) {
                if (ans[atual]==1) printf ("Case #%d: %lld is a Happy number.\n", i, x);
                else {
                    printf ("Case #%d: %lld is an Unhappy number.\n", i, x);
                    happy = false;
                }
                break;
            }
            if (atual == 1) {
                printf ("Case #%d: %lld is a Happy number.\n", i, x);
                break;
            }
            if (ciclo.find(atual) != ciclo.end()) {
                printf ("Case #%d: %lld is an Unhappy number.\n", i, x);
                happy = false;
                break;
            }
            ciclo[atual] = ++cont;
            atual = digitos_ao_quadrado(atual);
        }
        auto u = ciclo.begin();
        if (happy) {
            while (u!=ciclo.end()) {
                ans[u->first] = 1;
                ++u;
            }
        }
        else {
            while (u!=ciclo.end()) {
                ans[u->first] = 2;
                ++u;
            }
        }
        ciclo.clear();
    }
    return 0;
}