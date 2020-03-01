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

struct Rect { int height; int pos; };

// ヒストグラムから最大長方形面積を取得
int getLargestRect(int size, int buffer[]) {
  stack<Rect> S;
  int maxv = 0;
  buffer[size] = 0;

  rep(i, 0, size+1) {
    Rect rect;
    rect.height = buffer[i];
    rect.pos = i;
    if (S.empty()) {
      S.push(rect);
    } else {
      if (S.top().height < rect.height) {
        S.push(rect);
      } else if (S.top().height > rect.height) {
        int target = i;
        while (!S.empty() && S.top().height >= rect.height) {
          Rect pre = S.top(); S.pop();
          int area = pre.height * (i - pre.pos);
          maxv = max(maxv, area);
          target = pre.pos;
        }

        rect.pos = target;
        S.push(rect);
      }
    }
  }

  return maxv;
};

int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];

int solve() {
  rep(j, 0, W) {
    rep(i, 0, H) {
      if (buffer[i][j]) {
        T[i][j] = 0;
      } else {
        T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
      }
    }
  }

  int ret = 0;

  rep(i, 0, H) {
    ret = max(ret, getLargestRect(W, T[i]));
  }

  return ret;
};

int main() {
  scanf("%d %d", &H, &W);

  rep(i, 0, H) {
    rep(j, 0, W) {
      scanf("%d", &buffer[i][j]);
    }
  }
  int ans = solve();
  cout << ans << endl;
};
