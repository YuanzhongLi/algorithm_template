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



#define MAX 1400

// VERIFICATIOIN: ABC 189_C
// URL: https://atcoder.jp/contests/abc189/submissions/19654680

// from histogram get max rectangular area
ll getLargestRect(vector<long long> A) {
  vector<pair<long long, long long>> stack;
  A.push_back(0ll); // add sentinel
  ll n = A.size();
  ll maxv = 0;

  for (int i=0; i<n+1; i++) {
    ll a = A[i];
    if (stack.empty()) stack.push_back(make_pair(a, i));
    else {
      if (stack.back().first < a) stack.push_back(make_pair(a, i));
      else if (stack.back().first > a) {
        ll target = i;
        while (!stack.empty() && stack.back().first >= a) {
          auto  pre = stack.back(); stack.pop_back();
          ll tmp = pre.first * (i - pre.second); maxv = max<ll>(maxv, tmp); target = pre.second;
        }
        stack.push_back(make_pair(a, target));
      }
    }
  }
  return maxv;
};

int H, W;
vector<vector<long long>> buffer(MAX, vector<long long> (MAX, 0ll)), T(MAX, vector<long long> (MAX, 0ll));

int solve() {
  rep(j, 0, W) {
    rep(i, 0, H) {
      if (buffer[i][j]) {
        T[i][j] = 0;
      } else {
        T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
      }
    }
  }

  ll ret = 0;

  rep(i, 0, H) {
    ret = max<ll>(ret, getLargestRect(T[i]));
  }

  return ret;
};

int main() {
  scanf("%d %d", &H, &W);

  rep(i, 0, H) {
    rep(j, 0, W) {
      scanf("%d", &buffer[i][j]);
    }
  }
  int ans = solve();
  cout << ans << endl;
};
