#include <bits/stdc++.h>

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        priority_queue<int> a, b;
        for (int i=1; i<=n; i++) {
            int x;
            cin>>x;
            a.push(x);
        }
        for (int i=1; i<=m; i++) {
            int x;
            cin>>x;
            b.push(x);
        }
        bool alice_venceu = false;
        for (int i=1; ; i++) {
            int alice = a.top();
            int bob = b.top();
            if (i%2 == 1) {
                if (alice >= bob) b.pop();
                else {
                    b.pop();
                    b.push(bob-alice);
                }
                if (b.empty()) {
                    alice_venceu = true;
                    break;
                }
            }
            else {
                if (bob >= alice) a.pop();
                else {
                    a.pop();
                    a.push(alice-bob);
                }
                if (a.empty()) {
                    break;
                }
            }
        }
        if (alice_venceu) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}