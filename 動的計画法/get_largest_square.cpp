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

#define MAX 1400

// Gはgridで0 or 1
int dp[MAX][MAX], G[MAX][MAX];

int getLargestSquare(int H, int W) {
  int maxWidth = 0;
  rep(i, 0, H) {
    rep(j, 0, W) {
      dp[i][j] = (G[i][j] + 1) % 2;
      maxWidth |= dp[i][j];
    }
  }

  rep(i, 1, H) {
    rep(j, 1, W) {
      if (G[i][j]) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i-1][j], dp[i][j-1])) + 1;
        maxWidth = max(maxWidth, dp[i][j]);
      }
    }
  }

  return maxWidth * maxWidth;
};

int main() {
  int H, W;
  cin >> H >> W;

  rep(i, 0, H) {
    rep(j, 0, W) {
      scanf("%d", &G[i][j]);
    }
  }

  int ans = getLargestSquare(H, W);

  cout << ans << endl;
};
