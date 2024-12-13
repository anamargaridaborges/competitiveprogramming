#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int mini[4*MAXN], ind_mini[4*MAXN], maxi[4*MAXN], ind_maxi[4*MAXN];
int vet[MAXN];

void build_mini(int node, int l, int r) {
    if (l==r) {
        mini[node] = vet[l];
        ind_mini[node] = l;
        return;
    }
    int mid = (l+r)/2;
    build_mini(2*node, l, mid);
    build_mini(2*node+1, mid+1, r);
    if (mini[2*node]<=mini[2*node+1]) {
        mini[node] = mini[2*node];
        ind_mini[node] = ind_mini[2*node];
    }
    else {
        mini[node] = mini[2*node+1];
        ind_mini[node] = ind_mini[2*node+1];
    }
    return;
}

void build_maxi(int node, int l, int r) {
    if (l==r) {
        maxi[node] = vet[l];
        ind_maxi[node] = l;
        return;
    }
    int mid = (l+r)/2;
    build_maxi(2*node, l, mid);
    build_maxi(2*node+1, mid+1, r);
    if (maxi[2*node]>=maxi[2*node+1]) {
        maxi[node] = maxi[2*node];
        ind_maxi[node] = ind_maxi[2*node];
    }
    else {
        maxi[node] = maxi[2*node+1];
        ind_maxi[node] = ind_maxi[2*node+1];
    }
    return;
}

pair<int, int> build_ans_mini (int node, int l, int r, int l0, int r0) {
    if (l>=l0 && r<=r0) return {mini[node], ind_mini[node]};
    if (l>r0 || r<l0) return {1000000000, 0};
    int mid = (l+r)/2;
    pair<int, int> ans1 = build_ans_mini(2*node, l, mid, l0, r0);
    pair<int, int> ans2 = build_ans_mini(2*node+1, mid+1, r, l0, r0);
    if (ans1.first<=ans2.first) return {ans1.first, ans1.second};
    else return {ans2.first, ans2.second};
}

pair<int, int> build_ans_maxi (int node, int l, int r, int l0, int r0) {
    if (l>=l0 && r<=r0) return {maxi[node], ind_maxi[node]};
    if (l>r0 || r<l0) return {0, 0};
    int mid = (l+r)/2;
    pair<int, int> ans1 = build_ans_maxi(2*node, l, mid, l0, r0);
    pair<int, int> ans2 = build_ans_maxi(2*node+1, mid+1, r, l0, r0);
    if (ans1.first>=ans2.first) return {ans1.first, ans1.second};
    else return {ans2.first, ans2.second};
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);
        for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
        build_mini(1, 1, n);
        build_maxi(1, 1, n);
        int q;
        scanf ("%d", &q);
        while (q--) {
            int l, r;
            scanf ("%d%d", &l, &r);
            pair<int, int> ans_mini = build_ans_mini(1, 1, n, l, r);
            pair<int, int> ans_maxi = build_ans_maxi(1, 1, n, l, r);
            if (ans_mini.first == ans_maxi.first) printf ("-1 -1\n");
            else printf ("%d %d\n", min(ans_mini.second, ans_maxi.second), max(ans_mini.second, ans_maxi.second));
        }
        printf ("\n");
    }
    return 0;
}