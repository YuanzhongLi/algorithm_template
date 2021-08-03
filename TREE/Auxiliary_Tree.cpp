#define LOCAL
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
// string to_string(mint m) {return to_string(m.a); };
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

void LINE_OUT() { cout << "--------------" << endl; };
void SPACE_OUT() { cout << endl; };

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define LINE LINE_OUT();
#define SPACE SPACE_OUT();
#else
#define debug(...) 71
#define LINE 71;
#define SPACE 71;
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
  for (auto& vec : df) { print(vec); }
};

class LCA {
public:
  int V, logV;
  vector<int> depth;
  vector<vector<int>> parent;
  vector<vector<int>> tree;

  LCA(vector<vector<int>> in_tree) {
    tree = in_tree;
    V = in_tree.size();
    logV = 0;
    while (V > (1ll<<logV)) logV++;
    this->depth = vector<int>(V);
    this->parent = vector<vector<int>> (logV, vector<int>(V));
  }

  void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[0][u] = p;
    for (int v: tree[u]) {
      if (v == p) continue;
      dfs(v, u, d+1);
    }
  }

  void doubling() {
    for (int k = 0; k < logV-1; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

  void build(int u = 0, int p = -1, int d = 0) {
    dfs(u,p,d);
    doubling();
  }

  int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < logV; k++) {
      if (((depth[v] - depth[u])>>k)&1) v = parent[k][v];
    }
    if (u == v) return u;
    for (int k = logV-1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  int get_distance(int u, int v) {
    int lca = query(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
  }
};

class AuxiliaryTree {
public:
  int V;
  vector<vector<int>> tree;
  vector<int> fs, ls; // fs[v]: ET上の頂点vの最初の出現位置, ls[v]: ET上の頂点vの最後の出現位置
  LCA lca;

  vector<vector<int>> T; // auxiliary_tree graph

  AuxiliaryTree(vector<vector<int>> in_tree): lca(in_tree) {
    this->V = in_tree.size();
    this->tree = in_tree;
    lca.build();

    this->fs = vector<int>(V);
    this->ls = vector<int>(V);
    int cur = 0;
    et_dfs(0,-1,cur);

    this->T = vector<vector<int>>(V);
  }

  void et_dfs(int u, int p, int &cur) { // Euler tour
    fs[u] = cur++;
    for (int v: tree[u]) {
      if (v == p) continue;
      et_dfs(v, u, cur);
    }
    ls[u] = cur++;
  }

  void add_aux_edge(int u, int v) {
    T[u].pb(v);
    T[v].pb(u);
  }

  int query(vector<int> &vs) {
    sort(vs.begin(), vs.end(), [&](int u, int v) { return fs[u]<fs[v]; });
    vs.erase(unique(vs.begin(),vs.end()),vs.end());

    int K = vs.size();
    for (int i=0; i < K-1; i++) vs.push_back(lca.query(vs[i], vs[i+1]));
    sort(vs.begin(), vs.end(), [&](int u, int v) { return fs[u]<fs[v]; });
    vs.erase(unique(vs.begin(),vs.end()),vs.end());

    vector<int> stack;
    for (int v: vs) T[v].clear();
    for (int v: vs) {
      while (!stack.empty() && ls[stack.back()] < fs[v]) stack.pop_back();
      if (!stack.empty()) add_aux_edge(stack.back(), v);
      stack.push_back(v);
    }

    return stack[0]; // return root
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
};
