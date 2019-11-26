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

// PrimalDual法
/*
最小費用流を最短路反復で解くアルゴリズム。始点から終点までの重みの最短路を求め、そこに流せる限り流す。これを流したい分だけ流しきるまで繰り返す。
最短路の計算は、ポテンシャル h を用いて負辺がないように変換して Dijkstra法 で求める。
*/

// 計算量 O(F * E * logV)

static const int INF = (1<<30);

struct PrimalDual {
  struct edge {
    int to, cap, cost, rev;
  };

  vector<vector<edge>> G;
  vector<int> potential, min_cost;
  vector<int> prevv, preve;

  PrimalDual(int V): G(V) {}

  void add_edge(int from ,int to, int cap, int cost) {
    G[from].pb((edge) { to, cap, cost, (int) G[to].size() });
    // capそのままでcostをマイナスにする
    G[to].pb((edge) { from, 0, -cost, (int) G[from].size()-1 });
  }

  int min_cost_flow(int s, int t, int f) {
    int V = (int) G.size();
    int ret = 0;
    // <cost, node番号>
    using Pi = pair<int, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    // potentialを0で初期化
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);

    while (f > 0) {
      min_cost.assign(V, INF);
      // 始点追加
      que.push(make_pair(0, s));
      min_cost[s] = 0;
      while (!que.empty())  {
        Pi p = que.top();
        que.pop();
        // 次のノード番号までのコストがそもそもp.firstより小さいのでskip
        if (min_cost[p.second] < p.first) continue;
        // 次のノードから出ている全エッジに対して
        rep(i, 0, G[p.second].size()) {
          edge &e = G[p.second][i];
          // このエッジを採用した時のノードe.toへのコスト
          int nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if (e.cap > 0 && min_cost[e.to] > nextCost) {
            // 最小コストをupdate
            min_cost[e.to] = nextCost;
            // e.toの一つ前のノードはp.second
            prevv[e.to] = p.second;
            // e.toへのエッジはp.secondのi番目のエッジ
            preve[e.to] = i;
            // G[prevv[e.to]][preve[e.to]]でe.toに至るエッジを検出可
            // <次のnodeまでのcost, 次のnode番号>をpush
            que.push(make_pair(min_cost[e.to], e.to));
          }
        }
      }
      // そもそも与えられたフローでtへ到達不能-1を返す
      if (min_cost[t] == INF) return -1;

      rep(v, 0, V) {
        potential[v] += min_cost[v];
      }
      int add_flow = f;
      // sからtまでの中で最小の容量のエッジを検出
      for (int v = t; v != s; v = prevv[v]) {
        add_flow = min(add_flow, G[prevv[v]][preve[v]].cap);
      }
      f -= add_flow;
      ret += add_flow * potential[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= add_flow;
        G[v][e.rev].cap += add_flow;
      }
    }

    return ret;
  }
};

int main() {
  int V, E, F;
  cin >> V >> E >> F;
  int u, v, c, d;
  struct PrimalDual pd(V);
  rep(i, 0, E) {
    cin >> u >> v >> c >> d;
    pd.add_edge(u, v, c, d);
  }

  int ans = pd.min_cost_flow(0, V - 1, F);
  cout << ans << endl;
};
