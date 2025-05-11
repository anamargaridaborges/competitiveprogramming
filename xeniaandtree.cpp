#include <bits/stdc++.h>
#define MAXN (int)(2e5+10)

using namespace std;

vector<int> adj[MAXN];
vector<int> centroid_tree[MAXN];
int is_removed[MAXN];
int subtree_size[MAXN];
int ans[MAXN], pai[MAXN];
int tin[MAXN], tout[MAXN], t;
int anc[MAXN][20];
int nivel[MAXN];
 
bool ancestral (int d, int a) {
    if (tin[d]>tin[a] && tout[d]<tout[a]) return true;
    else return false;
}
 
void dfs (int x) {
    tin[x] = ++t;
    for (int i=0; i<(int)adj[x].size(); i++) {
        int at = adj[x][i];
        if (tin[at]==0) {
            nivel[at] = nivel[x]+1;
            anc[at][0] = x;
            dfs(at);
        }
    }
    tout[x] = ++t;
    return;
}
 
int lca (int x, int y) {
    if (x==y) return x;
    if (ancestral(x, y)==true) return y;
    if (ancestral(y, x)==true) return x;
    if (nivel[y]>nivel[x]) swap(x, y);
    int cont = 19;
    while (cont>=0) {
        if (ancestral(y, anc[x][cont]) == false) x = anc[x][cont];
        cont--;
    } 
    return anc[x][0];
}

int get_subtree_size(int node, int parent = -1) {
	subtree_size[node] = 1;
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) continue;
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1) {
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) continue;
		if (subtree_size[child] * 2 > tree_size) {
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

int build_centroid_decomp(int node = 0) {
	int centroid = get_centroid(node, get_subtree_size(node));

	is_removed[centroid] = 1;

	for (int child : adj[centroid]) {
		if (is_removed[child]) continue;
		int child_centroid = build_centroid_decomp(child);
        centroid_tree[centroid].push_back(child_centroid);
        centroid_tree[child_centroid].push_back(centroid);
        pai[child_centroid] = centroid;
	}

    return centroid;
}

void print_centroid (int node, int parent = -1) {
    cout<<node<<": ";
    for (int child : centroid_tree[node]) {
        cout<<child<<' ';
    }
    cout<<endl;
    for (int child : centroid_tree[node]) {
        if (child != parent) print_centroid(child, node);
    }
} 

void paint (int at, int node) {
    int dist = nivel[at] + nivel[node]-2*nivel[lca(at, node)];
    ans[at] = min(ans[at], dist);
    if(pai[at] == -1) return;
    paint(pai[at], node);
}

int query (int at, int node) {
    int dist = nivel[at] + nivel[node]-2*nivel[lca(at, node)];
    if (pai[at] == -1) return ans[at] + dist;
    int ans_anc = query(pai[at], node);
    return min(ans_anc, ans[at]+dist);
}

int main () {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    anc[1][0] = 1;
    for (int i=1; i<20; i++) {
        for (int j=1; j<=n; j++) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
    int root = build_centroid_decomp(1);
    pai[root] = -1;
    for (int i=1; i<=n; i++) ans[i] = 1e9;
    paint(1, 1);
    while (m--) {
        int t, x;
        cin>>t>>x;
        if (t==1) {
            paint(x, x);
        }
        else {
            cout<<query(x, x)<<endl;
        }
    }
    return 0;
}