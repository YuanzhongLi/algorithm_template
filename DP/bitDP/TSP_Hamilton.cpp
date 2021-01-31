// #define LOCAL
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

constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1002003004;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vvi graph(N);
  vector<bool> used(N, false);
  vi dist(N, INF);
  rep(i, 0, M) {
    int a, b; cin >> a >> b; a--; b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  int K; cin >> K;
  vi C(K);
  rep(i, 0, K) {
    int c; cin >> c; c--;
    C[i] = c;
  }

  vvi g(K, vi(K, INF));
  rep(k, 0, K) {
    rep(i, 0, N) {
      used[i] = false;
      dist[i] = INF;
    }
    int c = C[k];
    queue<int> q;
    q.push(c);
    dist[c] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (used[u]) continue;
      used[u] = true;
      for (int v: graph[u]) {
        if (used[v]) continue;
        q.push(v);
        chmin(dist[v], dist[u]+1);
      }
    }

    rep(i, 0, K) {
      chmin(g[k][i], dist[C[i]]);
      chmin(g[i][k], dist[C[i]]);
    }
  }


  /*
   * Bit DP Part
   */
  vvi dp(1 << K, vi(K, INF));
  for (int i=0; i<K; i++) dp[1<<i][i] = 0;
  for (int bit=1; bit<(1<<K); bit++) {
    rep(i, 0, K) { // 現在はiにいる
      if ((bit>>i)&1) {
        int bit2 = bit ^ (1<<i); // 一つ前の状況(iに到達する前)
        for (int j=0; j<K; j++) {
          if ((bit2>>j)&1) { // bit2の状況でjにいる
            dp[bit][i] = min(dp[bit][i], dp[bit2][j] + g[j][i]);
          }
        }
      }
    }
  }

  // こっちでもok
  // vvi dp(1 << K, vi(K, INF));
  // rep(i, 0, K) dp[(1 << K)-1][i] = 0;
  // for (int S = (1 << K) - 2; S >= 0; S--) {
  //   rep(v, 0, K) {
  //     rep(u, 0, K) {
  //       if (!((S >> u) & 1)) {
  //         dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + g[v][u]);
  //       }
  //     }
  //   }
  // }

  int ans = INF;
  rep(i, 0, K) {
    chmin(ans, dp[(1<<K)-1][i]);
  }
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans + 1 << endl;
  }

  return 0;
};
