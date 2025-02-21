#include <bits/stdc++.h>
#define ll long long int

using namespace std;

typedef struct t_vetor {
    ll x, y;
    t_vetor menos(t_vetor a) {
        t_vetor ans;
        ans.x = x-a.x;
        ans.y = y-a.y;
        return ans;
    }
    ll cross(t_vetor a) {
        return x*a.y - y*a.x;
    }
    bool igual(t_vetor a) {
        if (x==a.x&&y==a.y) return true;
        else return false;
    }
    bool dentro(t_vetor ini, t_vetor fim) {
        if (x>=ini.x && x<=fim.x && y<=max(ini.y, fim.y) && y>=min(ini.y, fim.y)) return true;
        else return false;
    }
}t_vetor;

bool comp (t_vetor a, t_vetor b) {
    return a.x<b.x;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        vector<t_vetor> um(2), dois(2);
        scanf ("%lld%lld%lld%lld", &um[0].x, &um[0].y, &um[1].x, &um[1].y);
        scanf ("%lld%lld%lld%lld", &dois[0].x, &dois[0].y, &dois[1].x, &dois[1].y);
        // linhas coincidem
        t_vetor op1 = um[1].menos(um[0]), op2 = dois[0].menos(um[0]), op3 = dois[1].menos(um[0]);
        if (op1.cross(op2) == 0 && op1.cross(op3) == 0) {
            sort(um.begin(), um.end(), comp);
            sort(dois.begin(), dois.end(), comp);
            if ((dois[0].dentro(um[0], um[1]) || dois[1].dentro(um[0], um[1])) || (um[0].dentro(dois[0], dois[1]) || um[1].dentro(dois[0], dois[1]))) printf ("YES\n");
            else printf ("NO\n");
            continue;
        }
        // um ponto em comum
        if ((um[0].igual(dois[0]) || um[0].igual(dois[1])) || (um[1].igual(dois[0]) || um[1].igual(dois[1]))) {
            printf ("YES\n");
            continue;
        }
        // interceptam em um ponto
        t_vetor base1 = um[1].menos(um[0]), base2 = dois[1].menos(dois[0]);
        op1 = dois[0].menos(um[0]), op2 = dois[1].menos(um[0]), op3 = um[0].menos(dois[0]);
        t_vetor op4 = um[1].menos(dois[0]);
        if ((base1.cross(op1)>=0 && base1.cross(op2)<=0) || (base1.cross(op1)<=0 && base1.cross(op2)>=0)) {
            if ((base2.cross(op3)>=0 && base2.cross(op4)<=0) || (base2.cross(op3)<=0 && base2.cross(op4)>=0)) {
                printf ("YES\n");
                continue;
            }
        }
        printf ("NO\n");
    }
    return 0;
}