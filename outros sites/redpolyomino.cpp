#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

char mat[10][10];
int ans;
int vis[10][10];
int32_t dx[4] = {0, 0, 1, -1};
int32_t dy[4] = {1, -1, 0, 0};
int n;

bool check (int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int32_t main () {
    int k;
    cin>>n>>k;
    queue<int> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>mat[i][j];
            if (mat[i][j] == '.') {
                q.push(pow(2, n*i + j));
            }
        }
    }
    set<int> processado;
    while (!q.empty()) {
        int at = q.front();
        q.pop();
        if (processado.find(at) != processado.end()) continue;
        processado.insert(at);
        if (__builtin_popcountll(at) == k) {
            ans++;
            continue;
        }
        //cout<<at<<endl;
        for (int i=0; i<n*n; i++) {
            if ((at & (1ULL<<i))) {
                int x = i/n;
                int y = i%n;
                for (int j=0; j<4; j++) {
                    int novoX = x+dx[j];
                    int novoY = y+dy[j];
                    if (!check(novoX, novoY)) continue;
                    if (mat[novoX][novoY] != '.') continue;
                    //cout<<(at | (1ULL<<(novoX*n + novoY)))<<endl;
                    if (processado.find((at | (1ULL<<(novoX*n + novoY)))) != processado.end()) continue;
                    q.push((at | (1ULL<<(novoX*n + novoY))));
                    //processado.insert((at | (1ULL<<(novoX*n + novoY))));
                }
            }
        }
    }
    cout<<ans<<endl;
}