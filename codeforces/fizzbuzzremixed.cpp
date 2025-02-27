#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);
        if (n%15>2) printf ("%d\n", ((n/15)+1)*3);
        else if (n%15==0) printf ("%d\n", (n/15)*3+1);
        else if (n%15==1) printf ("%d\n", (n/15)*3+2);
        else if (n%15==2) printf ("%d\n", (n/15)*3+3);
    }
    return 0;
}