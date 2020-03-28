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

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

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

/* 問題文
  n種類の品物があってi番目の品物はai個ある。
  異なる種類の品物同士は区別されるが,同じ種類の品物同士は区別できない。
  これらの品物の中からm個選ぶ組み合わせの総数を求めmodで割ったあまりを答えよ。
*/

/* 制約
  1 <= n <= 1000
  1 <= m <= 1000
  1 <= ai <= 1000
  2 <= mod <= 10000
*/

/* 考え方
  dp[i+1][j]: i番目までの品物からj個選ぶ組み合わせの総数
  dp[i+1][j] = Σ(min(j, a[i]), k=0) dp[i][j - k]
  このままだとO(nm^2)となる
  dp[i+1][j-1] = Σ(min(j-1, a[i]), k=0) dp[i][j - k - 1]を考える
*/

static const int MAX_N = 1000;
static const int MAX_M = 1000;
int n, m, mod;
int a[MAX_N];

int dp[MAX_N+1][MAX_M+1];

int solve() {
  // 一つも選ばない方法は常に一通り
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  rep(i, 0, n) { // 0番目の品物スタートでn-1番目の品物エンドのn種類の品物
    rep(j, 1, m+1) {
      if (j - 1 - a[i] >= 0) {
        // 負になり得るときは常に足してからmodを考える
        dp[i+1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + mod) % mod;
      } else {
        dp[i+1][j] = (dp[i+1][j-1]+dp[i][j]) % mod;
      }
    }
  }
  return dp[n][m];
};

int main() {
};
