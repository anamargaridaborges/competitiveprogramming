#include <bits/stdc++.h>
#define int long long

using namespace std;

int vet[200010];

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) cin>>vet[i];
    sort(vet+1, vet+n+1);
    if (vet[1] != 1) {
        cout<<"1"<<endl;
        return 0;
    }
    int max_sum = 1;
    for (int i=2; i<=n; i++) {
        // consigo soma de 1 até max_sum
        // quais somas consigo a mais que isso com vet[i]?
        int next = max_sum + 1;
        next = next - vet[i];
        if (next >= 0 && next <= max_sum) {
            // consigo fazer o max_sum + 1
            // consigo fazer todas as somas de max_sum + 1 até max_sum + vet[i]
            max_sum = max_sum + vet[i];
        }
        else {
            cout<<max_sum + 1<<endl;
            return 0;
        }
    }
    cout<<max_sum + 1<<endl;
    return 0;
}