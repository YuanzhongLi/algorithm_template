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

// Ford-Fulkerson法
// 最大流を求める。増加パスをDFSで探して、そこにフローを流していくことを繰り返す。容量が無理数の場合, 有限回の操作で終了しないことがある。
// 計算量 O(F(max_flow) * E)

static const int INF = (1<<30);

// // revは残余ネットワークへの参照に使う
// // G[e.to][e.rev]で逆辺の構造体にアクセス可
// struct Edge {
//   int to, cap, rev;
// };

// 一回きり
class FordFulkerson {
  // revは残余ネットワークへの参照に使う
  // G[e.to][e.rev]で逆辺の構造体にアクセス可
  struct Edge {
    int to, cap, rev;
  };
  public:
    vector<vector<Edge>> G;
    vector<bool> used;
  FordFulkerson(int V): G(V), used(V) {}

  //辺を追加。revは,相互参照できるようにしている。sizeで実現しているが、別のルールを用いても良い(i.e ハッシュ)。逆辺の逆辺は通常の辺である。
  void addEdge(int from, int to, int cap) {
    G[from].pb((Edge) { to, cap, (int) G[to].size() });
    G[to].pb((Edge) { from, 0, (int) G[from].size() - 1}); // 逆辺
  }

  // sからtへ移動可能ならそのルートの最大流量を返し、不可能なら0を返す
  int dfs(int v, int t, int f) {
    // v == tつまりtに到達なのでその時点のfつまり流量を返す
    if (v == t) {
      return f;
    }
    used[v] = true;  // vに到達済み
    rep(i, 0,  G[v].size()) {
      Edge &e = G[v][i]; // vからでるedge
      if (!used[e.to] && e.cap > 0)  {
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

  // sからtへの最大流量を返す
  int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
      // usedを初期化
      rep(i, 0, used.size()) {
        used[i] = false;
      }

      int f = dfs(s, t, INF);
      if (f == 0) { // もう流せない
        return flow;
      }
      flow += f;
    }
  }
};

int main() {
  int V, E;
  cin >> V >> E;
  int u, v, c;
  FordFulkerson ff(V);
  rep(i, 0, E) {
    cin >> u >> v >> c;
    ff.addEdge(u, v, c);
  }
  int ans = ff.max_flow(0, V - 1);
  cout << ans << endl;
};
