#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

#define MAX 10000
#define INFTY (1 << 29)

class Unionfind {
  public:
    vector<int> par; // 節点
    vector<int> rank; // 木の高さ
    vector<int> size; // 節点が属する木の節点数
    int treeNum; // 木の数
    Unionfind(int N) : par(N), rank(N, 0), size(N, 1) {
      for (int i = 0; i < N; i++) {
        par[i] = i;
      }
      treeNum = N;
    }
    // 節点(木)追加
    void addNode(int x) {
      par[x] = x;
      rank[x] = 0;
      size[x] = 1;
      treeNum++;
    }
    // 根を探すと同時に経路上にある節点の親が根になるように代入
    int root(int x) {
      return par[x] == x ? x : par[x] = root(par[x]);
    }
    // 同じ木に属しているか
    bool same(int x, int y) {
      return root(x) == root(y);
    }
    // rankが低い方の木をrankが高い方の木の根に結びつける(結びつけた後の新しい木の高さが高くなることがないため)
    void unite(int x, int y) {
      x = root(x);
      y = root(y);
      treeNum--;
      if (x == y) {
        return;
      }
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

int Kruskal (int N, vector<Edge> edges) {
  int totalCost = 0;
  sort(All(edges));
  Unionfind uf = Unionfind(N + 1);

  int source, target;
  rep(i, 0, edges.size()) {
    Edge e = edges[i];
    if (!uf.same(e.source, e.target)) {
      totalCost += e.cost;
      uf.unite(e.source, e.target);
    }
  }

  return totalCost;
};

int main() {
  int N, M, cost;
  int source, target;

  cin >> N >> M;

  vector<Edge> edges;
  rep(i, 0, M) {
    cin >> source >> target >> cost;
    edges.pb(Edge(source, target, cost));
  }

  cout << Kruskal(N, edges) << endl;
};
