#include <bits/stdc++.h>
using namespace std;

class Person {
  public:
    string name;
    int age;
    Person(string s, int n): name(s), age(n) {}
};

vector<int> func(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    vec[i] = 0;
  }
  return vec;
};

int main() {
  vector<int> a(10, 1);
  vector<int> b = func(a);
  for (int i = 0; i < a.size(); i++) {
    cout << "a: " << a[i] <<
  }
};
