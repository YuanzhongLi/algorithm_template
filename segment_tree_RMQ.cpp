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
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示

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

/* O(log n)
  - 与えられた区間での最小値を求める
  - 一つの要素の値の変更
*/

static const int MAX_N = 1 << 17;

// セグメント気を持つグローバル配列
int n, dat[2 * MAX_N - 1];

// 初期化 n_個のの要素
void init(int n_) {
  // 簡単のため、要素数を2のべき乗に
  n = 1;
  while (n < n_) {
    n *= 2;
  }

  rep(i, 0, 2 * n - 1) dat[i] = INT_MAX;
};

// k番目の値をaに変更
void update(int k, int a) {
  // 葉の節点
  k += n - 1; //根を0番目としたときの節点番号
  dat[k] = a;
  // 登りながら更新
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
};

// [a, b)区間の最小値を求める
// 後ろの方の引数は計算の簡単のための引数
// kは接点の番号、l, rはその節点が[l, r)に対応づいていることを表す
// したがって、外からはquery(a, b, 0, 0, n)として呼ぶ
int query(int a, int b, int k, int l, int r) {
  // 交差なし
  if (r <= a || b <= l) {
    return INT_MAX;
  }

  // [a, b) が[l, r)を完全に含んでいる場合
  if (a <= l && r <= b) {
    return dat[k];
  } else {
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
};

int main() {
  int n_, q;
  cin >> n_ >> q;
  init(n_);

  int com, x, y;
  rep(i, 0, q) {
    cin >> com >> x >> y;
    if (com == 0) {
      update(x, y);
    }
    if (com == 1) {
      cout << query(x, y+1, 0, 0, n) << endl;
    }
  }

  return 0;
};
