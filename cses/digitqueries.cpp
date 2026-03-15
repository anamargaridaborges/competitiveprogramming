#include <iostream>
#define int long long

using namespace std;

int pos[20], pref[20];

int32_t main () {
    int qtd = 0;
    int pot = 1;
    for (int i=1; i<18; i++) {
        int aux = 9*pot*i;
        pos[i] = aux;
        qtd += aux;
        pot*=10;
    }
    for (int i=1; i<18; i++) {
        pref[i] = pref[i-1] + pos[i];
    }
    int q;
    cin>>q;
    while (q--) {
        int k;
        cin>>k;
        int ans = 0, d = 1;
        for (int i=1; i<18; i++) {
            if (pref[i] > k) break;
            ans = pref[i];
            d = i+1;
        }
        if (ans == k) {
            cout<<9<<endl;
            continue;
        }
        k -= ans;
        int divi = (k-1)/d, res = (k-1)%d;
        // res-ésimo dígito do divi-ésimo número de d dígitos
        int aux = 1;
        for (int i=1; i<d; i++) {
            aux *= 10;
        }
        int novo = aux + divi;
        int digi_at;
        for (int i=0; i<=res; i++) {
            digi_at = novo/aux;
            novo -= (novo/aux) * aux;
            aux = aux/10;
        }
        cout<<digi_at<<endl;
    }
    return 0;
}