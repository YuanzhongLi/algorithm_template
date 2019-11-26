#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  long long ans = 0;
  long long sum = 0;

  int r = 0;
  // lを基準にして考えていく
  for (int l = 0; l < N; l++) {
    // このwhileでK以上となるrまで到達する（ない場合はsumがsum < Kとなっている）
    while (sum < K) {
      if (r == N) {
        break;
      } else {
        sum += a[r];
        r++;
      }
    }
    // 現在のlの地点で最大のr = N - 1まで合計してもKを超えなかったのでbreakする
    if (sum < K) {
      break;
    }
    ans += N - r + 1;
    sum -= a[l];
  }

  cout << ans << endl;
};
