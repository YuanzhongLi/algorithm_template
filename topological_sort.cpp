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

static const int MAXN = 1005;
static const int MAXV = MAXN*MAXN;
vector<int> to[MAXV]; // 隣接リスト

bool visited[MAXV];
bool calculated[MAXV];
int dp[MAXV]; // max length of path from v（vからstartしたときの最長経路）
int dfs(int v) {
  if (visited[v]) {
    if (!calculated[v]) return -1; // 閉路検出
    return dp[v];
  }
  visited[v] = true;
  dp[v] = 1;
  for (int u: to[v]) {
    int res = dfs(u);
    if (res == -1) return -1; // 閉路検出
    dp[v] = max(dp[v], res+1);
  }
  calculated[v] = true;
  return dp[v];
};

int main() {

};
