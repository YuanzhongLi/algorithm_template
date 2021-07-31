#include <bits/stdc++.h>
using namespace std;

// VERIFICATIOIN: typical90_058
// URL: https://atcoder.jp/contests/typical90/submissions/23169142

static const int INF = 1e9+7;
static const int range = 100000;

int f(int x) { // range内のある数からrange内の別の数に変わる関数
  return x;
};

int main() {
  int N, K;
  vector<int> A;
  vector<int> visited(range, INF); // memo index
  int cur = N;
  int s, e;
  while (true) {
    int next = f(cur);
    if (visited[next] != INF) {
      s = visited[next]; e = A.size(); break;
    } else {
      cur = next;
      A.push_back(cur);
      visited[cur] = A.size()-1;
    }
  }

  vector<int> loop;
  for (int i=s; i<e; i++) loop.push_back(A[i]);
  int lp_size = loop.size();

  if (K <= e) {
    cout << A[K-1] << endl;
  } else {
    K -= s;
    K %= lp_size;
    K = (K == 0 ? lp_size-1 : K-1);
    cout << loop[K] << endl;
  }
};
