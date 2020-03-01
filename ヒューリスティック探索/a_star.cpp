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

#define N 4
#define N2 16

static const int dx[4] = { 0, -1, 0, 1};
static const int dy[4] = { 1, 0, -1, 0};
static const char dir[4] = { 'r', 'u', 'l', 'd'};
int MDT[N2][N2];

struct Puzzle {
  int f[N2], space, MD;
  int cost;

  bool operator < (const Puzzle &p) const {
    rep(i, 0, N2) {
      if (f[i] == p.f[i]) continue;
      return f[i] < p.f[i];
    }
    return false;
  }
};

struct State {
  Puzzle puzzle;
  int estimated;
  bool operator < (const State &s) const {
    return estimated > s.estimated;
  }
};

int getAllMD(Puzzle pz) {
  int sum = 0;
  rep(i, 0, N2) {
    if (pz.f[i] == N2) continue;
    sum += MDT[i][pz.f[i] - 1];
  }
  return sum;
};

int astar(Puzzle s) {
  priority_queue<State> PQ;
  s.MD = getAllMD(s);
  s.cost = 0;
  map<Puzzle, bool> V;
  Puzzle u, v;
  State initial;
  initial.puzzle = s;
  initial.estimated = getAllMD(s);
  PQ.push(initial);

  while (!PQ.empty()) {
    State st = PQ.top(); PQ.pop();
    u = st.puzzle;

    if (u.MD == 0) return u.cost;
    V[u] = true;

    int sx = u.space / N;
    int sy = u.space % N;
    rep(r, 0, 4) {
      int tx = sx + dx[r];
      int ty = sy + dy[r];
      if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
      v = u;

      v.MD -= MDT[tx * N + ty][v.f[tx * N + ty] - 1];
      v.MD += MDT[sx * N + sy][v.f[tx * N + ty] - 1];

      swap(v.f[sx * N + sy], v.f[tx * N + ty]);
      v.space = tx * N + ty;
      if (!V[v]) {
        v.cost++;
        State news;
        news.puzzle = v;
        news.estimated = v.cost + v.MD;
        PQ.push(news);
      }
    }
  }
  return -1;
};

int main() {
  rep(i, 0, N2) {
    rep(j, 0, N2) {
      MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
    }
  }

  Puzzle in;
  rep(i, 0, N2) {
    cin >> in.f[i];
    if (in.f[i] == 0) {
      in.f[i] = N2;
      in.space = i;
    }
  }

  cout << astar(in) << endl;

  return 0;
};
