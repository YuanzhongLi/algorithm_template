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

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

static const int INF = 1e9+7;
static const int MAX_V = 1000;
int cost[MAX_V][MAX_V];
int mincost[MAX_V]; // 集合Xからの辺の最小コスト
bool used[MAX_V]; // 頂点iがXに含まれるか
int V;
// O(V * E)
int Prim() {
  // 初期化
  rep(i, 0, V) {
    mincost[i] = INF;
    used[i] = false;
  }

  mincost[0] = 0;
  int res = 0;
  while (true) {
    int v = -1;
    // Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
    rep(u, 0, V) {
      if (!used[u] && (v == -1 || mincost[u] < mincost[v])) {
        v = u;
      }
    }

    if (v == -1) break;
    used[v] = true;
    res += mincost[v];

    rep(u, 0, V) {
      mincost[u] = min(mincost[u], cost[v][u]);
    }
  }

  return res;
};

int main() {

  return 0;
};
