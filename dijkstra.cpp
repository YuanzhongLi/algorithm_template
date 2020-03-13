#include <bits/stdc++.h>
using namespace std;

static const int MAX = 10000;
static const int INFTY = (1<<21);
static const int WHITE = 0; // 未到達
static const int GRAY = 1; // 到達
static const int BLACK = 2; // 探索済み

// <node, cost>
vector<pair<int, int>> adj[MAX]; // 重み付き有向グラフの隣接リスト表現
int color[MAX];
int d[MAX];
int p[MAX];

void dijkstra(int s) {
  // <cost, node>
  priority_queue<pair<int, int>> PQ;
  for (int i = 0; i < MAX; i++) {
    d[i] = INFTY;
    color[i] = 0;
  }

  d[s] = 0;
  PQ.push(make_pair(0, s));
  color[s] = GRAY;

  while (!PQ.empty()) {
    pair<int, int> f = PQ.top();
    PQ.pop();
    int u = f.second;
    color[u] = BLACK;

    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].first;
      if (color[v] == BLACK) continue;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        p[v] = u; // 経路を求めるために親ノードを更新
        // priority_queueはデフォルトで大きい値を優先するため-1をかける
        PQ.push(make_pair(d[v] * (-1), v));
        color[v] = GRAY;
      }
    }
  }
};
