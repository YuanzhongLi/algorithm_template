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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;
#define debug(x) cerr << #x << ": " << (x) << "\n";

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
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
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

  // 自前実装
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
  // constexpr modint& operator++() noexcept {
  //     return (*this) += modint(1);
  // }
  // constexpr modint operator++(int) {
  //     modint tmp(*this);
  //     operator++();
  //     return tmp;
  // }
  // constexpr modint& operator--() noexcept {
  //     return (*this) -= modint(1);
  // }
  // constexpr modint operator--(int) {
  //     modint tmp(*this);
  //     operator--();
  //     return tmp;
  // }
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

const ll MOD = 1e9+7;
using mint = modint<MOD>;
// 標準入出力対応
std::ostream &operator<<(std::ostream &out, const modint<MOD> &m) {
  out << m.a;
  return out;
}
std::istream &operator>>(std::istream &in, modint<MOD> &m) {
  ll a;
  in >> a;
  m = mint(a);
  return in;
}

mint fact[200005];

void init() {
  fact[0] = mint(1);
  for(int i = 1; i < 200005; i++) {
    fact[i] = fact[i - 1] * mint(i);
  }
};

// nCr mod を計算する
mint modcomb(long long n, long long r) {
  return fact[n] / fact[r] / fact[n - r];
};

// VERIFICATION: ABC 164_F

// sum_t: 単位元の型（つまりdpで保持するデータの型）, key_t: 辺データの型
template< typename sum_t, typename key_t >
struct ReRooting {
  struct Edge {
    int to;
    key_t data;
    // dp: 出て行く時のdpの値（rootとする頂点によって変化して行く）, ndp累積の値（前からと後ろからで変化して行く）
    sum_t dp, ndp;
  };

  using F = function< sum_t(sum_t, sum_t) >;
  using G = function< sum_t(sum_t, key_t) >;

  vector< vector< Edge > > graph;
  vector< sum_t > subdp, dp;
  const sum_t ident; // 単位元
  const F f; // マージする関数（モノイド）
  const G g;
  // V: 頂点数, f: function, g: function, ident: 単位元
  ReRooting(int V, const F f, const G g, const sum_t &ident)
      : graph(V), f(f), g(g), ident(ident), subdp(V, ident), dp(V, ident) {}

  void add_edge(int u, int v, const key_t &d) {
    graph[u].emplace_back((Edge) {v, d, ident, ident});
    graph[v].emplace_back((Edge) {u, d, ident, ident});
  }

  void add_edge_bi(int u, int v, const key_t &d, const key_t &e) {
    graph[u].emplace_back((Edge) {v, d, ident, ident});
    graph[v].emplace_back((Edge) {u, e, ident, ident});
  }

  // 最初にある頂点idxを決めてdfsを行う
  void dfs_sub(int idx, int par) {
    for(auto &e : graph[idx]) {
      if(e.to == par) continue;
      dfs_sub(e.to, idx);
      subdp[idx] = f(subdp[idx], g(subdp[e.to], e.data));
    }
  }

  void dfs_all(int idx, int par, const sum_t &top) { // top: 親方向へのdpの値
    sum_t buff{ident}; // 累積バッファ（単位元で初期化）

    // 順に見て行く
    for(int i = 0; i < (int) graph[idx].size(); i++) {
      auto &e = graph[idx][i];
      e.ndp = buff; // 0から順に見たときの累積（　[,idx)までの累積　）
      e.dp = g(par == e.to ? top : subdp[e.to], e.data);
      buff = f(buff, e.dp);
    }
    dp[idx] = buff;

    // 逆から見て行く
    buff = ident;
    for(int i = (int) graph[idx].size() - 1; i >= 0; i--) {
      auto &e = graph[idx][i];
      if(e.to != par) dfs_all(e.to, idx, f(e.ndp, buff));
      e.ndp = f(e.ndp, buff); // 逆から見た時の累積
      buff = f(buff, e.dp);
    }
  }

  vector< sum_t > build() {
    dfs_sub(0, -1);
    dfs_all(0, -1, ident);
    return dp;
  }
};

void solve() {
  // <通り, 部分木の辺の数>
  // 単位元 <mint(1), 0>
  using pmi = pair<mint, int>;

  int n;
  cin >> n;

  init();

  // マージ関数
  auto f1 = [&](pmi a, pmi b) {
    return pmi(a.first * b.first * modcomb(a.second + b.second, a.second), a.second + b.second);
  };

  // <通り, 部分木の辺の数に自身を足すことで部分木のサイズを返す>
  auto f2 = [&](pmi a, int b) {
    return pmi(a.first, a.second + b);
  };

  ReRooting<pmi, int> rt(n, f1, f2, pmi(mint(1), 0));

  int u, v;
  rep(i, 0, n-1) {
    cin >> u >> v;
    u--; v--;
    rt.add_edge(u, v, 1);
  }

  for (auto p: rt.build()) {
    cout << p.first << endl;
  }
};



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
};
