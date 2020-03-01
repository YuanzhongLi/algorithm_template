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
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)


// ます目の入力を想定
/**
 * 3 5
 * ##..#
 * .#...
 * .###.
 */
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H+2, vector<char> (W+2, '#'));
  string S;
  rep(i, 1, H+1) {
    cin >> S;
    rep(j, 1, W+1) {
      grid[i][j] = S[j - 1];
    }
  }

  int INF = (int) 1e9+7;

  vector<vector<int>> dist(H*W, vector<int> (H*W, INF));
  vector<vector<int>> list(H*W);
  int x, y, v;
  rep(i, 0, H) {
    x = i + 1;
    rep(j, 0, W) {
      y = j + 1;
      v = i * W + j;

      if (grid[x][y] != '.') {
        continue;
      }

      dist[v][v] = 0;
      if (grid[x][y-1] == '.') { // left
        list[v].pb(v-1);
        list[v-1].pb(v);
        dist[v][v-1] = 1;
        dist[v-1][v] = 1;
      }

      if (grid[x-1][y] == '.') { // up
        list[v].pb(v-W);
        list[v-W].pb(v);
        dist[v][v-W] = 1;
        dist[v-W][v] = 1;
      }

      if (grid[x][y+1] == '.') { // right
        list[v].pb(v+1);
        list[v+1].pb(v);
        dist[v][v+1] = 1;
        dist[v+1][v] = 1;
      }

      if (grid[x+1][y] == '.') { // down
        list[v].pb(v+W);
        list[v+W].pb(v);
        dist[v][v+W] = 1;
        dist[v+W][v] = 1;
      }
    }
  }
}
