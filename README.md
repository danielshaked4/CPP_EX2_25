
# CPP_EX2_25

## Overview

This project implements a `SquareMat` class for square matrix operations. It provides a set of matrix operations, including arithmetic, comparison, and matrix-specific operations like transpose and determinant calculation.

Key features:
- Matrix creation and memory management
- Arithmetic operations (addition, subtraction, multiplication, scalar operations)
- Modulo operations
- Matrix power, transpose, and determinant
- Comparison operators based on element sums
- Increment/decrement operators

## File Structure

- `SquareMat.h`, `SquareMat.cpp`: Implementation of the `SquareMat` class with matrix operations.
- `Main.cpp`: Demonstrates basic usage of the `SquareMat` class.
- `Tests.cpp`: Unit tests for `SquareMat` operations using the Doctest library.
- `Makefile`: Build instructions, test execution, and memory leak checking.
- `doctest.h`: External testing library included in the project.

## Makefile Commands

- `make Main`: Compiles and builds the main program (`Main.cpp`).
- `make test`: Compiles and runs unit tests from `Tests.cpp`.
- `make valgrind`: Runs the main program with Valgrind to check for memory leaks.
- `make clean`: Removes executable files (`Main`, `Tests`) and object files.
