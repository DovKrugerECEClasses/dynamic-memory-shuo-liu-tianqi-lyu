#include <iostream>
using namespace std;

template <typename T>

void sort(T a[], int b){
    for (int i = 0; i < b - 1; i++) {
        for (int j = 0; j < b - 1; j++) {
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

T sum(T a[], int b){
    T sum = 0;
    for (int i = 0; i < b; i++) {
        sum += a[i];
    }
    return sum;
}

void print(T a[], int b){
    for (int i = 0; i < b; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
    sort(a, sizeof(a)/sizeof(int));
    print(a, sizeof(a)/sizeof(int));

    double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
    sort(b, sizeof(b)/sizeof(double));
    print(b, sizeof(b)/sizeof(double));

    cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
    cout << sum(b, sizeof(b)/sizeof(double)) << '\n';

    string c[] = {"yo", "ho", "test", "foo", "bar"};
    sort(c, sizeof(c)/sizeof(string));
    print(c, sizeof(c)/sizeof(string));
    //TODO?	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}