#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * ------------------------------------------------------------
 * Algorithm Challenge – Level 3 | #18 Intersected Numbers in Two Matrices (3x3)
 *
 * This program prints the numbers that appear in BOTH matrices.
 * The algorithm traverses the first matrix and checks whether each element exists in the second matrix.
 *
 * Core concepts:
 * - Matrix-to-matrix comparison
 * - Reusing search logic across algorithms
 * - Nested traversal and value matching
 * - Thinking in terms of set intersection
 *
 * Author: Ahmad Sindi
 * Language: C++
 * ------------------------------------------------------------
 */

// Prints a 3x3 matrix in a formatted layout
void PrintMatrix(int arr[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            cout << setw(3) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

// Checks whether a number exists in a given matrix
bool IsNumInMatrix(int Matrix1[3][3], int Number, short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}

// Prints numbers that exist in both matrices
void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Colms)
{
    int Number;

    // Traverse the first matrix
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            // Take each element from Matrix1
            Number = Matrix1[i][j];

            // Check if it exists in Matrix2
            if (IsNumInMatrix(Matrix2, Number, Rows, Colms))
            {
                cout << setw(3) << Number << "   ";
            }
        }
    }
}

int main()
{
    int Matrix1[3][3] = {
        {55, 77, 1},
        {5, 24, 62},
        {85, 7, 14}};

    int Matrix2[3][3] = {
        {18, 62, 24},
        {7, 35, 55},
        {77, 1, 45}};

    cout << "Matrix 1:\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix 2:\n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers are:\n";
    PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

    return 0;
}
