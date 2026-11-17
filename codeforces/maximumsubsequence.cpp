#include <bits/stdc++.h>
#define int long long

using namespace std;

int vet[40];
vector<int> sum1, sum2;
int n, m;

void backtracking (int sum, int r, int idx, bool is_one) {
    if (idx == r + 1) {
        if (is_one) sum1.push_back(sum);
        else sum2.push_back(sum);
        return;
    }
    backtracking(sum, r, idx+1, is_one);
    backtracking((sum+vet[idx])%m, r, idx+1, is_one);
}

int binary_search (int y) {
    int l = 0, r = (int)sum2.size(), mid;
    int idx = -1;
    while (l <= r) {
        mid = (l+r)/2;
        if (sum2[mid] + y >= m) {
            r = mid - 1;
        }
        else {
            idx = mid;
            l = mid + 1;
        }
    }
    return idx;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>vet[i];
        vet[i] = vet[i]%m;
    }
    backtracking(0ll, n/2, 1, true);
    backtracking(0ll, n, (n/2)+1, false);
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    int ans = 0;
    int last = sum2[(int)sum2.size()-1];
    for (int y : sum1) {
        // acho o valor que, somado a y, dá no maximo m e maior soma
        // acho o valor que, somado a y, dá mais que m e maior soma
        int a = binary_search(y);
        int b = last;
        if (a == -1) {
            ans = max(ans, (b+y)%m);
        }
        else {
            a = sum2[a];
            ans = max(ans, max((a+y)%m, (b+y)%m));
        }
    }
    cout<<ans<<endl;
}

