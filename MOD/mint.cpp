#include <bits/stdc++.h>
using namespace std;

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

// calculate nCr mod
mint modcomb(long long n, long long r) {
  return fact[n] / fact[r] / fact[n - r];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
};
