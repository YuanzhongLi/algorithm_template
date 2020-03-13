#include <bits/stdc++.h>
using namespace std;

// x^n mod Mを計算する
// 引き算は引かられる数にmodを足す!
long long modpow(long long x, long long n, long long M) {
  long long res = 1;
  if (n > 0) {
    res = modpow(x, n / 2, M);
    if (n % 2 == 0) res = (res * res) % M;
    else res = (((res * res) % M) * x) % M;
  }
  return res;
};

// initし忘れるな!!!
long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
};

long long fact[200005], inv[200005], factinv[200005];

void init(int m) {
  fact[0] = 1;
  for(int i = 1; i < 200000; i++) {
    fact[i] = (1ll * fact[i - 1] * i) % m;
  }
  for(int i = 0; i < 200000; i++) {
    inv[i] = modinv(i, m);
    factinv[i] = modinv(fact[i], m);
  }
};

// nCrを計算する
long long comb(long long n, long long r) {
  return fact[n] * factinv[r] * factinv[n - r];
};

// nCr mod を計算する
long long modcomb(long long n, long long r, long long m) {
  return (fact[n] * factinv[r] % m) * factinv[n - r] % m;
};
