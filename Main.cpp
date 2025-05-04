// Email: sone0149@gmail.com

#include "SquareMat.h"
#include <iostream>

using namespace MatrixMath;

int main() {
    try {
        // Create two 2x2 matrices
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        SquareMat mat2(2);
        mat2[0][0] = 2; mat2[0][1] = 3;
        mat2[1][0] = 4; mat2[1][1] = 5;

        std::cout << "Matrix 1:\n" << mat1 << std::endl;
        std::cout << "Matrix 2:\n" << mat2 << std::endl;
        std::cout << "Sum:\n" << (mat1 + mat2) << std::endl;
        std::cout << "Product:\n" << (mat1 * mat2) << std::endl;
        std::cout << "Scalar multiply:\n" << (mat1 * 2.0) << std::endl;
        std::cout << "Transpose of Matrix 1:\n" << (~mat1) << std::endl;
        std::cout << "Determinant of Matrix 1: " << !mat1 << std::endl;

    } catch (const MatrixException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}