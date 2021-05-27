#include <bits/stdc++.h>
using namespace std;

// VERIFICATION: AOJ ALDS1_14_D
// URL: https://onlinejudge.u-aizu.ac.jp/status/users/ryuan71/submissions/1/ALDS1_14_D/judge/5509989/C++17

// O(N(lonN)^2)
class SuffixArray {
public:
  int N;
  string S;
  vector<int> rank;
  vector<int> tmp;
  vector<int> sa;
  SuffixArray(string S): S(S) {
    N = S.size();
    rank.resize(N+1);
    tmp.resize(N+1);
    sa.resize(N+1);

    for (int i=0; i<=N; i++) {
      sa[i] = i;
      rank[i] = i < N ? S[i] : -1;
    }

    for (int k=1; k <= N; k <<= 1) {
      sort(sa.begin(), sa.end(), [&](int i, int j) {
        if (rank[i] != rank[j]) return rank[i] < rank[j];
        int ri = (i+k <= N ? rank[i+k] : -1);
        int rj = (j+k <= N ? rank[j+k] : -1);
        return ri < rj;
      });

      tmp[sa[0]] = 0;
      for (int i = 1; i <= N; i++) {
        bool small;
        if (rank[sa[i-1]] != rank[sa[i]]) small = rank[sa[i-1]] < rank[sa[i]];
        else {
          int ri = (sa[i-1]+k <= N ? rank[sa[i-1]+k] : -1);
          int rj = (sa[i]+k <= N ? rank[sa[i]+k] : -1);
          small = ri < rj;
        }
        tmp[sa[i]] = tmp[sa[i-1]] + (small ? 1 : 0);
      }
      for (int i=0; i <= N; i++) rank[i] = tmp[i];
    }
  }

  bool lt_substr(const string &t, int si = 0, int ti = 0) {
    int sn = S.size(), tn = t.size();
    while (si < sn && ti < tn) {
      if (S[si] < t[ti]) return true;
      if (S[si] > t[ti]) return false;
      si++; ti++;
    }
    return si >= sn && ti < tn;
  }

  int lower_bound(const string &t) {
    int low = -1, high = sa.size();
    while (high - low > 1) {
      int mid = (high+low)/2;
      if (lt_substr(t, sa[mid])) low = mid;
      else high = mid;
    }
    return high;
  }

  pair<int, int> lower_upper_bound(string &t) {
    int idx = lower_bound(t); // lower_bound
    int low = idx-1, high = sa.size();
    t.back()++;
    while (high - low > 1) {
      int mid = (low+high)/2;
      if (lt_substr(t, sa[mid])) low = mid;
      else high = mid;
    }
    t.back()--;
    return {idx, high}; // <lower_bound, upper_bound>
  }

  int detect(string &t) {
    auto pi = lower_upper_bound(t);
    int low_idx = pi.first, upper_idx = pi.second;
    return (low_idx == upper_idx ? -1 : low_idx);
  }

  void show() {
    for (int i=0; i < sa.size(); i++) {
      cout << i << ": " << S.substr(sa[i]) << endl;
    }
  }
};

int main() {
  string S; cin >> S;
  SuffixArray sa(S);

  int Q; cin >> Q;
  while (Q--) {
    string P; cin >> P;
    cout << (sa.detect(P) == -1 ? 0 : 1) << endl;
  }

  return 0;
};
