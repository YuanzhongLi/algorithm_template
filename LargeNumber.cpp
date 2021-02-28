// #define LOCAL
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

int digit(int x) {
  int ret = 0;
  while (x) {
    x /= 10;
    ret++;
  }
  return ret;
};

int toI(vector<int> &K, int l, int r) {
  int ret = 0;
  int j = r-l;
  rep(i, l, r+1) {
    ret += K[i] * POW(10, j);
    j--;
  }
  return ret;
}

vector<int> toD (int x) { // 123 -> [3, 2, 1]
  vi ret;
  while (x) {
    ret.pb(x%10);
    x/=10;
  }
  return ret;
}

int div(int x, vi K) {
  int dk = K.size();
  int l = 0, r = 0;
  while (r < dk) {
    int k = toI(K, l, r);
    if (k >= x) {
      int re = k%x;
      auto re_d = toD(re);
      rep(i, 0, re_d.size()) K[r-i] = re_d[i];
      l = r+1-re_d.size();
    } else {
      if (r == dk-1) return k;
      else r++;
    }
  }
};

vi sub(int x, vi K) {
  vi X = toD(x);
  reverse(All(K));
  int carry = 0;
  rep(i, 0, K.size()) {
    int xi = 0;
    if (i < X.size()) xi = X[i];
    int ki = K[i];
    int nxt_carry = 0;
    if (carry) {
      if (ki == 0) {
        ki = 9;
        nxt_carry = 1;
      } else ki--;
    }

    if (ki >= xi) {
      K[i] = ki-xi;
    } else {
      nxt_carry = 1;
      ki += 10;
      K[i] = ki-xi;
    }
    carry = nxt_carry;
  }
  reverse(All(K));
  return K;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, a; cin >> N >> a; a--;
  string tmp_k; cin >> tmp_k;
  vi K;
  for (char ch: tmp_k) {
    K.pb((int)ch-'0');
  }
  vi B(N); rep(i, 0, N) { cin >> B[i]; B[i]--; }

  vi way;
  way.pb(a);
  set<int> s;
  int roop_s_idx;
  rep(i, 0, n_max) {
    int prev = way.back();
    int nxt = B[prev];
    if (Find(s, nxt)) {
      rep(i, 0, way.size()) {
        if (way[i] == nxt) {
          roop_s_idx = i;
          break;
        }
      }
      break;
    } else {
      way.pb(nxt);
      s.insert(nxt);
    }
  }
  debug(way);
  int to_roop_s = roop_s_idx-1;
  vi roop; rep(i, roop_s_idx, way.size()) roop.pb(way[i]);
  int roop_size = roop.size();
  debug(roop);

  int dk = K.size();
  if (dk > 7) {
    K = sub(to_roop_s, K);
    int re = div(roop_size, K);
    int idx = (re-1+roop_size) % roop_size;
    cout << roop[idx]+1 << endl;
  } else {
    int k = toI(K, 0, K.size()-1);
    int ans = a;
    rep(i, 0, k) {
      ans = B[ans];
    }
    cout << ans+1 << endl;
  }

  return 0;
};
