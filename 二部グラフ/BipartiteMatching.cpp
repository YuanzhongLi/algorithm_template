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

static const int INF = (1<<30);

struct Dinic {
  // icapは元々の容量でcapと比較することでmatchingがどれかわかる
  struct Edge {
    int to, cap, icap, rev;
  };

  int V;
  vector<vector<Edge>> G;
  vector<int> level;
  vector<bool> used;

  Dinic(int V): V(V), G(V) {}

  void add_edge(int from, int to, int cap) {
    G[from].pb((Edge){ to, cap, cap, (int) G[to].size() });
    G[to].pb((Edge) { from, 0, 0, (int) G[from].size()-1 });
  }
  // sからの到達するのにかかる最短のステップ数を調べるbfsで調べる
  void bfs(int s) {
    level.assign(V, -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto &e: G[v]) {
        // level[e.to] == -1つまり未"発見"
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

  // xは片方のnodeの数
  vector<pair<int, int>> matching_pair(int s, int t, int x) {
    vector<pair<int, int>> ret;
    int match = max_flow(s, t);
    rep(i, 0, x) {
      for (auto e: G[i]) {
        if (e.cap == 0 && e.icap == 1) {
          ret.pb(make_pair(i, e.to));
        }
      }
    }
    return ret;
  }
};

int main() {
  int X, Y, E;
  cin >> X >> Y >> E;
  int supernode_S = X + Y;
  int supernode_T = X + Y + 1;
  int x, y;
  // supernode S, Tを追加
  int V = X + Y + 2;
  struct Dinic dinic(V);
  rep(i, 0, E) {
    cin >> x >> y;
    dinic.add_edge(x, y + X, 1);
  }
  rep(i, 0, X) {
    x = i;
    dinic.add_edge(supernode_S, x, 1);
  }
  rep(i, 0, Y) {
    y = i + X;
    dinic.add_edge(y, supernode_T, 1);
  }
  int ans = dinic.max_flow(supernode_S, supernode_T);
  cout << ans << endl;
};
