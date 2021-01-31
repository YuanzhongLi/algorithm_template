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

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, long>;

/* Lowlink: グラフの関節点・橋を列挙する構造体
    作成: O(E+V)
    関節点の集合: vector<int> aps
    橋の集合: vector<P> bridges
*/
struct LowLink {
  const Graph &G;
  vector<int> used, ord, low;
  vector<int> aps;  // articulation points
  vector<P> bridges;

  LowLink(const Graph &G_) : G(G_) {
    used.assign(G.size(), 0);
    ord.assign(G.size(), 0);
    low.assign(G.size(), 0);
    int k = 0;
    for (int i = 0; i < (int)G.size(); i++) {
      if (!used[i]) k = dfs(i, k, -1);
    }
    sort(aps.begin(), aps.end()); // 必要ならソートする
    sort(bridges.begin(), bridges.end()); // 必要ならソートする
  }

  int dfs(int id, int k, int par) { // id:探索中の頂点, k:dfsで何番目に探索するか, par:idの親
    used[id] = true;
    ord[id] = k++;
    low[id] = ord[id];
    bool is_aps = false;
    int count = 0; // 子の数
    for (auto &e : G[id]) {
      if (!used[e.to]) {
        count++;
        k = dfs(e.to, k, id);
        low[id] = min(low[id], low[e.to]);
        if (par != -1 && ord[id] <= low[e.to]) is_aps = true;
        if (ord[id] < low[e.to]) bridges.emplace_back(min(id, e.to), max(id, e.to)); // 条件を満たすので橋
      } else if (e.to != par) { // eが後退辺の時
        low[id] = min(low[id], ord[e.to]);
      }
    }
    if (par == -1 && count >= 2) is_aps = true;
    if (is_aps) aps.push_back(id);
    return k;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
};
