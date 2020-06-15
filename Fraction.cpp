#include <bits/stdc++.h>
using namespace std;

class Fraction {
public:
  long long numerator, denominator;
  long long sign;
  Fraction(long long n, long long d, long long s = 0, bool fixed = false) {
    assert(d != 0);
    if (!fixed) {
      if (d == 0) {
        numerator = 0; denominator = 1; sign = 0;
      } else {
        if ((n > 0 && d > 0) || (n < 0 && d < 0)) sign = 1;
        else sign = -1;

        n = abs(n); d = abs(d);
        long long g = __gcd(n, d);
        numerator = n/g; denominator = d/g;
      }
    } else {
      numerator = n; denominator = d; sign = s;
    }
  }

  const Fraction operator+(const Fraction f) const {
    return Fraction(*this) += f;
  }
  const Fraction operator-(const Fraction f) const {
    return Fraction(*this) -= f;
  }
  const Fraction operator*(const Fraction f) const {
    return Fraction(*this) *= f;
  }
  const Fraction operator/(const Fraction f) const {
    return Fraction(*this) /= f;
  }
  const Fraction &operator+=(const Fraction f) {
    long long g = __gcd(denominator, f.denominator);
    long long tmp1 = denominator/g, tmp2 = f.denominator/g;
    long long n = sign*numerator*tmp2+f.sign*f.numerator*tmp1;
    long long d = tmp1*tmp2*g;
    long long s;
    if (n == 0) {
      numerator = 0; d = 1; sign = 0; return *this;
    }

    if ((n > 0 && d > 0) || (n < 0 && d < 0)) sign = 1ll;
    else sign = -1ll;

    n = abs(n); d = abs(d);
    long long g_ = __gcd(n, d);
    numerator = n/g_; denominator = d/g_;
    return *this;
  }

  const Fraction &operator-=(const Fraction f) {
    long long g = __gcd(denominator, f.denominator);
    long long tmp1 = denominator/g, tmp2 = f.denominator/g;
    long long n = sign*numerator*tmp2-f.sign*f.numerator*tmp1;
    long long d = tmp1*tmp2*g;
    long long s;
    if (n == 0) {
      numerator = 0; d = 1; sign = 0; return *this;
    }

    if ((n > 0 && d > 0) || (n < 0 && d < 0)) sign = 1ll;
    else sign = -1ll;

    n = abs(n); d = abs(d);
    long long g_ = __gcd(n, d);
    numerator = n/g_; denominator = d/g_;
    return *this;
  }

  const Fraction &operator*=(const Fraction f) {
    if ((sign&f.sign)==0) {
      numerator = 0; denominator = 1; sign = 0; return *this;
    }
    long long g1 = __gcd(numerator, f.denominator);
    long long g2 = __gcd(denominator, f.numerator);
    numerator = (numerator/g1)*(f.numerator/g2);
    denominator = (denominator/g2)*(f.denominator/g1);
    sign = sign*f.sign;
    return *this;
  }

  const Fraction operator/=(const Fraction f) {
    assert(f.sign != 0);
    if (sign == 0) return Fraction(0, 1, 0, true);
    long long g1 = __gcd(numerator, f.numerator);
    long long g2 = __gcd(denominator, f.denominator);
    numerator = (numerator/g1)*(f.denominator/g2);
    denominator = (denominator/g2)*(f.numerator/g1);
    sign = sign*f.sign;
    return *this;
  }

  const bool operator==(const Fraction f) {
    return (numerator == f.numerator && denominator == f.denominator && sign == f.sign);
  }
  const bool operator<(const Fraction f) {
    long long g1 = __gcd(numerator, f.numerator);
    long long g2 = __gcd(denominator, f.denominator);
    return sign*(numerator/g1)*(f.denominator/g2) < f.sign*(f.numerator/g1)*(denominator/g2);
  }
  const bool operator<=(const Fraction f) {
    long long g1 = __gcd(numerator, f.numerator);
    long long g2 = __gcd(denominator, f.denominator);
    return sign*(numerator/g1)*(f.denominator/g2) <= f.sign*(f.numerator/g1)*(denominator/g2);
  }
  const bool operator>(const Fraction f) {
    long long g1 = __gcd(numerator, f.numerator);
    long long g2 = __gcd(denominator, f.denominator);
    return sign*(numerator/g1)*(f.denominator/g2) > f.sign*(f.numerator/g1)*(denominator/g2);
  }
  const bool operator>=(const Fraction f) {
    long long g1 = __gcd(numerator, f.numerator);
    long long g2 = __gcd(denominator, f.denominator);
    return sign*(numerator/g1)*(f.denominator/g2) <= f.sign*(f.numerator/g1)*(denominator/g2);
  }

  friend ostream &operator<<(std::ostream &out, const Fraction &f) {
    if (f.sign == 0ll) {
      out << 0;
      return out;
    } else if (f.sign == 1ll) {
      out << f.numerator << "/" << f.denominator;
      return out;
    } else {
      out << "-" << f.numerator << "/" << f.denominator;
      return out;
    }
  }
};

int main() {
  Fraction a(-10, 21);
  Fraction b(3, 5);
  Fraction c(-20, 42);
  vector<Fraction> tmp;
  tmp.push_back(a);
  tmp.push_back(b);
  tmp.push_back(c);
  sort(tmp.begin(), tmp.end());
  for (Fraction f: tmp) {
    cout << f << endl;
  }
};
