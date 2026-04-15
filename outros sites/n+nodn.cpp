#include <bits/stdc++.h>
#define int long long

using namespace std;

int qtd_div (int x) {
    int qtd = 0;
    for (int i=1; i*i <= x; i++) {
        if (x % i == 0) {
            if (i*i == x) qtd++;
            else qtd += 2;
        }
    }
    return qtd;
}

int32_t main () {
    vector<int> sequence;
    sequence.push_back(1);
    int at = 1;
    while (at <= 1000000) {
        at = at + qtd_div(at);
        sequence.push_back(at);
    }
    int t;
    cin>>t;
    int n = (int)sequence.size();
    for (int i=1; i<=t; i++) {
        int a, b;
        cin>>a>>b;
        int l = 0, r = n-1, mid;
        int menores = -1;
        while (l <= r) {
            mid = (l+r)/2;
            if (sequence[mid] >= a) {
                r = mid - 1;
            }
            else {
                menores = mid;
                l = mid + 1;
            }
        }
        menores++;
        l = 0, r = n-1;
        int maiores = -1;
        while (l <= r) {
            mid = (l+r)/2;
            if (sequence[mid] <= b) {
                l = mid + 1;
            }
            else {
                maiores = mid;
                r = mid - 1;
            }
        }
        maiores = n - (maiores + 1);
        cout<<"Case "<<i<<": "<<n - menores - maiores - 1<<"\n";
    }

}