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

int main() {
  string s, t;
  cin >> s >> t;
  int sizes = s.size();
  int sizet = t.size();

  vector<vector<int>> dp(3001, vector<int> (3001));

  rep(i, 0, sizes) {
    char x = s[i];
    rep(j, 0, sizet) {
      char y = t[j];
      if (x == y) {
        dp[i+1][j+1] = dp[i][j]+1;
      } else {
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }
  }

  string ans;
  int i = sizes, j = sizet;
  while(true) {
    if (i == 0 || j == 0) break;
    if (dp[i][j] == dp[i-1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      i--;
      j--;
      ans+=s[i];
    }
  }

  reverse(All(ans));

  cout << ans << endl;
};
