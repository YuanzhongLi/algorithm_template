#include <bits/stdc++.h>
using namespace std;

class LCA {
public:
  int V, logV; // V: node num
  vector<int> depth, dist;
  vector<vector<int>> parent; // parent[k][v], go back 2^k
  vector<vector<pair<int,int>>> tree;

  LCA(vector<vector<pair<int,int>>> in_tree) {
    tree = in_tree;
    V = in_tree.size();
    logV = 0;
    while (V > (1LL<<logV)) logV++;
    this->depth = vector<int>(V);
    this->dist = vector<int>(V);
    this->parent = vector<vector<int>>(logV, vector<int>(V));
  }

  void dfs(int u, int p, int d, int c) { // dfs: calculate dist and parent
    depth[u] = d;
    parent[0][u] = p;
    dist[u] = c;
    for (int i = 0; i < (int)tree[u].size(); i++) {
      int v = tree[u][i].first;
      int cost = tree[u][i].second;
      if (v == p) continue;
      dfs(v, u, d+1, c + cost);
    }
  }

  void doubling() { // doubling: build parent
    for (int k = 0; k < logV-1; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

  void build(int u = 0, int p = -1, int d = 0, int c = 0) {
    dfs(u,p,d,c);
    doubling();
  }

  int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < logV; k++) {
      if ((depth[v] - depth[u]) >> k & 1) v = parent[k][v];
    }
    if (u == v) return u;

    for (int k = logV-1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  int get_distance(int u, int v) {
    int lca = query(u, v);
    return dist[u] + dist[v] - 2 * dist[lca];
  }
};

int main() {
  int N; cin >> N;
  vector<vector<pair<int,int>>> G(N);
  for (int i = 0; i < N-1; i++) {
    int x, y, d; cin >> x >> y >> d;
    x--; y--;
    G[x].push_back(make_pair(y, d));
    G[y].push_back(make_pair(x, d));
  }

  LCA lca(G);
  lca.build();

  int Q; cin >> Q;
  while (Q--) {
    int x, y; cin >> x >> y;
    x--; y--;
    cout << lca.get_distance(x, y) << endl;
  }

  return 0;
};
