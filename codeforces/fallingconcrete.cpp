#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        set<int> s;
        for (int i=1; i<=n; i++) {
            int x;
            cin>>x;
            x -= i;
            s.insert(x);
        }
        int ant = -1;
        int seq_at = 0, seq_maxi = 1;
        for (int x : s) {
            if (ant == -1) {
                seq_at++;
            }
            else if (x == ant + 1) {
                seq_at++;
            }
            else {
                seq_at = 1;
            }
            seq_maxi = max(seq_maxi, seq_at);
            ant = x;
        }
        cout<<seq_maxi<<endl;
    }
}