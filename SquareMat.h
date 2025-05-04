// Email: sone0149@gmail.com

#ifndef SQUARE_MAT_H
#define SQUARE_MAT_H

#include <stdexcept>
#include <iostream>

namespace MatrixMath {

class SquareMat {
private:
    double** data;
    int size;

    void allocate(int n);
    void deallocate();

    double determinantHelper(double** mat, int n) const;

    void getMinor(double** src, double** dest, int row, int col, int n) const;

public:
    SquareMat(int n);
    SquareMat(const SquareMat& other);
    ~SquareMat();

    SquareMat& operator=(const SquareMat& other);

    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator-() const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator*(double scalar) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator^(int power) const;

    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(int scalar);

    SquareMat& operator++();    
    SquareMat operator++(int);  
    SquareMat& operator--();    
    SquareMat operator--(int);  
    SquareMat operator~() const;
    double* operator[](int i) const;
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;
    double operator!() const;

    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
    friend SquareMat operator*(double scalar, const SquareMat& mat);
};

class MatrixException : public std::runtime_error {
public:
    MatrixException(const std::string& message) : std::runtime_error(message) {}
};

} 

#endif