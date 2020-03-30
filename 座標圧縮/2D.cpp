#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
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
#define debug(x) cerr << #x << ": " << (x) << "\n";

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(ll x, int n) {
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

int dx[4] = {0, 1, 0, -1}; // u, r, d, l
int dy[4] = {-1, 0, 1, 0}; // u, r, d, l

// AOJ 0531
const int MAX = 1005;
vector<vector<bool>> visited(MAX*6, vector<bool> (MAX*6, false));

void init_visited(int w, int h) {
  rep(i, 0, h) {
    rep(j, 0, w) {
      visited[i][j] = false;
    }
  }
};

int compress(int n, vi &X1, vi &X2, int w) {
  vector<int> xs;
  rep(i, 0, n) {
    for (int d = -1; d <= 1; d++) {
      int tx1 = X1[i]+d, tx2 = X2[i]+d;
      if (0 <= tx1 && tx1 <= w) xs.pb(tx1);
      if (0 <= tx2 && tx2 <= w) xs.pb(tx2);
    }
  }

  sort(All(xs));
  xs.erase(unique(All(xs)), xs.end());
  rep(i, 0, n) {
    X1[i] = lbidx(xs, X1[i]);
    X2[i] = lbidx(xs, X2[i]);
    // X1[i] = find(All(xs), X1[i]) - xs.begin();
    // X2[i] = find(All(xs), X2[i]) - xs.begin();
  }

  return xs.size();
};

int solve(int w, int h, int n, vi &X1, vi &Y1, vi &X2, vi &Y2) {
  int W = compress(n, X1, X2, w);
  int H = compress(n, Y1, Y2, h);
  init_visited(W, H);

  rep(i, 0, n) {
    for (int y = Y1[i]; y <= Y2[i]; y++) {
      for (int x = X1[i]; x <= X2[i]; x++) {
        visited[y][x] = true;
      }
    }
  }

  int ans = 0;
  rep(y, 0, H) {
    rep(x, 0, W) {
      if (visited[y][x]) continue;
      ans++;
      queue<int> q;
      int s = y * W + x;
      q.push(s);
      while (!q.empty()) {
        int u = q.front(); q.pop();
        int uy = u / W;
        int ux = u % W;
        if (visited[uy][ux]) continue;
        visited[uy][ux] = true;
        rep(i, 0, 4) {
          int ty = uy + dy[i];
          int tx = ux + dx[i];
          if (0 <= ty && ty < H && 0 <= tx && tx < W) {
            if (visited[ty][tx]) continue;
            int v = ty * W + tx;
            q.push(v);
          }
        }
      }
    }
  }

  return ans;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h;
  while (cin >> w >> h, w) {
    w--; h--;
    int n;
    cin >> n;
    vi X1(n), Y1(n), X2(n), Y2(n);
    rep(i, 0, n) {
      cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
      X2[i]--; Y2[i]--;
    }

    cout << solve(w, h, n, X1, Y1, X2, Y2) << endl;
  }
  return 0;
};
