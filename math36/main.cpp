#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

template <typename T>
int findN(T eps) {
    int n = 1;
    while (( pow(2.0, n + 1) / pow(n + 2, n + 1)) - eps < std::numeric_limits<double>::epsilon()) {
        n++;
    }
    return n + 1;
}

int main() {
    double eps = 0;
    std::string str;
    std::cin >> str;
    eps = stod(str);
    int N = findN(eps < 10e-7 ? float(eps) : double(eps));

    double res = 0;
    double sum = 0;
    for (auto i = 1; i <= N; i++) {
        res = (pow((-1.0), i) * pow(2.0, i)) / pow(i + 1, i);
        sum += res;
    }

    std::cout << std::fixed << std::setprecision(abs(log10(eps))) << sum;
    return 0;
}