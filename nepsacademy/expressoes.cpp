#include <bits/stdc++.h>
#define MAXN (int)1e5 + 10

using namespace std;

map<char, char> corresp;

bool rec (char exp[MAXN], int ini, int fim) {
    if (fim<ini) return 1;
    if (exp[ini] == ')' || exp[ini] == '}' || exp[ini] == ']') return 0;
    if (exp[fim] == '(' || exp[fim] == '{' || exp[fim] == '[') return 0;
    if (fim-ini+1 == 2 && corresp[exp[ini]] == exp[fim]) return 1;
    else if (fim-ini+1 == 2) return 0;
    int par = 0, col = 0, cha = 0;
    int ini_atual = ini;
    int ans_atual = 1;
    for (int i=ini; i<=fim; i++) {
        if (exp[i] == '(') par++;
        if (exp[i] == '{') col++;
        if (exp[i] == '[') cha++;
        if (exp[i] == ')') {
            par--;
            if (par == 0 && exp[ini_atual] == '(') {
                ans_atual = rec(exp, ini_atual+1, i-1);
                ini_atual = i+1;
            }
        }
        if (exp[i] == '}') {
            col--;
            if (col == 0 && exp[ini_atual] == '{') {
                ans_atual = rec(exp, ini_atual+1, i-1);
                ini_atual = i+1;
            }
        }
        if (exp[i] == ']') {
            cha--;
            if (cha == 0 && exp[ini_atual] == '[') {
                ans_atual = rec(exp, ini_atual+1, i-1);
                ini_atual = i+1;
            }
        }
        if (ans_atual == 0) return 0;
    }
    if (par != 0 || col != 0 || cha != 0) return 0;
    return ans_atual;
}

int main () {
    int t;
    scanf ("%d", &t);
    corresp['('] = ')';
    corresp['{'] = '}';
    corresp['['] = ']';
    while (t--) {
        char exp[MAXN];
        scanf ("%s", exp);
        if (rec(exp, 0, strlen(exp)-1) == 0) printf ("N\n");
        else printf ("S\n");
    }
    return 0;
}