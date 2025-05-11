#include <bits/stdc++.h>
#define MAXN (int)(2e5+10)

using namespace std;

vector<int> adj[MAXN];
vector<int> centroid_tree[MAXN];
int is_removed[MAXN];
int subtree_size[MAXN];
int pai[MAXN];
char ans[MAXN];

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

void solve (int node, int parent, char corresp) {
    ans[node] = corresp;
    for (int child : centroid_tree[node]) {
        if (child == parent) continue;
        solve(child, node, corresp+1);
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = build_centroid_decomp(1);
    pai[root] = -1;
    solve(root, -1, 'A');
    for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}