#include <bits/stdc++.h>
using namespace std;

// 対象のvectorの [s, e)の範囲でのLIS
vector<int> LIS(vector<int> &x, int s, int e) {
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
  return vector<int> (ret.begin(), ret.begin()+size);
};

int main() {
  vector<int> X(8);
  for(int i = 0; i < 8; i++) {
    cin >> X[i];
  }

  vector<int> ans = LIS(X, 0, X.size());
  for (auto a: ans) {
    cout << a << endl;
  }
};


