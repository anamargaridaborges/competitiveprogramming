#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        char s[MAXN];
        scanf ("%s", s);
        stack<int> pilha;
        int ans = 0;
        for (int i=0; i<strlen(s); i++) {
            if (s[i] == '<') pilha.push(1);
            else if (s[i] == '>') {
                if (pilha.size()>0) {
                    pilha.pop();
                    ans++;
                }
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}