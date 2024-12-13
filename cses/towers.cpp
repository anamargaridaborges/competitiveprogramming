#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int seg[4*MAXN];
int seq[MAXN];

const int inf = 1e9;

int ans (int node, int l, int r, int l0, int r0) {
    if (r<l0 || l>r0) return inf;
    if (l>=l0 && r<=r0) return seg[node];
    int mid = (l+r)/2;
    int resp = min(ans(2*node, l, mid, l0, r0), ans(2*node+1, mid+1, r, l0, r0));
    return resp;
}

int update1 (int node, int l, int r, int last) {
    if (l == r) {
        seq[last]--;
        if (seq[last]>0) return seg[node] = last;
        else return seg[node] = inf;
    }
    int mid = (l+r)/2;
    if (last<=mid) seg[node] = min(seg[2*node+1], update1(2*node, l, mid, last));
    else seg[node] = min(seg[2*node], update1(2*node+1, mid+1, r, last));
    return seg[node];
}

int update2 (int node, int l, int r, int novo) {
    if (l == r) {
        seq[novo]++;
        return seg[node] = novo;
    }
    int mid = (l+r)/2;
    if (novo<=mid) seg[node] = min(seg[2*node+1], update2(2*node, l, mid, novo));
    else seg[node] = min(seg[2*node], update2(2*node+1, mid+1, r, novo));
    return seg[node];
}

int main () {
    int n;
    scanf ("%d", &n);
    int vet[MAXN], aux[MAXN];
    for (int i=1; i<=n; i++) {
        scanf ("%d", &vet[i]);
        aux[i] = vet[i];
    }
    sort (aux+1, aux+n+1);
    map<int, int> corresp;
    int cont = 0;
    for (int i=1; i<=n; i++) {
        if (corresp.find(aux[i]) == corresp.end()) {
            corresp[aux[i]] = ++cont;
        }
    }
    int resp = 0;
    for (int i=1; i<=4*n; i++) seg[i] = inf;
    for (int i=1; i<=n; i++) {
        int base = ans(1, 1, cont, corresp[vet[i]]+1, cont);
        if (base == inf) {
            resp++;
            update2(1, 1, cont, corresp[vet[i]]);
        }
        else {
            update1(1, 1, cont, base);
            update2(1, 1, cont, corresp[vet[i]]);
        }
    }
    printf ("%d\n", resp);
    return 0;
}