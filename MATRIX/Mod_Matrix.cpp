#define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n; i > (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
// #define M_PI 3.14159265358979323846 // CF
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // print Decimal number 10 Rank
#define endl "\n"
#define Case(x) printf("Case #%d: ", x); // gcj

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;

constexpr ll INF = 1001002003004005006ll;
constexpr int n_max = 2e5+10;

template<class T>
inline bool chmax(T &a, T b) { if(a<b) { a=b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a>b) { a=b; return true; } return false; };

template<class T, class U>
T POW(T x, U n) {T ret=1; while (n>0) {if (n&1) {ret*=x;} x*=x; n>>=1;} return ret;};

// debug
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';};
string to_string(const char c) {return to_string((string) &c);};
string to_string(bool b) {return (b ? "true" : "false");};
template <size_t N>
string to_string(bitset<N> v){
  string res = "";
  for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
};
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for(const auto &x : v) {
    if(!first) res += ", ";
    first = false; res += to_string(x);
  }
  res += "}";
  return res;
};
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;};
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); };

void LINE_OUT() {
  cout << "--------------" << endl;
};

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define LINE LINE_OUT();
#else
#define debug(...) 71
#define LINE 71;
#endif

void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
};

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
};

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
};

template<std::int_fast64_t Modulus>
class modint {
  using i64 = int_fast64_t;

  public:
  i64 a;

  constexpr modint(const i64 x = 0) noexcept {
    this -> a = x % Modulus;
    if(a < 0){
      a += Modulus;
    }
  }
  // constexpr i64 &value() const noexcept {return a;}
  constexpr const i64 &value() const noexcept {return a;}
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if(a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if(a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    i64 a_ = rhs.a, b = Modulus, u = 1, v = 0;
    while(b){
      i64 t = a_/b;
      a_ -= t * b; swap(a_,b);
      u -= t * v; swap(u,v);
    }
    a = a * u % Modulus;
    if(a < 0) a += Modulus;
    return *this;
  }

  constexpr bool operator==(const modint rhs) noexcept {
    return a == rhs.a;
  }
  constexpr bool operator!=(const modint rhs) noexcept {
    return a != rhs.a;
  }
  constexpr bool operator>(const modint rhs) noexcept {
    return a > rhs.a;
  }
  constexpr bool operator>=(const modint rhs) noexcept {
    return a >= rhs.a;
  }
  constexpr bool operator<(const modint rhs) noexcept {
    return a < rhs.a;
  }
  constexpr bool operator<=(const modint rhs) noexcept {
    return a <= rhs.a;
  }
  template<typename T>
  friend constexpr modint modpow(const modint &mt, T n) noexcept {
    if(n < 0){
      modint t = (modint(1) / mt);
      return modpow(t, -n);
    }
    modint res = 1, tmp = mt;
    while(n){
      if(n & 1)res *= tmp;
      tmp *= tmp;
      n /= 2;
    }
    return res;
  }
};

const long long MOD = 1e9+7;
using mint = modint<MOD>;
// iostream
std::ostream &operator<<(std::ostream &out, const modint<MOD> &m) {
  out << m.a; return out;
};
std::istream &operator>>(std::istream &in, modint<MOD> &m) {
  long long a; in >> a; m = mint(a); return in;
};

mint fact[200005];

void init() {
  fact[0] = mint(1);
  for(int i = 1; i < 200005; i++) {
    fact[i] = fact[i-1] * mint(i);
  }
};

// VERIFICATIOIN: EDPC_R
// URL: https://atcoder.jp/contests/dp/submissions/20597196

class ModMatrix {
  public:
  long long r, c;
  vector<vector<mint>> mat;
  ModMatrix() {}
  ModMatrix(int r, int c, mint init=mint(0)): r(r), c(c) {
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
  ModMatrix operator-() const {
    ModMatrix ret = ModMatrix(r, c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) ret.mat[i][j] *= -1;
    return ret;
  }
  ModMatrix& operator+=(const ModMatrix a) {
    assert(r == a.r && c == a.c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] += a.mat[i][j];
    return *this;
  }
  ModMatrix& operator+=(const int n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] += n;
    return *this;
  }
  ModMatrix& operator-=(const ModMatrix a) {
    assert(r == a.r && c == a.c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] -= a.mat[i][j];
    return *this;
  }
  ModMatrix& operator-=(const long long n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] -= n;
    return *this;
  }
  ModMatrix& operator*=(const ModMatrix a) {
    assert(c == a.r);
    ModMatrix ret = ModMatrix(r, a.c);
    for (int i=0; i<r; i++) for (int k=0; k<c; k++) for (int j=0; j<a.c; j++) ret.mat[i][j] += (mat[i][k] * a.mat[k][j]);
    *this = ret;
    return *this;
  }
  ModMatrix& operator*=(const long long n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] *= n;
    return *this;
  }
  ModMatrix operator+(const ModMatrix a) const {
    assert(r == a.r && c == a.c);
    return ModMatrix(*this) += a;
  }
  ModMatrix operator+(const long long n) const {
    return ModMatrix(*this) += n;
  }
  ModMatrix operator-(const ModMatrix a) const {
    assert(r == a.r && c == a.c);
    return ModMatrix(*this) -= a;
  }
  ModMatrix operator-(const long long n) const {
    return ModMatrix(*this) -= n;
  }
  ModMatrix operator*(const ModMatrix a) const {
    return ModMatrix(*this) *= a;
  }
  ModMatrix operator*(const long long n) const {
    return ModMatrix(*this) *= n;
  }
};

ModMatrix POWMAT(ModMatrix a, long long n) {
  assert(a.r == a.c);
  ModMatrix ret = ModMatrix(a.r, a.r);
  for (int i=0; i<a.r; i++) ret.mat[i][i] = mint(1ll);
  while (n > 0) {
    if (n & 1ll) ret *= a;
    a *= a; n >>= 1;
  }
  return ret;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
};
