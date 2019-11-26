#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> p[i];
  }

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);

  sort(ord.begin(), ord.end(),  [&](int a, int b) {
    if (s[a] == s[b]) return p[a] > p[b];
    return s[a] < s[b];
  });

  for (auto e: ord) cout << e + 1 << endl;
};
