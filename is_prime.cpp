#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)

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

int isPrime(int x) {
  int i;
  if (x < 2) return 0;
  else if (x == 2) return 1;

  if (x % 2 == 0) return 0;
  for (i = 3; i*i <= x; i += 2) {
    if (x % i == 0) return 0;
  }
  return 1;
};

// 素因数分解
// pn = { 2, 3, 5, 7 ..} 可能性のある素数列
map<int, int> PrimeFactorization(int x, vector<int> &pn) {
  map<int, int> ret;
  rep(i, 0, pn.size()) {
    ret.emplace(pn[i], 0);
  }

  int pn_idx = 0;
  while(x > 1) {
    int p = pn[pn_idx];
    if (x % p == 0) {
      x /= p;
      ret[p]++;
    } else {
      pn_idx++;
    }
  }

  return ret;
};

int main() {

};
