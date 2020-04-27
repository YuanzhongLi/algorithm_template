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

// Dinic法
// 最大流を求める。最短の増加パスを探して、そこにフローを流していくことを繰り返す。そのような経路がなくなったら残余パスでもう一度それを繰り返す。それでも、流せなくなったら終了する。
// 計算量 O(E * V^2)
// ただしほとんどの場合、実際の計算量より高速に動作する。

static const int INF = (1<<30);

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

// AOJ GRL_6_A

int main() {
  int V, E;
  cin >> V >> E;
  int u, v, c;
  Dinic d(V);
  rep(i, 0, E) {
    cin >> u >> v >> c;
    d.addEdge(u, v, c);
  }
  int ans = d.max_flow(0, V - 1);
  cout << ans << endl;
};


