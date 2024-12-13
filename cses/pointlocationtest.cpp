#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        long long int x1, y1, x2, y2, x3, y3;
        scanf ("%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3);
        long long int x_a = x2-x1, y_a = y2-y1;
        long long int x_b = x3-x1, y_b = y3-y1;
        long long int prod = x_a*y_b - y_a*x_b;
        if (prod>0) printf ("LEFT\n");
        else if (prod<0) printf ("RIGHT\n");
        else printf ("TOUCH\n");
    }
    return 0;
}