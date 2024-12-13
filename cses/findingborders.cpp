#include <bits/stdc++.h>
#define MAXN (int)1e6 + 10

using namespace std;

const int primo = 37;
const int mod1 = (int)1e9 + 7;
const int mod2 = (int)1e9 + 9;

int main () {
    char s[MAXN];
    scanf ("%s", s);
    long long int pot1[MAXN], pot2[MAXN];
    pot1[0] = 1;
    pot2[0] = 1;
    int tam = strlen(s);
    for (int i=1; i<=tam; i++) {
        pot1[i] = (pot1[i-1]*primo)%mod1;
        pot2[i] = (pot2[i-1]*primo)%mod2;
    }
    long long int pref1 = 0, pref2 = 0, suf1 = 0, suf2 = 0;
    for (int i=0; i<tam-1; i++) {
        pref1 = (pref1+((s[i]-96)*pot1[i])%mod1)%mod1;
        pref2 = (pref2+((s[i]-96)*pot2[i])%mod2)%mod2;
        suf1 = (suf1*primo)%mod1;
        suf1 = (suf1+(s[tam-i-1]-96))%mod1;
        suf2 = (suf2*primo)%mod2;
        suf2 = (suf2+(s[tam-i-1]-96))%mod2;
        if (pref1 == suf1 && pref2 == suf2) printf ("%d ", i+1);
    }
    printf ("\n");
    return 0;
}