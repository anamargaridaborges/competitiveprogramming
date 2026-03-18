#include <iostream>
#define int long long

using namespace std;

int ans[1000010];

int32_t main () {
    int n, k;
    cin>>n>>k;
    int l = 1, r = n;
    for (int i=n; i>=1; i--) {
        if ((i-1) <= k) {
            ans[l++] = i;
            k -= (i-1);
        }
        else ans[r--] = i;
    }
    for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}