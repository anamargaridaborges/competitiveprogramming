#include <bits/stdc++.h>
#define MAXN (int)1e6 + 10

using namespace std;

const int mod1 = (int)1e9 + 7;
const int mod2 = 998244353;

const int primo = 37;
long long int potencias1[MAXN], potencias2[MAXN];

long long int calcular_hash (char x[MAXN], const int mod) {
    long long int ans = 0;
    if (mod == mod1) {
        for (int i=0; i<strlen(x); i++) {
            ans = (ans+((x[i]-96)*potencias1[i]))%mod;
            //ans = ans%mod1;
        }
    }
    else {
        for (int i=0; i<strlen(x); i++) {
            ans = (ans+((x[i]-96)*potencias2[i]))%mod;
            //ans = ans%mod2;
        }
    }
    return ans;
}

bool sao_iguais (long long int a_hash1, long long int a_hash2, long long int b_hash1, long long int b_hash2) {
    if (a_hash1 == b_hash1 && a_hash2 == b_hash2) return true;
    else return false;
}

int main () {
    char s[MAXN], p[MAXN];
    scanf ("%s%s", s, p);
    if (strlen(p)>strlen(s)) {
        printf ("0\n");
        return 0;
    }
    // 'a' = 97
    potencias1[0] = 1;
    potencias2[0] = 1;
    for (int i=1; i<strlen(p); i++) {
        potencias1[i] = (potencias1[i-1]*primo)%mod1;
    }
    for (int i=1; i<strlen(p); i++) {
        potencias2[i] = (potencias2[i-1]*primo)%mod2;
    }
    char aux[MAXN];
    for (int i=0; i<strlen(p); i++) {
        aux[i] = s[i];
    }
    aux[strlen(p)] = '\0';
    long long int hash1 = calcular_hash(p, mod1), hash2 = calcular_hash(p, mod2);
    int resp = 0;
    long long int at1 = calcular_hash(aux, mod1), at2 = calcular_hash(aux, mod2);
    if (sao_iguais(hash1, hash2, at1, at2)) {
        resp++;
    }
    long long int inv1[40];
    long long int inv2[40];
    inv1[1] = 1;
    inv2[1] = 1;
    for (int i = 2; i <=38; i++) inv1[i] = mod1 - mod1/i * inv1[mod1 % i] % mod1;
    for (int i = 2; i <=38; i++) inv2[i] = mod2 - mod2/i * inv2[mod2 % i] % mod2;
    for (int i=1; i<=strlen(s)-strlen(p); i++) {
        at1 -= s[i-1]-96;
        //at1 = at1%mod1;
        at1 = (at1*inv1[primo])%mod1;
        //at1 = at1/primo;
        at2 -= s[i-1]-96;
        //at2 = at2%mod2;
        at2 = (at2*inv2[primo])%mod2;
        //at2 = at2/primo;
        int ind = i + strlen(p) - 1;
        at1 += ((s[ind]-96)*potencias1[strlen(p)-1])%mod1;
        at2 += ((s[ind]-96)*potencias2[strlen(p)-1])%mod2;
        at1 = at1%mod1;
        at2 = at2%mod2;    
        if (sao_iguais(at1, at2, hash1, hash2)) {
            resp++; 
        }
    } 
    printf ("%d\n", resp);
    return 0;
}