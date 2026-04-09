#include <bits/stdc++.h>

using namespace std;

map<vector<vector<int>>, int> dist;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check (int x, int y) {
    return (x >= 0 && x < 3 && y >=0 && y < 3);
}

bool fim(vector<vector<int>> v) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i == 0 && j == 0 && v[i][j] != 1) return false; 
            if (i == 0 && j == 1 && v[i][j] != 2) return false; 
            if (i == 0 && j == 2 && v[i][j] != 3) return false; 
            if (i == 1 && j == 0 && v[i][j] != 4) return false; 
            if (i == 1 && j == 1 && v[i][j] != 5) return false; 
            if (i == 1 && j == 2 && v[i][j] != 6) return false; 
            if (i == 2 && j == 0 && v[i][j] != 7) return false; 
            if (i == 2 && j == 1 && v[i][j] != 8) return false; 
            if (i == 2 && j == 2 && v[i][j] != 0) return false; 
        }
    }
    return true;
}

int main () {
    vector<vector<int>> vet(3);
    for (int j=0; j<3; j++) {
        for (int i=0; i<3; i++) {
            int x;
            cin>>x;
            vet[j].push_back(x);
        }
    }
    queue<vector<vector<int>>> q;
    q.push(vet);
    int ans = -1;
    dist[vet] = 0;
    while (!q.empty()) {
        vector<vector<int>> at = q.front();
        vector<vector<int>> aux = q.front();
        if (fim(at)) {
            ans = dist[at];
            break;
        }
        q.pop();
        int x, y;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (at[i][j] == 0) {
                    x = i, y = j;
                    break;
                }
            }
        }
        for (int i=0; i<4; i++) {
            int novoX = x + dx[i];
            int novoY = y + dy[i];
            if (!check(novoX, novoY)) continue;
            swap(aux[x][y], aux[novoX][novoY]);
            if (dist.find(aux) == dist.end()) {
                dist[aux] = dist[at] + 1;
                q.push(aux);
            }
            swap(aux[x][y], aux[novoX][novoY]);
        }
    }
    cout<<ans<<endl;
}