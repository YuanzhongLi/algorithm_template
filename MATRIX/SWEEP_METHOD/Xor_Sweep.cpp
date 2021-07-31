#include <bits/stdc++.h>
using namespace std;

int Xor_Sweep(vector<vector<int>> &D) {
  int N = D.size(), M = D[0].size();
  int pos = 0;
  for (int i=0; i<M; i++) {
    bool found = false;
    for (int j = pos; j < N; j++) {
      if (D[j][i] == 1) {
        if (j != pos) swap(D[j], D[pos]);
        found = true;
        break;
      }
    }
    if (found) {
      for (int j=0; j<N; j++) {
        if (j != pos && D[j][i] == 1) {
          for (int k=i; k<M; k++) {
            D[j][k] ^= D[pos][k];
          }
        }
      }
      pos++;
    }
  }

  return pos; // pos行以降は0行列
};

void print_D(vector<vector<int>> D) {
  for (int i=0; i < D.size(); i++) {
    for (int j=0; j < D[0].size(); j++) {
      cout << D[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<vector<int> > D(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		int t, x;
		cin >> t;
		for (int j = 0; j < t; ++j) {
			cin >> x;
			D[i][--x] = 1;
		}
	}

	vector<int> S(M);
	for (int i = 0; i < M; ++i) {
		cin >> S[i];
	}

  int idx = Xor_Sweep(D);

  int pos = 0;
  for (int i=0; i<M; i++) {
    bool found = false;
    if (S[i] == 1) {
      while (pos < N) {
        if (D[pos][i]) {
          found = true;
          break;
        }
        pos++;
      }
      if (found) {
        for (int j=i; j<M; j++) {
          S[j] ^= D[pos][j];
        }
        pos++;
      }
    }
  }

  if (S == vector<int>(M, 0)) {
    int ans = 1;
    for (int i=idx; i<N; i++) ans = ans * 2 % 998244353;
    cout << ans << endl;
  } else cout << 0 << endl;
};
