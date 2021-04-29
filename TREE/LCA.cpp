#include <bits/stdc++.h>
using namespace std;

/* LCA
 VERIFICATION: HackerRank_ysf1_G
 URL: https://www.hackerrank.com/contests/ysf1/challenges/ysf1-g/submissions/code/1324331490
*/

// <to, dist>
vector<pair<int, int>> G[200005];
class LCA {
public:
  int V, logV; // V: node num
  vector<int> depth, dist;
  vector<vector<int>> parent; // parent[k][v], go back 2^k

  LCA(int V) {
    this->V = V;
    logV = 0;
    while (V > (1LL<<logV)) logV++;
    this->depth = vector<int>(V);
    this->dist = vector<int>(V);
    this->parent = vector<vector<int>>(logV, vector<int>(V));
  }

  void init(int v, int par, int d, int l) { // dfs: calculate dist and parent
    depth[v] = d;
    parent[0][v] = par;
    dist[v] = l;
    for (int i = 0; i < (int)G[v].size(); i++) {
      int w = G[v][i].first;
      int lc = G[v][i].second;
      if (w == par) continue;
      init(w, v, d+1, lc + l);
    }
  }

  void build() { // doubling: build parent
    for (int k = 0; k + 1 < logV; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
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

  int getDistance(int u, int v) {
    int z = query(u, v);
    return dist[u] + dist[v] - 2 * dist[z];
  }
};

int main() {
  int N; cin >> N;

  for (int i = 0; i < N-1; i++) {
    int x, y, d; cin >> x >> y >> d;
    x--; y--;
    G[x].push_back(make_pair(y, d));
    G[y].push_back(make_pair(x, d));
  }

  LCA lca(N);
  lca.init(0, -1, 0, 0);
  lca.build();

  int Q; cin >> Q;
  while (Q--) {
    int x, y; cin >> x >> y;
    x--; y--;
    cout << lca.getDistance(x, y) << endl;
  }

  return 0;
};
