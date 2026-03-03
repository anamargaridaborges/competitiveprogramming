#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ans;

void rec (int n, int origem, int aux, int destino) {
    if (n == 1) {
        ans.push_back({origem, destino});
        return;
    }
    rec(n-1, origem, destino, aux);
    ans.push_back({origem, destino});
    rec(n-1, aux, origem, destino);
}

int main () {
    int n;
    cin>>n;
    rec(n, 1, 2, 3);
    cout<<ans.size()<<endl;
    for (pair<int, int> x : ans) {
        cout<<x.first<<' '<<x.second<<endl;
    }
    return 0;
}