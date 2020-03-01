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

#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2 * N - 1], dneg[2* N - 1];

bool X[N][N];

void initialize() {
  rep(i, 0, N) {
    row[i] = FREE; col[i] = FREE;
  }
  rep(i, 0, 2*N-1) {
    dpos[i] = FREE; dneg[i] = FREE;
  }
};

void printBoard() {
  rep(i, 0, N) {
    rep(j, 0, N) {
      if (X[i][j]) {
        if (row[i] != j) return;
      }
    }
  }

  rep(i, 0, N) {
    rep(j, 0, N) {
      cout << ((row[i] == j) ? "Q" : ".");
    }
    cout << endl;
  }
};

void recursive(int i) {
  if (i == N) { // クイーンの配置に成功
    printBoard();
    return;
  }

  rep(j, 0, N) {
    // (i, j)が他のクイーンに襲撃されている場合は無視
    if (
      NOT_FREE == col[j] ||
      NOT_FREE == dpos[i+j] ||
      NOT_FREE == dneg[i - j + N - 1]
    ) continue;

    // (i, j)にクイーンを配置する
    row[i] = j;
    col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
    // 次の行を試す
    recursive(i+1);
    // (i, j)に配置されているクイーンを取り除く
    row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
  }

  // クイーンの配置に失敗
};

int main() {
  initialize();

  rep(i, 0, N) {
    rep(j, 0, N) X[i][j] = false;
  }

  int k;
  cin >> k;
  rep(i, 0, k) {
    int r, c;
    cin >> r >> c;
    X[r][c] = true;
  }

  recursive(0);

  return 0;
};
