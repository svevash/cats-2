#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>
using namespace std;

template <typename T>
T sum(T eps) {
    unsigned long long n = 1;
    T s = 0;
    T a;
    T a1 = 0.5;
    while (abs(a1) > eps) {
        n++;
        a = n / (n + pow(3, n));
        s += a;
        a1 = (n + 2) / ((2 * pow(3, n )));
    }
    return  s;
}

int main() {
    double eps = 0;
    cin >> eps;
    if (eps < 10e-7) {
        cout << fixed << setprecision(abs(log10(eps))) << sum(float(eps));
    }
    else {
        cout << fixed << setprecision(abs(log10(eps)))  << sum(double(eps));
    }
    return 0;
}