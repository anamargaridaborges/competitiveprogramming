#include <bits/stdc++.h>
#define MAXN 2*((int)1e5 + 5)

using namespace std;

int seg[4*MAXN];
map<int, int> corresp;
int vet[MAXN], aux[MAXN];

int ans (int node, int l, int r, int l0, int r0) {
    if (r<l0 || l>r0) {
        return 0;
    }
    if (l>=l0 && r<=r0) {
        return seg[node];
    }
    int mid = (l+r)/2;
    return max(ans(2*node, l, mid, l0, r0), ans(2*node+1, mid+1, r, l0, r0));
}

int update (int node, int pos, int l, int r, int v) {
    if (l == r) {
        seg[node] = max(seg[node], v);
        return seg[node];
    }
    int mid = (l+r)/2;
    if (pos<=mid) {
        seg[node] = max(seg[node], update(2*node, pos, l, mid, v));
    }
    else seg[node] = max(seg[node], update(2*node+1, pos, mid+1, r, v));
    return seg[node];
}

int main () {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf ("%d", &vet[i]);
        aux[i] = vet[i];
    }
    sort(aux+1, aux+n+1);
    int cont = 1;
    for (int i=1; i<=n; i++) {
        if (corresp.find(aux[i]) == corresp.end()) {
            corresp[aux[i]] = cont++;
        }
    }
    int lis[MAXN];
    for (int i=1; i<=n; i++) {
        int ant = ans(1, 1, cont-1, 1, corresp[vet[i]]-1);
        lis[i] = 1 + ant;
        update(1, corresp[vet[i]], 1, cont-1, lis[i]);
    }
    int resp = 0;
    for (int i=1; i<=n; i++) resp = max(resp, lis[i]);
    printf ("%d\n", resp);
    return 0;
}