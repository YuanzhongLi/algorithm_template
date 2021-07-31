#define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

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

const long double eps = 1e-10;
// solve Ax = b, A shoulde be square matrix
// if no solution or solution is not unique, return size 0 vector
vector<long double> gauss_jordan(vector<vector<long double>> A, vector<long double> b) {
  int n = A.size();
  vector<vector<long double>> B(n, vector<long double> (n+1)); // B = [A, b]
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) B[i][j] = A[i][j];
  for (int i=0; i<n; i++) B[i][n] = b[i];

  for (int i=0; i<n; i++) {
    // put the largest |coefficient| to the current place:i (this is for smaller error)
    int pivot = i;
    for (int j=0; j<n; j++) if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
    swap(B[i], B[pivot]);

    if (abs(B[i][i]) < eps) return vector<long double>();

    for (int j=i+1; j<=n; j++) B[i][j] /= B[i][i];
    for (int j=0; j<n; j++) {
      if (i != j) {
        for (int k=i+1; k<=n; k++) B[j][k] -= B[j][i]*B[i][k];
      }
    }
  }
  vector<long double> x(n);
  for (int i=0; i<n; i++) x[i] = B[i][n];
  return x;
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
};
