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
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)

template<class T>
inline bool chmax(T &a, T b) { if(a<b) { a=b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a>b) { a=b; return true; } return false; };


// VERIFICATIOIN: ABC 61_D
// URL: https://atcoder.jp/contests/abc061/submissions/21452609

// 単一始点全点間最短路を求めるアルゴリズム。単一始点全点間最短路を求めるアルゴリズム。負辺があっても動作する。また負閉路も検出する。
// 計算量 O(V * E)

constexpr int INF = 1002003004;

struct Edge {
  int from, to, cost;
};

tuple<vector<int>, vector<bool>, bool> bellman_ford(int s, int V, vector<Edge> &edges) {
  vector<int> dist(V, INF);
  dist[s] = 0;
  rep(i, 0, V - 1) {
    rep(j, 0, edges.size()) {
      struct Edge e = edges[j];
      if (dist[e.from] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
    }
  }

  vector<bool> neg(V, false);

  bool flag = false; // has negative loop
  rep(i, 0, edges.size()) {
    struct Edge e = edges[i];
    if (dist[e.from] == INF) continue;
    // detect negative loop
    if (dist[e.from] + e.cost < dist[e.to]) {
      dist[e.to] = dist[e.from] + e.cost;
      neg[e.to] = true;
      flag = true;
    }

    if (neg[e.from]) neg[e.to] = true;
  }

  return {dist, neg, flag};
};
