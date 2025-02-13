#include <bits/stdc++.h>
#define MAXN (int)(2*(1e5 + 5))

using namespace std;

typedef struct Func {
    long long int a;
    long long int b;
    long long int val (long long int x) {
        return a*x + b;
    }
}Func;

deque<Func> retas;

void update (Func curr) {
    int tam = retas.size();
    while (tam>1 && ((retas[tam-2].b-retas[tam-1].b)*(curr.a-retas[tam-2].a)) >= ((retas[tam-2].b-curr.b)*(retas[tam-1].a-retas[tam-2].a))) {
        retas.pop_back();
        tam--;
    }
    retas.push_back(curr);
}

long long int query (long long int x) {
    while (retas.size()>1 && retas[0].val(x) >= retas[1].val(x)) {
        retas.pop_front();
    }
    return retas.front().val(x);
}

int main () {
    int n;
    long long int c;
    long long int h[MAXN];
    long long int dp[MAXN];
    scanf ("%d%lld", &n, &c);
    for (int i=1; i<=n; i++) {
        scanf ("%lld", &h[i]);
        dp[i] = pow(10, 18);
    }
    dp[1] = 0;
    Func at;
    at.b = dp[1]+h[1]*h[1];
    at.a = -2*h[1];
    update(at);
    for (int i=2; i<=n; i++) {
        dp[i] = query(h[i])+h[i]*h[i]+c;
        at.b = dp[i]+h[i]*h[i];
        at.a = -2*h[i];
        update(at);
    }
    printf ("%lld\n", dp[n]);
    return 0;
}