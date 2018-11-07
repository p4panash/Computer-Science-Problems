#include <iostream>
using namespace std;

void Read(long matrix[][2], long &n) {
    cin >> n;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> matrix[i][j];
}

void init(long matrix [][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            matrix[i][j] = 0;
}

void Add(long matrix[][2], long matrix2[][2]) {
    matrix[0][0] += matrix2[0][0];
    matrix[0][1] += matrix2[0][1];
    matrix[1][0] += matrix2[1][0];
    matrix[1][1] += matrix2[1][1];
}

void Multiply(long matrix[][2], long matrix2[][2], long matrix3[][2]) {
    matrix3[0][0] = matrix[0][0] * matrix2[0][0] + matrix[0][1] * matrix2[1][0];
    matrix3[0][1] = matrix[0][0] * matrix2[0][1] + matrix[0][1] * matrix2[1][1];
    matrix3[1][0] = matrix[1][0] * matrix2[0][0] + matrix[1][1] * matrix2[1][0];
    matrix3[1][1] = matrix[1][0] * matrix2[0][1] + matrix[1][1] * matrix2[1][1];
}

void MatrixEquals(long matrix[][2], long matrix2[][2]) {
    matrix[0][0] = matrix2[0][0];
    matrix[0][1] = matrix2[0][1];
    matrix[1][0] = matrix2[1][0];
    matrix[1][1] = matrix2[1][1];
}

int Sum(long matrix[][2], long sum[][2], long n) {
    long initialMatrix[2][2];
    MatrixEquals(initialMatrix, matrix);
    init(sum);
    for (int i = 0; i < n; i++) {
        Add(sum, matrix);
        long result[2][2];
        Multiply(matrix, initialMatrix, result);
        MatrixEquals(matrix, result);
    }
}

int Modulo(long matrix[][2], long prime) {
    matrix[0][0] = matrix[0][0] % prime;
    matrix[0][1] = matrix[0][1] % prime;
    matrix[1][0] = matrix[1][0] % prime;
    matrix[1][1] = matrix[1][1] % prime;
}

void Print(long matrix[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    long n;
    long matrix[2][2];
    long sum[2][2];
    Read(matrix, n);
    Sum(matrix, sum, n);
    //Modulo(sum, 66601);
    Print(sum);
}
