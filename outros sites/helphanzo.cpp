#include <bits/stdc++.h>
#define int long long

using namespace std;

int primo[100010];
vector<int> primos;
int composto[100010];

void crivo() {
    for (int i=2; i<=100000; i++) {
        if (primo[i]) continue;
        for (int j=2*i; j<=100000; j+=i) primo[j] = 1;
        primos.push_back(i);
    }
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    crivo();
    int t;
    cin>>t;
    for (int j=1; j<=t; j++) {
        int a, b;
        cin>>a>>b;
        int ans = 0;
        for (int i=1; i<=(b-a+1); i++) composto[i] = 0;
        if (a == 1) composto[1] = 1;
        for (int p : primos) {
            if (p * p > b) break;
            int inicio = max(p * p, ((a + p - 1ll) / p) * p);
            for (int i=inicio; i<=b; i+=p) {
                if (i < a) continue;
                composto[i-a+1] = 1;
            }
        }
        for (int i=1; i<=(b-a+1); i++) ans += composto[i];
        ans = (b-a+1)-ans;
        cout<<"Case "<<j<<": "<<ans<<endl;
    }
    return 0;
}