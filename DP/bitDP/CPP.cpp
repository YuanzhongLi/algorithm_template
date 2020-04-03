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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;
#define debug(x) cerr << #x << ": " << (x) << "\n";

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
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(ll x, int n) {
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

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

// AOJ DPL_2_B
// 無向中国人郵便配達問題
/*
  グラフがオイラー閉路を持つならばそれが答え
  そうでないならグラフに出来るだけ短い辺を追加してオイラー補完する
  向こうグラフでオイラー路を持つ必要十分条件は奇点がないこと
  よってグラフの奇点間の最短経路長を長さとするような完全グラフを作成する
  この上で最小重みマッチングを求め、得られたマッチングに対応する最短経路を元のグラフに足せば
  最小オイラー補完となる
*/

const int MAX_N = 15;
const int INF = 1e9+7;
vvi dist(MAX_N, vi(MAX_N, INF));
vvi dp(1 << MAX_N, vi (MAX_N, INF));
vpi graph[MAX_N];
int V;

int ChinesePostman() {
  int total = 0;
  vi odds;
  rep (u, 0, V) {
    for (auto pi: graph[u]) {
      total += pi.first;
    }
    if (graph[u].size() % 2 == 1) odds.pb(u);
  }
  total /= 2; // 2回ずつカウントしているため

  int n = odds.size();
  int N = 1 << n;
  int w[n][n]; // 奇数点間の最短距離

  rep(u, 0, n) {
    int s = odds[u];
    vi dist(V, INF);
    dist[s] = 0;
    vector<bool> visited(V, false);
    priority_queue<PI> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
      auto pi = pq.top(); pq.pop();
      int c = -pi.first;
      int v = pi.second;
      if (visited[v]) continue;
      visited[v] = true;
      for (auto pi2: graph[v]) {
        int c2 = pi2.first;
        int v2 = pi2.second;
        if (visited[v2]) continue;
        if (dist[v2] > dist[v] + c2) {
          dist[v2] = dist[v] + c2;
          pq.push(make_pair(-1*dist[v2] ,v2));
        }
      }
    }
    rep(v, 0, n) w[u][v] = dist[odds[v]];
  }

  vi dp(N, INF);
  dp[0] = 0;

  rep(S, 0, N) {
    // i番目の奇点とj番目の奇点が最短経路で結ばれてなく、
    // その二つを結ぶとしたときの最小コストを更新
    rep(i, 0, n) {
      if (!(S >> i & 1)) {
        rep(j, i+1, n) {
          if (!(S >> j & 1)) {
            dp[S | (1 << i) | (1 << j)] = min(dp[S | (1 << i) | (1 << j)], dp[S]+w[i][j]);
          }
        }
      }
    }
  }

  return total + dp[N-1];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int E;
  cin >> V >> E;
  int s, t, d;
  rep(i, 0, E) {
    cin >> s >> t >> d;
    graph[s].pb(make_pair(d, t));
    graph[t].pb(make_pair(d, s));
  }

  cout << ChinesePostman() << endl;

  return 0;
};
