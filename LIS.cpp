#include <bits/stdc++.h>
using namespace std;


// 対象のvectorの [s, e)の範囲でのLIS
int LIS(vector<int> &x, int s, int e) {
  int INFTY = 1e9+7;
  vector<int> ret(e - s, INFTY);
  ret[0] = x[s];
  int size = 1;
  for (int i = s + 1; i < e; i++) {
    int tmp = x[i];
    // 注意: 以上、以下の場合 <= , >=となる
    if (ret[size - 1] < tmp) {
      ret[size++] = tmp;
    } else {
      // 注意: 以上、以下の場合upper_boundとなる
      *lower_bound(ret.begin(), ret.end(), tmp) = tmp;
    }
  }
  return size;
};

int main() {
  vector<int> X(6);
  for(int i = 0; i < 6; i++) {
    cin >> X[i];
  }

  int ans = LIS(X, 0, X.size());
  cout << ans << endl;
};


