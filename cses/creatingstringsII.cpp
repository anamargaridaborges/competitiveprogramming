#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = (int)(1e9 + 7);

int exp (int a, int b) {
    if (b == 0) return 1ll;
    if (b == 1) return a;

    int aux = exp(a, b/2);

    int resp = (aux * aux) % mod;

    if (b % 2 == 1) {
        resp = (resp * a) % mod;
    }

    return resp;

}

int qtd[30];
int fatorial[1000010];

int32_t main () {

    string s;
    cin>>s;

    for (int i=0; i<(int)s.size(); i++) {
        qtd[s[i] - 'a']++;
    }

    fatorial[0] = 1;
    fatorial[1] = 1;

    for (int i=2; i<=(int)s.size(); i++) fatorial[i] = (fatorial[i-1] * i) % mod;

    int denominador = 1;

    for (int i=0; i<29; i++) denominador = (denominador * fatorial[qtd[i]]) % mod;

    denominador = exp(denominador, mod - 2);

    cout<<(fatorial[(int)s.size()] * denominador) % mod<<endl;

    return 0;
}