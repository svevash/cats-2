#include <cstdint>
#include "num.h"

Num::Num(int val, int mod) : value(val % mod), modulo(mod) {}

Num& Num::operator=(const Num &other) = default;

Num Num::operator+(const Num &other) {
    int64_t tmp = value + other.value;
    tmp %= modulo;
    int v = static_cast<int>(tmp);
    Num res(v, modulo);
    return res;
}

Num Num::operator+(int num) {
    int64_t tmp = value + num;
    tmp %= modulo;
    int v = static_cast<int>(tmp);
    Num res(v, modulo);
    return res;
}

Num& Num::operator+=(int num) {
    int64_t tmp = value + num;
    tmp %= modulo;
    value = static_cast<int>(tmp);
    return *this;
}

Num& Num::operator+=(const Num &other) {
    int64_t tmp = value + other.value;
    tmp %= modulo;
    value = static_cast<int>(tmp);
    return *this;
}

Num Num::operator-(int num) {
    Num res(value - num, modulo);
    return res;
}

Num Num::operator-(const Num &other) {
    Num res(value - other.value, modulo);
    return res;
}

Num& Num::operator-=(int num) {
    value = (value - num) % modulo;
    return *this;
}

Num& Num::operator-=(const Num &other) {
    value = (value - other.value) % modulo;
    return *this;
}

Num Num::operator*(int num) {
    int64_t tmp = value * num;
    tmp %= modulo;
    Num res(static_cast<int>(tmp), modulo);
    return res;
}

Num Num::operator*(const Num &other) {
    int64_t tmp = value * other.value;
    tmp %= modulo;
    Num res(static_cast<int>(tmp), modulo);
    return res;
}

Num& Num::operator*=(int num) {
    int64_t tmp = value * num;
    tmp %= modulo;
    value = static_cast<int>(tmp);
    return *this;
}

Num& Num::operator*=(const Num &other) {
    int64_t tmp = value * other.value;
    tmp %= modulo;
    value = static_cast<int>(tmp);
    return *this;
}

