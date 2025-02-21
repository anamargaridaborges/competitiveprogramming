#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll dp[20][2][2][10][2];
deque<int> l, r;

ll rec (int idx, int maior, int menor, int ultimo, int ze) {
    if (idx == l.size()) return 1;
    ll &resp = dp[idx][maior][menor][ultimo][ze];
    if (resp != -1) return resp;
    resp = 0;
    for (int i = (menor ? l[idx] : 0); i <= (maior ? r[idx] : 9); i++) {
        if (i == ultimo && ze == 0) continue;
        resp += rec(idx+1, maior&&(i == r[idx]), menor&&(i == l[idx]), i, ze&&(i == 0));
    }
    return resp;
}

void build (ll a, ll b) {
    if (a == 0 && b == 0) {
        l.push_back(0);
        r.push_back(0);
    } 
    while (a>0) {
        l.push_front(a%10);
        a = a/10;
    }
    while (b>0) {
        r.push_front(b%10);
        b = b/10;
    }
    while (l.size()<r.size()) l.push_front(0);
    return;
}

int main () {
    ll a, b;
    scanf ("%lld%lld", &a, &b);
    for (int i=0; i<20; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<=1; k++) dp[i][0][0][j][k] = dp[i][0][1][j][k] = dp[i][1][0][j][k] = dp[i][1][1][j][k] = -1;
        }
    }
    build(a, b);
    printf ("%lld\n", rec(0, 1, 1, -1, 1));
    return 0;
}