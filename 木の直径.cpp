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

#define MAX 100000
#define INFTY (1 << 30)
class Edge {
public:
  int t, w;
  Edge() {}
  Edge(int t, int w): t(t), w(w) {}
};

vector<Edge> G[MAX];
int n, d[MAX];

bool vis[MAX];
int cnt;

void bfs(int s) {
  rep(i, 0, n) d[i] = INFTY;
  queue<int> Q;
  Q.push(s);
  d[s] = 0;
  int u;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    rep(i, 0, G[u].size()) {
      Edge e = G[u][i];
      if (d[e.t] == INFTY) {
        d[e.t] = d[u] + e.w;
        Q.push(e.t);
      }
    }
  }
};

void solve() {
  // 適当な始点sからもっとも遠い点tgtを求める
  bfs(0);
  int maxv = 0;
  int tgt = 0;
  rep(i, 0, n) {
    if (d[i] == INFTY) continue;
    if (maxv < d[i]) {
      maxv = d[i];
      tgt = i;
    }
  }

  // tgtからもっとも遠い点の距離maxvを求める
  bfs(tgt);
  maxv = 0;
  rep(i, 0, n) {
    if (d[i] == INFTY) continue;
    maxv = max(maxv, d[i]);
  }
  cout << maxv << endl;
};

int main() {
  int s, t, w;
  cin >> n;
  rep(i, 0, n - 1) {
    cin >> s >> t >> w;
    G[s].pb(Edge(t, w));
    G[t].pb(Edge(s, w));
  }
  solve();
};
