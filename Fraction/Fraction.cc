#include "Fraction.hh"

using namespace std;
Fraction::Fraction(int n, int d):num(n), den(d){ // TODO: finish initializer list :
}

//friend
Fraction operator +(const Fraction& a, const Fraction& b) {
    return Fraction(a.num * b.den + a.den * b.num, a.den * b.den);
}

// member operator
Fraction Fraction::operator -(const Fraction& c) const {
    return Fraction(num * c.den - den * c.num, den * c.den);
}

ostream& operator <<(ostream& s, const Fraction& f) {
    s << f.num << "/" << f.den << '\n';
    return s;
}

//just here for illustration, you do not have to do anything
void Fraction::simplify() {
}