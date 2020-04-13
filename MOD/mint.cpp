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
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
};
