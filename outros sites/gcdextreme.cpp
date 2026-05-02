#include <bits/stdc++.h>
#define int long long

using namespace std;

int soma_gcd[1000010];
int phi[1000010];

void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    phi_1_to_n(1000000);
    for (int i=1; i<=1000000; i++) {
        for (int j=2*i; j<=1000000; j+=i) {
            soma_gcd[j] += i * phi[j/i];
        }
    }
    for (int i=2; i<=1000000; i++) soma_gcd[i] = soma_gcd[i] + soma_gcd[i-1];
    while (true) {
        int n;
        cin>>n;
        if (n == 0) break;
        cout<<soma_gcd[n]<<endl;
    }
    return 0;
}