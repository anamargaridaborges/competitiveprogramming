#include <bits/stdc++.h>

using namespace std;

int freq[200010];

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int vet[200010];
        for (int i=1; i<=n; i++) freq[i] = 0;
        bool perm = true;
        for (int i=1; i<=n; i++) {
            cin>>vet[i];
            if (freq[vet[i]]>0) perm = false;
            freq[vet[i]]++;
        }
        if (perm == false) {
            int a, b = -1, c = -1;
            for (int i=1; i<=n; i++) {
                if (freq[i] == 0) {
                    a = i;
                }
                else {
                    if (b == -1) b = i;
                    else if (c == -1) c = i;
                }
            }
            cout<<"? "<<a<<' '<<b<<endl;
            fflush(stdout);
            int ans;
            cin>>ans;
            cout<<"? "<<a<<' '<<c<<endl;
            fflush(stdout);
            cin>>ans;
            if (ans == 0) {
                cout<<"! A"<<endl;
                fflush(stdout);
            }
            else {
                cout<<"! B"<<endl;
                fflush(stdout);
            }
        }
        else {
            int i, j;
            for (int k=1; k<=n; k++) {
                if (vet[k] == 1) i = k;
                if (vet[k] == n) j = k;
            }
            int ans1, ans2;
            cout<<"? "<<i<<' '<<j<<endl;
            fflush(stdout);
            cin>>ans1;
            cout<<"? "<<j<<' '<<i<<endl;
            fflush(stdout);
            cin>>ans2;
            if (ans1 == ans2 && ans1>=n-1) {
                cout<<"! B"<<endl;
                fflush(stdout);
            }
            else {
                cout<<"! A"<<endl;
                fflush(stdout);
            }
        }
    }
    return 0;
}