#include <bits/stdc++.h>
using namespace std;

// for problem which mod is variable
class mint {
public:
  long long x, mod;
  mint() {}
  mint(long long x, long long mod): x((x%mod+mod)%mod), mod(mod) {}
  mint operator-() const { return mint(-x, mod); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(long long t) const {
    if (!t) return mint(1,mod);
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2); }
  mint& operator /= (const mint a) { return *this *= a.inv(); }
  mint operator / (const mint a)  const { return mint(*this) /= a; }
};

mint fact[200005];
void init(long long mod) {
  fact[0] = mint(1, mod);
  for (long long i = 1; i < 200005ll; i++) {
    fact[i] = fact[i-1] * mint(i, mod);
  }
};
