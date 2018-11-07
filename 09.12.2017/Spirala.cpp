#include <iostream>
using namespace std;

const int MAX_SIZE = 101;

void Read(int &n, int &m) {
    cin >> n >> m;
}

bool IsPrime(int number) {
    if (number < 2)
        return false;
    for (int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int NextPrimeNumber(int number) {
    number++;
    while (!IsPrime(number))
        number++;
    return number;
}

void initMatrix(int matrix[][MAX_SIZE], int n, int m) {
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = 0;
}

void BuildMatrix(int matrix[][MAX_SIZE], int n, int m) {
    int filledElements = 0;
    int i = 0, j = 0;
    int lastElement = 0;
    bool horizontal = true;
    bool ascending = true;
    while (filledElements < n * m) {
        if (matrix[i][j] == 0) {
            int prime = NextPrimeNumber(lastElement);
            matrix[i][j] = prime;
            lastElement = prime;
            filledElements++;
        }
        if (horizontal) {
            if (ascending) {
                if (j + 1 < m && matrix[i][j + 1] == 0) {
                    j++;
                } else {
                    horizontal = false;
                }
            } else {
                if (j - 1 >= 0 && matrix[i][j - 1] == 0) {
                    j--;
                } else {
                    horizontal = false;
                }
            }
        } else {
            if (ascending) {
                if (i + 1 < n && matrix[i + 1][j] == 0) {
                    i++;
                } else {
                    ascending = false;
                    horizontal = true;
                }
            } else {
                if (i - 1 >= 0 && matrix[i - 1][j] == 0) {
                    i--;
                } else {
                    ascending = true;
                    horizontal = true;
                }
            }
        }
    }
}

void PrintMatrix(int matrix[][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    Read(n, m);
    initMatrix(matrix, n, m);
    BuildMatrix(matrix, n, m);

    PrintMatrix(matrix, n, m);
}
