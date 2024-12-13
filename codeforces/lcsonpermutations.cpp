#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

map<int, int> corresp;

int seg[4*MAXN];

int ans (int node, int l, int r, int l0, int r0) {
    if (l>r0 || r<l0) return 0;
    if (l>=l0 && r<=r0) return seg[node];
    int mid = (l+r)/2;
    return max(ans(2*node, l, mid, l0, r0), ans(2*node+1, mid+1, r, l0, r0));
}

int update (int node, int l, int r, int v, int novo_v) {
    if (l == r) {
        return seg[node] = novo_v;
    }
    int mid = (l+r)/2;
    if (v<=mid) {
        seg[node] = max(seg[2*node+1], update(2*node, l, mid, v, novo_v));
    }
    else {
        seg[node] = max(seg[2*node], update(2*node+1, mid+1, r, v, novo_v));
    }
    return seg[node];
}

int main () {
    int n;
    scanf ("%d", &n);
    int v1[MAXN], v2[MAXN];
    for (int i=1; i<=n; i++) {
        scanf ("%d", &v1[i]);
        corresp[v1[i]] = i;
    }
    for (int i=1; i<=n; i++) scanf ("%d", &v2[i]);
    int resp = 0;
    for (int i=1; i<=n; i++) {
        int seq = 1+ans(1, 1, n, 1, corresp[v2[i]]-1);
        resp = max(seq, resp);
        update(1, 1, n, corresp[v2[i]], seq);
    }
    printf ("%d\n", resp);
    return 0;
}