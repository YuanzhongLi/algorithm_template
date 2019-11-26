#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y);

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point {
  public:
  double x, y;

  Point(double x = 0, double y = 0): x(x), y(y) {}

  Point operator + (Point p) { return Point(x + p.x, y + p.y); }
  Point operator - (Point p) { return Point(x - p.x, y - p.y); }
  Point operator * (double a) { return Point(a * x, a * y); }
  Point operator / (double a) { return Point(x / a, y / a); }

  double abs() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }

  bool operator < (const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

class Circle {
  public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

struct Segment {
  Point p1, p2;
};

typedef Point Vector;
typedef Segment Line;

double norm(Vector a) {
  return a.x * a.x + a.y * a.y;
};

double abs(Vector a) {
  return sqrt(norm(a));
};

// 内積
double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
};

// 外積
double cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
};

// 直交判定
bool isOrthogonal(Vector a, Vector b) {
  return equals(dot(a, b), 0.0);
};

// 並行判定
bool isParallel(Vector a, Vector b) {
  return equals(cross(a, b), 0.0);
};

// 射影
Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / base.norm();
  return s.p1 + base * r;
};

// 反射
Point reflect(Segment s, Point p) {
  return p + (project(s, p) - p) * 2.0;
};

// 点と点の距離
double getDistance(Point a, Point b) {
  return abs(a - b);
};

// 点と直線の距離
double getDistanceLP(Line l, Point p) {
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
};

// 点と線分の距離
double getDistanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
};

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

// 二つのベクトルの位置関係
int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  if (a.norm() < b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
};

// 線分の交差判定
bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
};

bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
};

// 円と直線の交差判定
bool intersect(Circle c, Line l) {
  return getDistanceLP(l, c.c) <= c.r;
};

// 円と円の交差判定
bool intersect(Circle c1, Circle c2) {
  return getDistance(c1.c, c2.c) <= (c1.r + c2.r);
};

// 線分と線分の距離
double getDistance(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)), min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
};

// 線分と線分の交点(必ず交点があり、それがどちらかの端点出ない)
Point getCrossPoint(Segment s1, Segment s2) {
  Vector base = s2.p2 -s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 = abs(cross(base, s1.p2 - s2.p1));
  double t = d1/ (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
};

// 円cと線分lの交点
pair<Point, Point> getCrossPoints(Circle c, Line l) {
  assert(intersect(c, l));
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
  double base = sqrt(c.r * c.r - norm(pr - c.c));
  return make_pair(pr + e * base, pr - e * base);
};

double arg(Vector p) { return atan2(p.y, p.x); };
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); };

// circle c1とcircle c2の交点
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
  assert(intersect(c1, c2));
  double d = abs(c1.c - c2.c);
  double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  double t = arg(c2.c - c1.c);
  return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
};

typedef vector<Point> Polygon;
// 点の内包
int contains(Polygon g, Point p) {
  int n = g.size();
  bool x = false;
  for (int i = 0; i < n; i++) {
    Point a = g[i] - p, b = g[(i + 1) % n] - p;
    // 辺上のとき1を返す
    if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
    if (a.y > b.y) swap(a, b);
    if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
  }

  return (x ? 2 : 0);
};

// 凸包
Polygon andrewScan(Polygon s) {
  Polygon u, l;
  if (s.size() < 3) return s;
  sort(s.begin(), s.end());
  // xが小さいものから2つuに追加
  u.push_back(s[0]);
  u.push_back(s[1]);
  // xが大きいものから2つlに追加
  l.push_back(s[s.size() - 1]);
  l.push_back(s[s.size() - 2]);

  for (int i = 2; i < s.size(); i++) {
    for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {
      u.pop_back();
    }
    u.push_back(s[i]);
  }

  for (int i = s.size() - 3; i >= 0; i--) {
    for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {
      l.pop_back();
    }
    l.push_back(s[i]);
  }

  // 反時計周りになるように凸包の点の列を生成
  reverse(l.begin(), l.end());
  for (int i = u.size() - 2; i >= 1; i--) {
    l.push_back(u[i]);
  }

  return l;
};

int main() {
  int n;
  cin >> n;
  Point p;
  Polygon s;
  for (int i = 0; i < n; i++) {
    cin >> p.x >> p.y;
    s.push_back(p);
  }

  Polygon ans = andrewScan(s);

  int min_y_idx = 0;
  double min_y = ans[0].y;

  for (int i = 0; i < ans.size(); i++) {
    if (ans[i].y <  min_y) {
      min_y = ans[i].y;
      min_y_idx = i;
    }
  }

  cout << ans.size() << endl;
  int idx = min_y_idx;
  for (int i = 0; i < ans.size(); i++) {
    cout << (int) ans[idx].x << " " << (int) ans[idx].y << endl;
    if (idx == ans.size() - 1) {
      idx = 0;
    } else {
      idx++;
    }
  }


  return 0;
};
