#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin>>n;
    int sub = 0;
    if (n == 1) {
        cout<<0<<endl;
        return 0;
    }
    if (n == 2) {
        cout<<2<<endl;
        return 0;
    }
    for (int i=1; (i*i) <= (n-1); i++) {
        if ((n-1)%i == 0) {
            if (i*i == (n-1)) sub += 1;
            else sub += 2;
        }
    }
    sub--;
    cout<<n-sub<<endl;
    return 0;
}