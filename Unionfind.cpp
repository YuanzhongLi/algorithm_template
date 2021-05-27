#include <bits/stdc++.h>
using namespace std;

class Unionfind {
public:
  int N;
  vector<int> par; // parent
  vector<int> rank; // tree hight
  vector<int> size; // root node numbers
  int treeNum; // tree number
  Unionfind(int N) : N(N), par(N), rank(N, 0), size(N, 1) {
    for (int i = 0; i < N; i++) {
      par[i] = i;
    }
    treeNum = N;
  }
  // add node
  void addNode() {
    par.push_back(N);
    rank.push_back(0);
    size.push_back(1);
    N++;
    treeNum++;
  }
  int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return;
    }
    treeNum--;
    if (rank[x] < rank[y]) {
      par[x] = y;
      size[y] += size[x];
    } else {
      par[y] = x;
      size[x] += size[y];
      if (rank[x] == rank[y]) {
        rank[x] += 1;
      }
    }
  }

  vector<vector<int>> group() { // O(N)
    vector<vector<int>> res;
    vector<vector<int>> table(N);
    for (int i = 0; i < N; i++) {
      table[root(i)].push_back(i);
    }
    for (int i = 0; i < N; i++) {
      if (!table[i].empty()) {
        res.push_back(table[i]);
      }
    }
    return res;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> data(M, vector<int>(2));
  for (int i = 0; i < M; i++) {
    cin >> data[i][0];
    cin >> data[i][1];
    data[i][0] -= 1;
    data[i][1] -= 1;
  }

  reverse(data.begin(), data.end());

  Unionfind uf(N);

  vector<long long> union_array(M);

  for (int i = 0; i < M; i++) {
    int x = uf.root(data[i][0]);
    int y = uf.root(data[i][1]);
    if (!uf.same(x, y)) {
      long long ans = uf.size[x] * uf.size[y];
      uf.unite(x, y);
      union_array[i] = ans;
    } else {
      union_array[i] = 0;
    }
  }

  reverse(union_array.begin(), union_array.end());

  long long op = 0;

  for (int i = 0; i < M; i++) {
    op += union_array[i];
    cout << op << endl;
  }
};
