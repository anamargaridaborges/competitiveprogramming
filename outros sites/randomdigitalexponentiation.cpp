#include <bits/stdc++.h>
#define int long long

using namespace std;

deque<int> digitos;
int ans[15];
int pot10[15];

bool rec (int restante, int digito_at) {
    if (digito_at == (int)digitos.size()) {
        if (restante == 0) return true;
        else return false;
    }
    int mult = digitos[digito_at];
    int at = 1;
    int pot = 0;
    while (at*mult*pot10[digito_at] <= restante) {
        at = at*mult;
        pot += 1;
    }
    //cout<<pot<<" "<<at<<" "<<restante<<endl;
    at = 1;
    for (int i=0; i<=pot; i++) {
        bool check = rec (restante - at*pot10[digito_at], digito_at + 1);
        ans[digito_at] = i;
        if (check) {
            return true;
        }
        at = at*mult;
    }
    return false;
}

int32_t main () {
    int a, b;
    cin>>a>>b;
    while (a > 0) {
        digitos.push_front(a%10);
        a = a/10;
    }
    int at10 = 1;
    for (int i=0; i<(int)digitos.size(); i++) {
        pot10[(int)digitos.size() - i - 1] = at10;
        at10 = at10 * 10;
    }
    rec(b, 0);
    for (int i=0; i<(int)digitos.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}