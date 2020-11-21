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
// 左づめでの10進数xをdigits桁のN進数vectorにしてを返す
vector<int> baseNumber(int N, int digits, int x) {
  vector<int> ret(digits, 0);
  // 商
  int quotient = x;
  int counter = 0;
  while (quotient > 0) {
    // 余り
    int remainder = quotient % N;
    quotient /= N;
    ret[counter] = remainder;
    counter++;
  }

  return ret;
};

// 左づめでの10進数xをdigits桁のN進数vectorにしてを返す
vector<int> baseNumberLL(ll N, int digits, ll x) {
  vector<int> ret(digits, 0);
  // 商
  ll quotient = x;
  int counter = 0;
  while (quotient) {
    // 余り
    ll remainder = quotient % (int)N;
    quotient /= N;
    ret[counter] = (int)remainder;
    counter++;
  }

  return ret;
};

// 0からn-1までのN進数を上記のbaseNumberで返したvectorのvector
vector<vector<int>> baseNumbers(int n, int N, int digits) {
  vector<vector<int>> ret(n, vector<int> (digits));
  for (int i = 0; i < n; i++) {
    ret[i] = baseNumber(N, digits, i);
  }

  return ret;
};

vi Str2Int(string &s) {
  vi ret(s.size());
  rep(i, 0, s.size()) {
    ret[i] = (int)s[i] - '0';
  }
  return ret;
};

// xの先頭
int top(int x) {
  int ret = 0;
  while (x) {
    ret = x;
    x /= 10;
  }
  return ret;
};

int main() {
  cout << "baseNumber result" << endl;
  vector<int> a;
  a = baseNumber(3, 10, 65);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
  }
  cout << endl;

  cout << "baseNumber result end." << endl;
  cout << "----------------------" << endl;

  cout << "baseNumber result" << endl;
  vector<vector<int>> b = baseNumbers(14, 3, 5);
  for (int i = 0; i < 14; i++) {
    for (int j = 0; j < 5; j++) {
      cout << b[i][j];
    }
    cout << endl;
  }

  cout << "baseNumbers result end." << endl;
  cout << "----------------------" << endl;
};
