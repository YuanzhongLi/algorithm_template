#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
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

#define N 3
#define N2 9

struct Puzzle {
  int f[N2];
  int space;
  string path;
  bool operator < (const Puzzle &p) const {
    rep(i, 0, N2) {
      if (f[i] == p.f[i]) continue;
      return f[i] > p.f[i];
    }
    return false;
  }
};

static const int dx[4] = { -1, 0, 1, 0};
static const int dy[4] = { 0, -1, 0, 1};
static const char dir[4] = { 'u', 'l', 'd', 'r'}; // up, left, down, right

bool isTarget(Puzzle p) {
  rep(i, 0, N2) {
    if (p.f[i] != (i+1)) {
      return false;
    }
  }
  return true;
};

string bfs(Puzzle s) {
  queue<Puzzle> Q;
  map<Puzzle, bool> V;
  Puzzle u, v;
  s.path = "";
  Q.push(s);
  V[s] = true;

  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    if (isTarget(u)) return u.path;
    int sx = u.space / N; // row
    int sy = u.space % N; // column

    rep(r, 0, 4) {
      // tx, ty 交換する先のrow, column
      int tx = sx + dx[r];
      int ty = sy + dy[r];
      if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;

      v = u;
      swap(v.f[u.space], v.f[tx * N + ty]);
      v.space = tx * N + ty;
      if (!V[v]) {
        V[v] = true;
        v.path += dir[r];
        Q.push(v);
      }
    }
  }

  return "unsolvable";
};

int main() {
  Puzzle in;
  rep(i, 0, N2) {
    cin >> in.f[i];

    if (in.f[i] == 0) {
      in.f[i] = N2; // set space
      in.space = i;
    }
  }

  string ans = bfs(in);
  cout << ans.size() << endl;
};
