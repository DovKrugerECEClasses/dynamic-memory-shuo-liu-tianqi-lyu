#pragma once
#include <iostream>

using namespace std;

class Fraction {
private:
    int num, den;
    void simplify();
public:
    Fraction(int n, int d);
    friend Fraction	operator +(Fraction left, Fraction right);
    Fraction operator -(Fraction f);
    friend ostream& operator <<(ostream& s, Fraction f);
};