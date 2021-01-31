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

// AOJ DPL_2_A
// url: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/2/DPL_2_A

const int MAX_N = 15;
const int INF = 1e9+7;
vvi dist(MAX_N, vi(MAX_N, INF));
vvi dp(1 << MAX_N, vi (MAX_N, INF)); // dp[<すでに到達した場所のbit>][現在いる場所]

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int V, E;
  cin >> V >> E;
  int s, t, d;
  rep(i, 0, E) {
    cin >> s >> t >> d;
    dist[s][t] = d;
  }

  for (int i=0; i<V; i++) dp[(1<<V)-1][i] = 0;
  for (int S = (1 << V) - 2; S >= 0; S--) {
    rep(v, 0, V) {
      rep(u, 0, V) {
        if (!((S >> u) & 1)) { // まだ訪れてない点
          dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + dist[v][u]);
        }
      }
    }
  }

  if (dp[0][0] == INF) {
    cout << -1 << endl;
  } else {
    cout << dp[0][0] << endl;
  }

  return 0;
};
