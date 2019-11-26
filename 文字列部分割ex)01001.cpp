#include <bits/stdc++.h>
using namespace std;

int main() {
  int num = 1;
  string S;
  cin >> S;

  vector<char> v1;
  vector<int> v2;

  for (int i = 0; i < S.size(); i++) {
    char c = S[i];
    if (i == 0) {
      v1.push_back(c);
    } else if (c == S[i - 1]) {
      num++;
    } else {
      v2.push_back(num);
      v1.push_back(c);
      num = 1;
    }

    if (i == S.size() - 1) v2.push_back(num);
  }
};
