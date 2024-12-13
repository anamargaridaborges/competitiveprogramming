#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf ("%d", &n);
    stack<int> mini;
    while (n--) {
        char comando[10];
        scanf ("%s", comando);
        if (strcmp(comando, "PUSH") == 0) {
            int v;
            scanf ("%d", &v);
            if (mini.size() == 0) {
                mini.push(v);
            }
            else {
                mini.push(min(mini.top(), v));
            }
        }
        else if (strcmp(comando, "POP") == 0) {
            if (mini.empty()) {
                printf ("EMPTY\n");
            }
            else {
                mini.pop();
            }
        }
        else if (strcmp(comando, "MIN") == 0) {
            if (mini.empty()) {
                printf ("EMPTY\n");
            }
            else {
                printf ("%d\n", mini.top());
            }
        }
    }
    return 0;
}