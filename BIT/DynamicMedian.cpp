#define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n; i > (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // dist between two elements
// #define M_PI 3.14159265358979323846 // CF
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // 小数点を10桁まで表示
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

constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1001001001;
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

template<typename T>
class BIT {
public:
  int n;
  vector<T> dat;

  BIT(int nin=0) {
    n = nin;
    dat.resize(n);
    for (int i = 0; i < n; i++) dat[i] = 0;
  }

  // 0~iまでの和を求める
  T sum(int i) {
    T s = 0;
    while (i >= 0) {
      s += dat[i];
      i = (i & (i+1)) - 1;
    }
    return s;
  }

  // [i, j]の和を求める
  T sum_between(int i, int j){
    if(i > j) return 0;
    return sum(j) - sum(i-1);
  }

  // 一点更新
  void add(int i, T x) {
    while(i < n) {
      dat[i] += x;
      i |= i+1;
    }
  }

  // a[0]+...+a[ret] >= x
  int lower_bound(T x){
    int ret = -1;
    int k = 1;
    while (2*k <= n) k <<= 1;
    for( ;k>0; k>>=1){
      if(ret+k < n && dat[ret+k] < x){
        x -= dat[ret+k];
        ret += k;
      }
    }
    return ret + 1;
  }
};

// VERIFICATION: ABC 127_F
// URL: https://atcoder.jp/contests/abc127/submissions/16495386

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Q; cin >> Q;
  vi T(Q), A(Q), B(Q);
  vi as;
  rep(i, 0, Q) {
    cin >> T[i];
    if (T[i] == 1) {
      cin >> A[i] >> B[i];
      as.pb(A[i]);
    }
  }

  // 圧縮
  sort(All(as));
  as.erase(unique(All(as)), as.end());
  map<int, int> mp;
  int sz = as.size();
  rep(i, 0, sz) mp[as[i]] = i; // 値に対応するindex(小さい方から何番目か)

  BIT<ll> bitnum(sz); // 何個かを管理するBIT
  BIT<ll> bitsum(sz); // 和を管理するBIT
  ll fix = 0; // 不変の部分
  int all = 0; // 何個追加されたか(つまりq = 1が何回か)
  rep(i, 0, Q) {
    if (T[i] == 1) {
      int ai = mp[A[i]];
      bitsum.add(ai, A[i]);
      bitnum.add(ai, 1);
      fix += B[i];
      all++;
    } else {
      ll ans = fix;
      int idx = bitnum.lower_bound((all+1)/2);
      ans += bitsum.sum_between(idx+1, sz-1);
      ans -= as[idx] * bitnum.sum_between(idx+1, sz-1);
      ans -= bitsum.sum_between(0, idx-1);
      ans += as[idx] * bitnum.sum_between(0, idx-1);
      cout << as[idx] << " " << ans << endl;
    }
  }

  return 0;
};
