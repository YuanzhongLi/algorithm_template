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

// a + b = (a xor b) + (a & b) * 2

// cf) abc129E
static const int mod = 1e9+7;

int dp[100005][2];
// dp[i][j]
// i: 上からi桁目までみた
// j: a+bを上からi桁目までみて1: L以下であることが確定, 0: i桁目までLと一致だがL以下確定ではない

int main() {
  string s;
  cin >> s;
  int n = s.size();
  dp[0][0] = 1;
  rep(i, 0, n) {
    { // a+b = 0 (a+bの上からi桁目が0を想定)
      if (s[i] == '0') {
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
      } else { // s[i] == '1' -> L以下のみ考える, a+b = 0なので一致し得ない
        dp[i+1][1] = (dp[i][0] + dp[i][1]) % mod;
      }
    }
    { // a+b = 1 (a+bの上からi桁目が1を想定)
      if (s[i] == '0') { // dp[i][0]はL以下の条件を満たすことが不可能なので考える必要がない
        (dp[i+1][1] += dp[i][1] * 2 % mod) %= mod;
      } else {
        (dp[i+1][0] += dp[i][0] * 2 % mod) %= mod;
        (dp[i+1][1] += dp[i][1] * 2 % mod) %= mod;
      }
    }
  }

  int ans = (dp[n][0] + dp[n][1]) % mod;
  cout << ans << endl;

  return 0;
};
