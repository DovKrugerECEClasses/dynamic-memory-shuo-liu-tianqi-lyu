#pragma once
#include <iostream>

using namespace std;

class Fraction {
private:
    int num, den;
    void simplify();
public:
    Fraction(int n, int d);
    friend Fraction	operator +(const Fraction& a, const Fraction& b);
    Fraction operator -(const Fraction& c)const ;
    friend ostream& operator <<(ostream& s, const Fraction& f);
};