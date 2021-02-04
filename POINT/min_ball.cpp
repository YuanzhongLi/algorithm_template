// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n; i > (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
// #define M_PI 3.14159265358979323846 // CF
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // print Decimal number 10 Rank
#define endl "\n"
#define Case(x) printf("Case #%d: ", x); // gcj

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;

constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1002003004;
constexpr int n_max = 2e5+10;

template<class T>
inline bool chmax(T &a, T b) { if(a<b) { a=b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a>b) { a=b; return true; } return false; };

template<class T, class U>
T POW(T x, U n) {T ret=1; while (n>0) {if (n&1) {ret*=x;} x*=x; n>>=1;} return ret;};

// debug
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';};
string to_string(const char c) {return to_string((string) &c);};
string to_string(bool b) {return (b ? "true" : "false");};
template <size_t N>
string to_string(bitset<N> v){
  string res = "";
  for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
};
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for(const auto &x : v) {
    if(!first) res += ", ";
    first = false; res += to_string(x);
  }
  res += "}";
  return res;
};
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;};
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); };

void LINE_OUT() {
  cout << "--------------" << endl;
};

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define LINE LINE_OUT();
#else
#define debug(...) 71
#define LINE 71;
#endif

void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
};

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
};

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
};

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point {
  public:
  long double x, y;

  Point(long double x = 0, long double y = 0): x(x), y(y) {}

  Point operator + (Point p) { return Point(x + p.x, y + p.y); }
  Point operator - (Point p) { return Point(x - p.x, y - p.y); }
  Point operator * (long double a) { return Point(a * x, a * y); }
  Point operator / (long double a) { return Point(x / a, y / a); }

  long double abs() { return sqrtl(norm()); }
  long double norm() { return x * x + y * y; }

  bool operator < (const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

std::ostream &operator<<(std::ostream &out, const Point &p) {
  out << '(' << p.x << ", " << p.y << ')';
  return out;
}

class Circle {
  public:
    Point c;
    long double r;
    Circle(Point c = Point(), long double r = 0.0): c(c), r(r) {}
};

struct Segment {
  Point p1, p2;
};

typedef Point Vector;
typedef Segment Line;

long double norm(Vector a) {
  return a.x * a.x + a.y * a.y;
};

long double abs(Vector a) {
  return sqrtl(norm(a));
};

// 内積
long double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
};

// 外積
long double cross(Vector a, Vector b) {
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
  long double r = dot(p - s.p1, base) / base.norm();
  return s.p1 + base * r;
};

// 反射
Point reflect(Segment s, Point p) {
  return p + (project(s, p) - p) * 2.0;
};

// 回転
Point rot(Point p, long double ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y); };
Point rot90(Point p) { return Point(-p.y, p.x); };

// 点と点の距離
long double getDistance(Point a, Point b) {
  return abs(a - b);
};

// 点と直線の距離
long double getDistanceLP(Line l, Point p) {
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
};

// 点と線分の距離
long double getDistanceSP(Segment s, Point p) {
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
long double getDistance(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)), min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
};

// 線分と線分の交点(必ず交点があり、それがどちらかの端点出ない)
Point getCrossPoint(Segment s1, Segment s2) {
  long double d = cross(s2.p2-s2.p1, s1.p2-s1.p1);
  return s1.p1 + (s1.p2-s1.p1) * cross(s2.p2-s2.p1, s2.p2-s1.p1) / d;
};

// 円cと線分lの交点
pair<Point, Point> getCrossPoints(Circle c, Line l) {
  assert(intersect(c, l));
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
  long double base = sqrtl(c.r * c.r - norm(pr - c.c));
  return make_pair(pr + e * base, pr - e * base);
};

long double arg(Vector p) { return atan2(p.y, p.x); };
Vector polar(long double a, long double r) { return Point(cos(r) * a, sin(r) * a); };

// circle c1とcircle c2の交点
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
  assert(intersect(c1, c2));
  long double d = abs(c1.c - c2.c);
  long double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  long double t = arg(c2.c - c1.c);
  return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
};

// 外心
Point gaisin(Point a, Point b, Point c) {
  Line ab = {(a+b)/2, (a+b)/2 + rot90(a-b)};
  Line bc = {(b+c)/2, (b+c)/2 + rot90(b-c)};
  return getCrossPoint(ab, bc);
};

typedef vector<Point> Polygon;

// VERIFICATIOIN: ABC 151_F
// URL: https://atcoder.jp/contests/abc151/submissions/19911467
// O(N^4)
Circle min_ball(Polygon polygon) {
  int N = polygon.size();
  if (N <= 1) {
    return Circle(); // x: 0, y: 0, r:0
  } else if (N == 2) {
    long double dist = getDistance(polygon[0], polygon[1]);
    long double r = dist/2.0;
    return Circle((polygon[0]+polygon[1])/2, r);
  }

  Polygon alt;
  for (int i=0; i<N; i++) {
    for (int j =i+1; j<N; j++) {
      alt.push_back((polygon[i]+polygon[j])/2);
      for (int k = j+1; k < N; k++) {
        int state = ccw(polygon[i], polygon[j], polygon[k]);
        if (!(state == CLOCKWISE || state == COUNTER_CLOCKWISE)) continue;
        Point p = gaisin(polygon[i], polygon[j], polygon[k]);
        alt.push_back(p);
      }
    }
  }

  const long double LDINF = 1e18;
  Circle ret(Point(), LDINF);
  for (Point c: alt) {
    long double r = 0.0;
    for (Point p: polygon) chmax(r, getDistance(p, c));
    if (chmin(ret.r, r)) ret.c = c;
  }

  return ret;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  Polygon polygon(N);
  rep(i, 0, N) cin >> polygon[i].x >> polygon[i].y;

  auto ans = min_ball(polygon);

  Decimal(ans.r);

  return 0;
};
