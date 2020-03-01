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
#define LIMIT 100

static const int dx[4] = { 0, -1, 0, 1};
static const int dy[4] = { 1, 0, -1, 0};
static const char dir[4] = { 'r', 'u', 'l', 'd'};

int MDT[N2][N2]; // マンハッタン距離テーブル

struct Puzzle {
  int f[N2], space, MD; // MD: マンハッタン距離
};

Puzzle state;
int limit;
int path[LIMIT];

int getAllMD(Puzzle pz) {
  int sum = 0;
  rep(i, 0, N2) {
    if (pz.f[i] == N2) continue;
    sum += MDT[i][pz.f[i]-1];
  }
  return sum;
};

bool isSolved() {
  rep(i, 0, N2) {
    if (state.f[i] != i+1) return false;
  }
  return true;
};

bool dfs(int depth, int prev) {
  if (state.MD == 0) return true;
  // 現在の深さにヒューリスティックを足して制限を超えたら枝を刈る
  if (depth + state.MD > limit) return false;

  int sx = state.space / N;
  int sy = state.space % N;
  Puzzle tmp;

  rep(r, 0, 4) {
    int tx = sx + dx[r];
    int ty = sy + dy[r];
    if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
    if (max(prev, r) - min(prev, r) == 2) continue; // '左右'、'上下'入れ替えのよな元の状態の探索を防ぐ
    tmp = state;
    // マンハッタン距離の差分を計算しつつ、ピースをスワップ
    state.MD -= MDT[tx * N + ty][state.f[tx * N + ty] - 1];
    state.MD += MDT[sx * N + sy][state.f[tx * N + ty] - 1];
    swap(state.f[tx * N + ty], state.f[sx * N + sy]);
    state.space = tx * N + ty;
    if (dfs(depth + 1, r)) {
      path[depth] = r;
      return true;
    }
    state = tmp;
  }
  return false;
};

// 反復深化
string iterative_deepening(Puzzle in) {
  in.MD = getAllMD(in);

  for (limit = in.MD; limit <= LIMIT; limit++) {
    state = in;
    if (dfs(0, -100)) {
      string ans = "";
      rep(i, 0, limit) ans += dir[path[i]];
      return ans;
    }
  }

  return "unsolvable";
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

  string ans = iterative_deepening(in);

  cout << ans.size() << endl;

  return 0;
};
