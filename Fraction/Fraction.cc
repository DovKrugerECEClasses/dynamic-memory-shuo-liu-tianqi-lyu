#include "Fraction.hh"

using namespace std;
Fraction::Fraction(int n, int d):num(n), den(d){ // TODO: finish initializer list :
}

//friend
Fraction operator +(const Fraction& a, const Fraction& b) {
    return Fraction(a.num * b.den + a.den * b.num, a.den * b.den);
}

// member operator
Fraction Fraction::operator -(const Fraction& f) const {
    return Fraction(num * f.den - den * f.num, den * f.den);
}

ostream& operator <<(ostream& s, const Fraction& b) {
    s << b.num << "/" << b.den << '\n';
    return s;
}

//just here for illustration, you do not have to do anything
void Fraction::simplify() {
}