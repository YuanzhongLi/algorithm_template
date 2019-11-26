#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)turn idx;
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

static const int MAX = 400;
static const ll INFTY = 1e15;

// N: node数, M: edge数
ll N, M;
ll dist[MAX][MAX];

// nodeAと nodeBの 距離(Cost) C
ll A[100000], B[100000], C[100000];

void input() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];
};

void floyd() {
  input();
  // 初期化
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      dist[i][j] = INFTY;
    }
    dist[i][i] = 0;
  }

  // 初期node間距離代入
  for (int i = 1; i <= M; i++) {
    chmin(dist[A[i]][B[i]], C[i]);
    chmin(dist[B[i]][A[i]], C[i]);
  }

  // フロイド法によって全点間の最短距離を算出
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        chmin(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
};

int main() {
  floyd();
  return 0;
};
