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

// AOJ DPL_1_H
/*
  n <= 40の条件などで使える可能性あり!
*/

class Item {
  public:
  ll v, w;
  Item() {}
  Item(ll v, ll w): v(v), w(w) {}
  bool operator < (const Item &i) {
    if (w == i.w) {
      return v > i.v;
    } else {
      return w < i.w;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  ll W;
  cin >> W;

  vector<Item> items(N);
  rep(i, 0, N) {
    cin >> items[i].v >> items[i].w;
  }

  int n = (N+1) / 2;

  vector<Item> items1;
  for (int i = 0; i < (1 << n); i++) {
    ll sv = 0ll, sw = 0ll;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1 == 1) {
        sv += items[j].v;
        sw += items[j].w;
      }
    }

    items1.pb(Item(sv, sw));
  }
  sort(All(items1));


  vector<Item> items2;
  items2.pb(Item(0ll, 0ll));
  int size = 1;
  rep(i, 0, items1.size()) {
    auto item = items1[i];
    if (item.v > items2[size-1].v && item.w > items2[size-1].w) {
      items2.pb(item);
      size++;
    }
  }

  ll ans = 0ll;

  for (int i = 0; i < (1 << (N-n)); i++) {
    ll sv = 0ll;
    ll sw = 0ll;
    for (int j = 0; j < (N-n); j++) {
      if ((i >> j) & 1 == 1) {
        sv += items[j+n].v;
        sw += items[j+n].w;
      }
    }

    ll tw = W - sw;
    if (tw < 0ll) continue;
    int ng = (int)items2.size();
    int ok = 0;
    while (abs(ng-ok) > 1) {
      int mid = (ng+ok) /2;
      if (items2[mid].w <= tw) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    ans = max(ans, sv + items2[ok].v);
  }

  cout << ans << endl;

  return 0;
};
