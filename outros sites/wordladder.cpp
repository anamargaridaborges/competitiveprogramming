#include <bits/stdc++.h>

using namespace std;

int check[110];

int main () {
    string a, b;
    cin>>a>>b;
    vector<int> ordem;
    for (int i=0; i<(int)a.size(); i++) {
        if (a[i]==b[i]) check[i] = 1;
        if (a[i]>b[i]) {
            ordem.push_back(i);
            check[i] = 1;
        }
    }
    for (int i=(int)a.size()-1; i>=0; i--) {
        if (check[i]!=1) ordem.push_back(i);
    }
    cout<<(int)ordem.size()<<endl;
    for (int i=0; i<(int)ordem.size(); i++) {
        a[ordem[i]] = b[ordem[i]];
        cout<<a<<endl;
    }
    return 0;
}