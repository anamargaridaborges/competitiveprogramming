#include <bits/stdc++.h>
#define ll long long int

using namespace std;

deque<int> l, r;
deque<ll> pot10;
ll dp[22][2][2][2];
ll ans = -1;
ll num = 0;

void build (ll a, ll b) {
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

ll rec (int idx, int maior, int menor, int zero_esq) {
    if (idx == r.size()) return dp[idx+1][maior][menor][zero_esq] = 1;
    ll &resp = dp[idx][maior][menor][zero_esq];
    if (resp != -1) return resp;
    resp = 0;
    for (int d = (menor?l[idx]:0); d<=(maior?r[idx]:9); d++) {
        if (zero_esq && d==0) resp = max(resp, rec(idx+1, maior&&(d==r[idx]), menor&&(d==l[idx]), zero_esq&&(d==0)));
        else resp = max(resp, d*rec(idx+1, maior&&(d==r[idx]), menor&&(d==l[idx]), zero_esq&&(d==0)));
    }
    return resp;
}

void busca_resp (int idx, int maior, int menor, int zero_esq) {
    bool check = false;
    if (idx == r.size()) return;
    for (int d = (menor?l[idx]:0); d<=(maior?r[idx]:9); d++) {
        if (check) break;
        if (zero_esq && d == 0) {
            if (ans == dp[idx+1][maior&&(d==r[idx])][menor&&(d==l[idx])][zero_esq&&(d==0)]) {
                check = true;
                busca_resp(idx+1, maior&&(d==r[idx]), menor&&(d==l[idx]), zero_esq&&(d==0));
            }
        }
        else {
            if (ans == d*dp[idx+1][maior&&(d==r[idx])][menor&&(d==l[idx])][zero_esq&&(d==0)]) {
                check = true;
                //num += d*pow(10, l.size()-idx-1);
                num += d*pot10[idx];
                if (d!=0) ans /= d;
                busca_resp(idx+1, maior&&(d==r[idx]), menor&&(d==l[idx]), zero_esq&&(d==0));
            }
        }
        if (check) break;
    }
}

int main () {
    ll a, b;
    scanf ("%lld%lld", &a, &b);
    build(a, b);
    for (int i=0; i<20; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) dp[i][j][k][0] = dp[i][j][k][1] = -1;
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) dp[l.size()][i][j][k] = 1;
        }
    }
    ll pot = 1;
    while (pot<=b) {
        pot10.push_front(pot);
        if (pot == 1000000000000000000) break;
        pot*=10;
    }
    if (l.front() == 0) ans = rec(0, 1, 1, 1);
    else ans = rec(0, 1, 1, 0);
    printf ("%lld\n", ans);
    if (l.front() == 0) busca_resp(0, 1, 1, 1);
    else busca_resp(0, 1, 1, 0);
    printf ("%lld\n", num);
    return 0; 
}