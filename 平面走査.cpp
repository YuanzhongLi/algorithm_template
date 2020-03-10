#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
};

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

class Point {
  public:
  int x, y;

  Point(int x = 0, int y = 0): x(x), y(y) {}
};

struct Segment {
  Point p1, p2;
};

#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint {
  public:
    Point p;
    int seg, st; // 入力線分のID, 端点の種類
    EndPoint() {}
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

    bool operator < (const EndPoint &ep) const {
      // y 座標が小さい順に整列
      if (p.y == ep.p.y) {
        return st < ep.st; // y同一の場合下、左、右、上端点の順に調べる
      } else return p.y < ep.p.y;
    }
};

EndPoint EP[2 * 100000]; // 端点(EP)のリスト

int manhattanIntersection(vector<Segment> S) {
  int n = S.size();

  for (int i = 0, k = 0; i < n; i++) {
    // 端点p1, p2が左下を基準に並ぶように調整
    if (S[i].p1.y == S[i].p2.y) { // 平行線
      if (S[i].p1.x > S[i].p2.x) swap(S[i].p1, S[i].p2);
    } else if (S[i].p1.y > S[i].p2.y) swap(S[i].p1, S[i].p2); // 垂直線

    if (S[i].p1.y == S[i].p2.y) { // 水平線分を端点リストに追加
      EP[k++] = EndPoint(S[i].p1, i, LEFT);
      EP[k++] = EndPoint(S[i].p2, i, RIGHT);
    } else {
      EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
      EP[k++] = EndPoint(S[i].p2, i, TOP);
    }
  }

  sort(EP, EP + (2*n));

  set<int> BT; // 二分探索木
  BT.insert(1000000001); // 番兵追加 (1)参照
  int cnt = 0;

  rep(i, 0, 2 * n) {
    if (EP[i].st == TOP) {
      BT.erase(EP[i].p.x);
    } else if (EP[i].st == BOTTOM) {
      BT.insert(EP[i].p.x);
    } else if (EP[i].st == LEFT) {
      set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x); // O(log n)
      set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x); // O(log n) - (1)このために番兵を追加している
      cnt += distance(b, e); // bとeの距離（点の数）を加算, O(k)
    }
  }

  return cnt;
};

int main() {
  int n;
  cin >> n;
  int x1, y1, x2, y2;
  vector<Segment> S(n);
  rep(i, 0, n) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    Point p1 = Point(x1, y1);
    Point p2 = Point(x2, y2);
    Segment seg = { p1, p2 };
    S[i] = seg;
  }

  int ans = manhattanIntersection(S);

  cout << ans << endl;
  return 0;
};
