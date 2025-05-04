// Email: sone0149@gmail.com

#include "SquareMat.h"
#include <cmath>

namespace MatrixMath {

void SquareMat::allocate(int n) {
    if (n <= 0) throw MatrixException("Matrix size must be positive");
    data = new double*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new double[n]();
    }
    size = n;
}

void SquareMat::deallocate() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

SquareMat::SquareMat(int n) {
    allocate(n);
}

SquareMat::SquareMat(const SquareMat& other) {
    allocate(other.size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

SquareMat::~SquareMat() {
    deallocate();
}

SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this != &other) {
        deallocate();
        allocate(other.size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) throw MatrixException("Matrix sizes must match");
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) throw MatrixException("Matrix sizes must match");
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = -data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) throw MatrixException("Matrix sizes must match");
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) throw MatrixException("Matrix sizes must match");
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0) throw MatrixException("Modulo by zero");
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = fmod(data[i][j], scalar);
        }
    }
    return result;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0) throw MatrixException("Division by zero");
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

SquareMat SquareMat::operator^(int power) const {
    if (power < 0) throw MatrixException("Negative power not supported");
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i][i] = 1.0;
    }
    SquareMat base = *this;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        power /= 2;
    }
    return result;
}

SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += 1.0;
        }
    }
    return *this;
}

SquareMat SquareMat::operator++(int) {
    SquareMat temp = *this;
    ++(*this);
    return temp;
}

SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] -= 1.0;
        }
    }
    return *this;
}

SquareMat SquareMat::operator--(int) {
    SquareMat temp = *this;
    --(*this);
    return temp;
}

SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[j][i];
        }
    }
    return result;
}

double* SquareMat::operator[](int i) const {
    if (i < 0 || i >= size) throw MatrixException("Index out of bounds");
    return data[i];
}

bool SquareMat::operator==(const SquareMat& other) const {
    if (size != other.size) return false;
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            sum1 += data[i][j];
            sum2 += other.data[i][j];
        }
    }
    return fabs(sum1 - sum2) < 1e-10;
}

bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

bool SquareMat::operator<(const SquareMat& other) const {
    if (size != other.size) throw MatrixException("Matrix sizes must match for comparison");
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            sum1 += data[i][j];
            sum2 += other.data[i][j];
        }
    }
    return sum1 < sum2;
}

bool SquareMat::operator>(const SquareMat& other) const {
    return other < *this;
}

bool SquareMat::operator<=(const SquareMat& other) const {
    return !(*this > other);
}

bool SquareMat::operator>=(const SquareMat& other) const {
    return !(*this < other);
}

void SquareMat::getMinor(double** src, double** dest, int row, int col, int n) const {
    int r = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (i != row) {
            c = 0;
            for (int j = 0; j < n; ++j) {
                if (j != col) {
                    dest[r][c] = src[i][j];
                    ++c;
                }
            }
            ++r;
        }
    }
}

double SquareMat::determinantHelper(double** mat, int n) const {
    if (n == 1) return mat[0][0];
    double det = 0;
    double** temp = new double*[n];
    for (int i = 0; i < n; ++i) {
        temp[i] = new double[n];
    }
    int sign = 1;
    for (int j = 0; j < n; ++j) {
        getMinor(mat, temp, 0, j, n);
        det += sign * mat[0][j] * determinantHelper(temp, n - 1);
        sign = -sign;
    }
    for (int i = 0; i < n; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
    return det;
}

double SquareMat::operator!() const {
    return determinantHelper(data, size);
}

SquareMat& SquareMat::operator+=(const SquareMat& other) {
    *this = *this + other;
    return *this;
}

SquareMat& SquareMat::operator-=(const SquareMat& other) {
    *this = *this - other;
    return *this;
}

SquareMat& SquareMat::operator*=(const SquareMat& other) {
    *this = *this * other;
    return *this;
}

SquareMat& SquareMat::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

SquareMat& SquareMat::operator/=(double scalar) {
    *this = *this / scalar;
    return *this;
}

SquareMat& SquareMat::operator%=(const SquareMat& other) {
    *this = *this % other;
    return *this;
}

SquareMat& SquareMat::operator%=(int scalar) {
    *this = *this % scalar;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            os << mat.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

} 