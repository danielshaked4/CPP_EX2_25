// Email: sone0149@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"
#include <cmath>

using namespace MatrixMath;

TEST_SUITE("SquareMat Tests") {

    TEST_CASE("Constructor and Index Operator") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        REQUIRE(mat1[0][0] == 1);
        REQUIRE(mat1[0][1] == 2);
        REQUIRE(mat1[1][0] == 3);
        REQUIRE(mat1[1][1] == 4);
    }

    TEST_CASE("Addition") {
        SquareMat mat1(2), mat2(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;
        mat2[0][0] = 2; mat2[0][1] = 3;
        mat2[1][0] = 4; mat2[1][1] = 5;

        SquareMat sum = mat1 + mat2;
        REQUIRE(sum[0][0] == 3);
        REQUIRE(sum[0][1] == 5);
        REQUIRE(sum[1][0] == 7);
        REQUIRE(sum[1][1] == 9);
    }

    TEST_CASE("Subtraction") {
        SquareMat mat1(2), mat2(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;
        mat2[0][0] = 2; mat2[0][1] = 3;
        mat2[1][0] = 4; mat2[1][1] = 5;

        SquareMat diff = mat1 - mat2;
        REQUIRE(diff[0][0] == -1);
        REQUIRE(diff[0][1] == -1);
        REQUIRE(diff[1][0] == -1);
        REQUIRE(diff[1][1] == -1);
    }

    TEST_CASE("Unary Minus") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        SquareMat neg = -mat1;
        REQUIRE(neg[0][0] == -1);
        REQUIRE(neg[0][1] == -2);
        REQUIRE(neg[1][0] == -3);
        REQUIRE(neg[1][1] == -4);
    }

    TEST_CASE("Matrix Multiplication") {
        SquareMat mat1(2), mat2(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;
        mat2[0][0] = 2; mat2[0][1] = 3;
        mat2[1][0] = 4; mat2[1][1] = 5;

        SquareMat prod = mat1 * mat2;
        REQUIRE(prod[0][0] == 10);
        REQUIRE(prod[0][1] == 13);
        REQUIRE(prod[1][0] == 22);
        REQUIRE(prod[1][1] == 29);
    }

    TEST_CASE("Scalar Multiplication") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        SquareMat scalar = mat1 * 2.0;
        REQUIRE(scalar[0][0] == 2);
        REQUIRE(scalar[0][1] == 4);
        REQUIRE(scalar[1][0] == 6);
        REQUIRE(scalar[1][1] == 8);
    }

    TEST_CASE("Element-wise Multiplication") {
        SquareMat mat1(2), mat2(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;
        mat2[0][0] = 2; mat2[0][1] = 3;
        mat2[1][0] = 4; mat2[1][1] = 5;

        SquareMat elemProd = mat1 % mat2;
        REQUIRE(elemProd[0][0] == 2);
        REQUIRE(elemProd[0][1] == 6);
        REQUIRE(elemProd[1][0] == 12);
        REQUIRE(elemProd[1][1] == 20);
    }

    TEST_CASE("Modulo") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        SquareMat mod = mat1 % 2;
        REQUIRE(mod[0][0] == 1);
        REQUIRE(mod[0][1] == 0);
        REQUIRE(mod[1][0] == 1);
        REQUIRE(mod[1][1] == 0);
    }

    TEST_CASE("Division") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        SquareMat div = mat1 / 2.0;
        REQUIRE(div[0][0] == 0.5);
        REQUIRE(div[0][1] == 1);
        REQUIRE(div[1][0] == 1.5);
        REQUIRE(div[1][1] == 2);
    }

    TEST_CASE("Power") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        SquareMat pow = mat1 ^ 2;
        REQUIRE(pow[0][0] == 7);
        REQUIRE(pow[0][1] == 10);
        REQUIRE(pow[1][0] == 15);
        REQUIRE(pow[1][1] == 22);
    }

    TEST_CASE("Increment") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        SquareMat inc = mat1;
        ++inc;
        REQUIRE(inc[0][0] == 2);
        REQUIRE(inc[0][1] == 3);
        REQUIRE(inc[1][0] == 4);
        REQUIRE(inc[1][1] == 5);
    }

    TEST_CASE("Transpose") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        SquareMat trans = ~mat1;
        REQUIRE(trans[0][0] == 1);
        REQUIRE(trans[0][1] == 3);
        REQUIRE(trans[1][0] == 2);
        REQUIRE(trans[1][1] == 4);
    }

    TEST_CASE("Equality") {
        SquareMat mat1(2), mat3(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;
        mat3[0][0] = 2; mat3[0][1] = 2;
        mat3[1][0] = 2; mat3[1][1] = 4;

        REQUIRE(mat1 == mat3); 
    }

    TEST_CASE("Comparison") {
        SquareMat mat1(2), mat2(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;
        mat2[0][0] = 2; mat2[0][1] = 3;
        mat2[1][0] = 4; mat2[1][1] = 5;

        REQUIRE(mat1 < mat2);
        REQUIRE(mat2 > mat1);
    }

    TEST_CASE("Determinant") {
        SquareMat mat1(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        double det = !mat1;
        REQUIRE(det == doctest::Approx(-2).epsilon(1e-10));
    }

    TEST_CASE("Compound Assignments") {
        SquareMat mat1(2), mat2(2);
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;
        mat2[0][0] = 2; mat2[0][1] = 3;
        mat2[1][0] = 4; mat2[1][1] = 5;

        SquareMat temp = mat1;
        temp += mat2;
        REQUIRE(temp[0][0] == 3);
        REQUIRE(temp[0][1] == 5);
        REQUIRE(temp[1][0] == 7);
        REQUIRE(temp[1][1] == 9);

        temp = mat1;
        temp *= 2.0;
        REQUIRE(temp[0][0] == 2);
        REQUIRE(temp[0][1] == 4);
        REQUIRE(temp[1][0] == 6);
        REQUIRE(temp[1][1] == 8);
    }

}
