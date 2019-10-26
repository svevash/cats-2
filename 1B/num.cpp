#include "num.h"

Num::Num(int value, int modulo) {
    if (modulo == 0) {
        this->value = value;
    }
    else {
        this->value = value % modulo;
    }
    this->modulo = modulo;
}

Num::Num(const Num &other) {
    this->value = other.value;
    this->modulo = 0;
}