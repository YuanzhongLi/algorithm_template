#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
};

// 東京大学プログラミングコンテスト2013 H

static const ll LINF = 1ll << 55;

struct Edge {
  int from;
  int to;
  ll cost;
};

vector<ll> bellman_ford(int s, int V, vector<Edge> &edges) {
  vector<ll> dist(V, LINF);
  dist[s] = 0;
  rep(i, 0, V - 1) {
    rep(j, 0, edges.size()) {
      struct Edge e = edges[j];
      if (dist[e.from] == LINF) continue;
      dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
    }
  }

  bool flag = true;
  rep(i, 0, edges.size()) {
    struct Edge e = edges[i];
    if (dist[e.from] == LINF) continue;
    // 負回路発見
    if (dist[e.from] + e.cost < dist[e.to]) {
      flag = false;
      break;
    }
  }

  if (flag) {
    return dist;
  } else {
    vector<ll> neg;
    return neg;
  }
};

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> p(N+1);
  rep(i, 1, N+1) {
    cin >> p[i];
  }

  vector<ll> q(N+1);
  rep(i, 1, N+1) {
    cin >> q[i];
  }

  vector<Edge> edges;
  set<int> S;

  int x, y, a, b;
  int s = 0;

  rep(i, 0, M) {
    cin >> x >> y >> a >> b;
    y += N;
    edges.pb(Edge { y, x, b });
    edges.pb(Edge { x, y, -a });
    if (!(Find(S, x))) {
      edges.pb(Edge { s, x, p[x] });
      edges.pb(Edge { x, s, 0ll });
      S.insert(x);
    }
    if (!(Find(S, y))) {
      edges.pb(Edge { y, s, q[y-N] });
      edges.pb(Edge { s, y, 0ll });
      S.insert(y);
    }
  }

  int V = 2*N+1;

  auto res = bellman_ford(s, V, edges);

  if (res.empty()) {
    cout << "no" << endl;
  } else {
    cout << "yes" << endl;
  }

  return 0;
};
