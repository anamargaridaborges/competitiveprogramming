#include <iostream>
#pragma GCC optimize("O3,unroll-loops")

using namespace std;

int seg[300010], seg2[300010];

int query(int node, int l, int r, int l0, int r0) {
    if (l >= l0 && r <= r0) {
        return seg[node];
    }
    if (l > r0 || r < l0) return 0;
    int mid = (l+r)/2;
    return query(2*node, l, mid, l0, r0) + query(2*node+1, mid+1, r, l0, r0);
}

int query2(int node, int l, int r, int l0, int r0) {
    if (l >= l0 && r <= r0) {
        return seg2[node];
    }
    if (l > r0 || r < l0) return 0;
    int mid = (l+r)/2;
    return query2(2*node, l, mid, l0, r0) + query2(2*node+1, mid+1, r, l0, r0);
}

void update (int node, int l, int r, int val, int k) {
    if (l == r) {
        seg[node] += val;
        return;
    }
    int mid = (l+r)/2;
    if (k <= mid) update(2*node, l, mid, val, k);
    else update(2*node+1, mid+1, r, val, k);
    seg[node] = seg[2*node] + seg[2*node+1];
}

void update2 (int node, int l, int r, int val, int k) {
    if (l == r) {
        seg2[node] += val;
        return;
    }
    int mid = (l+r)/2;
    if (k <= mid) update2(2*node, l, mid, val, k);
    else update2(2*node+1, mid+1, r, val, k);
    seg2[node] = seg2[2*node] + seg2[2*node+1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int mini = n + 1, mini_win = n + 1;
        int resp = 0;
        for (int i=1; i<=n; i++) {
            int x;
            cin>>x;
            if (mini < x && mini_win > x) {
                resp++;
                mini_win = min(mini_win, x);
            }
            mini = min(mini, x);
        }
        cout<<resp<<endl;
    }
    return 0;
}