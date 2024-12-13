#include <bits/stdc++.h>
#define float double

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int b, t1, a1, t2, a2;
        scanf ("%d%d%d%d%d", &b, &t1, &a1, &t2, &a2);
        float novo_1 = (float)a1, novo_2 = (float)a2;
        float ans1 = (float)a1/(float)b;
        if ((float)t1+ans1<=t2) {
            float ans2 = (float)a2/(float)b;
            printf ("%.8lf %.8lf\n", ans1, ans2);
        }
        else {
            float aux1 = ans1-(t2-t1);
            ans1 = t2-t1;
            novo_1 -= (t2-t1)*b;
            float ans2 = (float)a2/(float)b;
            float aux2 = ans2;
            ans2 = 0;
            if (aux1<aux2) {
                ans1 += aux1*2;
                ans2 += aux1*2;
                //novo_2 -= (aux1/2.0)*b;
                aux2 -= aux1;
                aux1 = 0;
            }
            else if (aux1>aux2) {
                ans2 += 2*aux2;
                ans1 += 2*aux2;
                //novo_1 -= (aux2/2.0)*b;
                aux1 -= aux2;
                aux2 = 0;
            }
            else {
                ans1 += 2*aux1;
                ans2 += 2*aux2;
                aux2 = 0;
                aux1 = 0;
            }
            if (aux1 != 0) {
                ans1 += aux1;
            }
            if (aux2 != 0) {
                ans2 += aux2;
            }
            printf ("%.8lf %.8lf\n", ans1, ans2);
        }
    }
    return 0;
}