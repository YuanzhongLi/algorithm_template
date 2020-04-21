#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << "\n";
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define endl "\n"
// gcj print用
#define Case(x) printf("Case #%d: ", x);

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
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

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

const int INF = 1e9+7;

class Dinic {
  struct Edge {
    int to, cap, rev;
  };

  public:
    int V;
    vector<vector<Edge>> G;
    vector<int> level; // sからの距離
    vector<bool> used;
  Dinic(int V): V(V), G(V), used(V) {}

  void addEdge(int from, int to, int cap) {
    G[from].pb((Edge){ to, cap, (int) G[to].size() });
    G[to].pb((Edge) { from, 0, (int) G[from].size()-1 });
  }
  // sからの到達するのにかかる最短のステップ数をbfsで調べる
  void bfs(int s) {
    level.assign(V, -1); // level 初期化
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto &e: G[v]) {
        // level[e.to] == -1つまり未"発見"
        // 距離が増加する向きの辺のみからなるグラフを作成
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }

  int dfs(int v, int t, int f) {
    if (v == t) return f;

    used[v] = true;
    rep (i, 0, G[v].size()) {
      Edge &e = G[v][i];
      // 容量ありでかつ辺の先はより遠い
      if (e.cap > 0 && level[v] < level[e.to] && !used[e.to]) {
        int d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }

    return 0;
  }

  int max_flow(int s, int t) {
    int ret = 0, f;
    while (bfs(s), level[t] >= 0)  {
      used.assign(V, false);
      while ((f = dfs(s, t, INF)) > 0) {
        ret += f;
      }
    }
    return ret;
  }
};

// AOJ GRL_7_A

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int X, Y, E; cin >> X >> Y >> E;

  Dinic dinic(X+Y+2);
  int x, y;
  int s = X+Y, t = X+Y+1;
  rep(i, 0, E) {
    cin >> x >> y;
    dinic.addEdge(x, y+X, 1);
  }

  rep(x, 0, X) {
    dinic.addEdge(s, x, 1);
  }

  rep(y, 0, Y) {
    dinic.addEdge(y+X, t, 1);
  }

  cout << dinic.max_flow(s, t) << endl;

  return 0;
};
