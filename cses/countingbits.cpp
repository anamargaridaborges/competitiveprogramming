#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main () {
    int n;
    cin>>n;
    int aux = 1;
    vector<int> pot2;
    while (aux <= n) {
        pot2.push_back(aux);
        aux *= 2;
    }
    int ans = 0;
    for (auto v : pot2) {
        int novo = n - (v - 1);
        if (novo % v == 0) {
            if ((novo/v) % 2 == 1) ans += ((novo/v)/2 + 1) * v;
            else ans += ((novo/v)/2) * v;
        }
        else if ((novo/v) % 2 == 0) {
            ans += ((novo/v)/2) * v;
            ans += novo % v;
        }
        else ans += ((novo/v)/2 + 1) * v;
    }
    cout<<ans<<endl;
    return 0;
}