#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
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
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << "\n";
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define endl "\n"
// gcj print用
#define Case(x) printf("Case #%d: ", x);

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

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

class Matrix {
  public:
  long long r, c;
  vector<vector<long long>> mat;
  Matrix() {}
  Matrix(int r, int c, long long init=0): r(r), c(c) {
    mat.resize(r);
    for (int i=0; i<r; i++) mat[i].resize(c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] = init;
  }
  void show() {
    for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) {
        cout << mat[i][j]; if (j < c-1) cout << " ";
      }
      cout << endl;
    }
  }
  Matrix operator-() const {
    Matrix ret = Matrix(r, c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) ret.mat[i][j] *= -1;
    return ret;
  }
  Matrix& operator+=(const Matrix a) {
    assert(r == a.r && c == a.c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] += a.mat[i][j];
    return *this;
  }
  Matrix& operator+=(const int n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] += n;
    return *this;
  }
  Matrix& operator-=(const Matrix a) {
    assert(r == a.r && c == a.c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] -= a.mat[i][j];
    return *this;
  }
  Matrix& operator-=(const long long n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] -= n;
    return *this;
  }
  Matrix& operator*=(const Matrix a) {
    assert(c == a.r);
    Matrix ret = Matrix(r, a.c);
    for (int i=0; i<r; i++) for (int k=0; k<c; k++) for (int j=0; j<a.c; j++) ret.mat[i][j] += (mat[i][k] * a.mat[k][j]);
    *this = ret;
    return *this;
  }
  Matrix& operator*=(const long long n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] *= n;
    return *this;
  }
  Matrix operator+(const Matrix a) const {
    assert(r == a.r && c == a.c);
    return Matrix(*this) += a;
  }
  Matrix operator+(const long long n) const {
    return Matrix(*this) += n;
  }
  Matrix operator-(const Matrix a) const {
    assert(r == a.r && c == a.c);
    return Matrix(*this) -= a;
  }
  Matrix operator-(const long long n) const {
    return Matrix(*this) -= n;
  }
  Matrix operator*(const Matrix a) const {
    return Matrix(*this) *= a;
  }
  Matrix operator*(const long long n) const {
    return Matrix(*this) *= n;
  }
};

Matrix POWMAT(Matrix a, long long n) {
  assert(a.r == a.c);
  Matrix ret = Matrix(a.r, a.r);
  for (int i=0; i<a.r; i++) ret.mat[i][i] = 1ll;
  while (n > 0) {
    if (n & 1ll) ret *= a;
    a *= a; n >>= 1;
  }
  return ret;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Matrix mat = Matrix(10, 10, 0);
  rep(i, 0, 10) {
    mat.mat[i][i] = 2;
    if (i > 0) mat.mat[i][i-1] = 1;
  }

  POWMAT(mat, 10).show();

  return 0;
};
