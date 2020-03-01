#include <bits/stdc++.h>
using namespace std;

// 左づめでの10進数xをdigits桁のN進数vectorにしてを返す
vector<int> baseNumber(int N, int digits, int x) {
  vector<int> ret(digits, 0);
  // 商
  int quotient = x;
  int counter = 0;
  while (quotient > 0) {
    // 余り
    int remainder = quotient % N;
    quotient /= N;
    ret[counter] = remainder;
    counter++;
  }

  return ret;
};

// 0からn-1までのN進数を上記のbaseNumberで返したvectorのvector
vector<vector<int>> baseNumbers(int n, int N, int digits) {
  vector<vector<int>> ret(n, vector<int> (digits));
  for (int i = 0; i < n; i++) {
    ret[i] = baseNumber(N, digits, i);
  }

  return ret;
};

int main() {
  cout << "baseNumber result" << endl;
  vector<int> a;
  a = baseNumber(3, 10, 65);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
  }
  cout << endl;

  cout << "baseNumber result end." << endl;
  cout << "----------------------" << endl;

  cout << "baseNumber result" << endl;
  vector<vector<int>> b = baseNumbers(14, 3, 5);
  for (int i = 0; i < 14; i++) {
    for (int j = 0; j < 5; j++) {
      cout << b[i][j];
    }
    cout << endl;
  }

  cout << "baseNumbers result end." << endl;
  cout << "----------------------" << endl;
};
