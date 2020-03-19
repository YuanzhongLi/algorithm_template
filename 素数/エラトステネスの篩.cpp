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

const int MAX_N = 100005;
int prime[MAX_N]; // i番目の素数
bool is_prime[MAX_N+1]; // is_prime[i] = trueならiは素数

// n以下の素数の数を返す
int sieve(int n) {
  int p = 0;
  rep(i, 0, n+1) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime[p++] = i;
      for (int j = 2 * i; j <= n; j+=i) is_prime[j] = false;
    }
  }

  return p;
};


/*
  [a, b)の区間での素数の数
  a < b <= 10^12
  b - a <= 10^6

  b未満の素数でない整数の最小の素因数は高々root(b)!
*/
const int MAX_L = 1e6+5;
const int MAX_SQRT_B = 1e6+5;
bool is_prime[MAX_L];
bool is_prime_samll[MAX_SQRT_B];

void segment_seive(ll a, ll b) {
  for (int i = 0; (ll)i*i < b; i++) is_prime_samll[i] = true;
  for (int i = 0; i < b - a; i++) is_prime[i] = true;
  for (int i = 2; (ll) i*i < b; i++) {
    for (int j = 2 * i; (ll)j * j < b; j+= i) is_prime_samll[j] = false; // [2, root(b)) のエラトステネスの篩
    for (ll j = max(2ll, (a+i-1)/i) * i; j < b; j+= i) is_prime[j - a] = false; // [a, b) の篩
    // ((a+i-1)/i) * i はa以上の最大のiの倍数
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
};
