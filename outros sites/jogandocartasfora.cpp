#include <bits/stdc++.h>

using namespace std;

int main () {
    while (true) {
        int n;
        scanf ("%d", &n);
        if (n == 0) break;
        queue<int> q;
        for (int i=1; i<=n; i++) {
            q.push(i);
        }
        printf ("Discarded cards: ");
        while (q.size()>1) {
            if (q.size()>2) printf ("%d, ", q.front());
            else printf ("%d\n", q.front());
            q.pop();
            int fim = q.front();
            q.pop();
            q.push(fim);
        }
        printf ("Remaining card: %d\n", q.front());
        q.pop();
    }
    return 0;
}