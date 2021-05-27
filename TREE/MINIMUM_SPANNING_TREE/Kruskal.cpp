#include <bits/stdc++.h>
using namespace std;

// VERIFICATIOIN: typical90 049
// URL: https://atcoder.jp/contests/typical90/submissions/22938826

class Unionfind {
public:
  int N;
  vector<int> par; // parent
  vector<int> rank; // tree hight
  vector<int> size; // root node numbers
  int treeNum; // tree number
  Unionfind(int N) : N(N), par(N), rank(N, 0), size(N, 1) {
    for (int i = 0; i < N; i++) {
      par[i] = i;
    }
    treeNum = N;
  }
  // add node
  void addNode() {
    par.push_back(N);
    rank.push_back(0);
    size.push_back(1);
    N++;
    treeNum++;
  }
  int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return;
    }
    treeNum--;
    if (rank[x] < rank[y]) {
      par[x] = y;
      size[y] += size[x];
    } else {
      par[y] = x;
      size[x] += size[y];
      if (rank[x] == rank[y]) {
        rank[x] += 1;
      }
    }
  }

  vector<vector<int>> group() { // O(N)
    vector<vector<int>> res;
    vector<vector<int>> table(N);
    for (int i = 0; i < N; i++) {
      table[root(i)].push_back(i);
    }
    for (int i = 0; i < N; i++) {
      if (!table[i].empty()) {
        res.push_back(table[i]);
      }
    }
    return res;
  }
};

class Edge {
  public:
    int source, target, cost;
    Edge(int source = 0, int target = 0, int cost = 0):
    source(source), target(target), cost(cost) {}
    bool operator < (const Edge &e) const {
      return cost < e.cost;
    }
};

int Kruskal (int N, vector<Edge> &edges) {
  int totalCost = 0;
  sort(edges.begin(), edges.end());
  Unionfind uf = Unionfind(N);

  for (int i=0; i < edges.size(); i++) {
    Edge e = edges[i];
    if (!uf.same(e.source, e.target)) {
      totalCost += e.cost;
      uf.unite(e.source, e.target);
    }
  }

  if (uf.treeNum > 1) return -1; // can not build connected tree

  return totalCost;
};

int main() {
  int N, M, cost;
  int source, target;

  cin >> N >> M;

  vector<Edge> edges;
  for (int i=0; i < M; i++) {
    cin >> source >> target >> cost;
    edges.push_back(Edge(source, target, cost));
  }

  cout << Kruskal(N, edges) << endl;
};
