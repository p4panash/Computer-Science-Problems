#include <iostream>
using namespace std;

struct matrix {
    int row;
    int column;
    int value;
};

bool IsUnique(matrix a[], matrix value, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i].row == value.row && a[i].column == value.column)
            return false;
    }
    return true;
}

void ReadSize(int &n, int &m) {
    cin >> n >> m;
}

void ReadMatrix(matrix a[], int &sizeA) {
    sizeA = 0;
    matrix input;
    cin >> input.row >> input.column >> input.value;
    while (input.row != -1 && input.column != -1 && input.value != -1) {
        if (IsUnique(a, input, sizeA)) {
            a[sizeA] = input;
            sizeA++;
        }
        cin >> input.row >> input.column >> input.value;
    }
}

int GetValue(matrix a[], int sizeA, matrix element) {
    for (int i = 0; i < sizeA; i++)
        if (a[i].row == element.row && a[i].column == element.column)
            return a[i].value;
    return -1;
}

void AddMatrix(matrix a[], int sizeA, matrix b[], int sizeB, matrix c[], int &sizeC) {
    sizeC = 0;
    for (int i = 0; i < sizeA; i++) {
        if (GetValue(b, sizeB, a[i]) == -1) {
            c[sizeC] = a[i];
            sizeC++;
        } else {
            c[sizeC] = a[i];
            c[sizeC].value += GetValue(b, sizeB, a[i]);
            sizeC++;
        }
    }
    for (int i = 0; i < sizeB; i++) {
        if (GetValue(a, sizeA, b[i]) == -1) {
            c[sizeC] = b[i];
            sizeC++;
        }
    }
}

void PrintMatrix(matrix c[], int sizeC, int n, int m) {
    matrix element;
    for (int i = 1; i <= n; i++) {
        element.row = i;
        for (int j = 1; j <= m; j++) {
            element.column = j;
            if (GetValue(c, sizeC, element) != -1) {
                cout << GetValue(c, sizeC, element) << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    const int MAX_SIZE = 10025;
    matrix a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
    int sizeA, sizeB, sizeC;

    ReadSize(n, m);
    ReadMatrix(a, sizeA);
    ReadMatrix(b, sizeB);

    AddMatrix(a, sizeA, b, sizeB, c, sizeC);
    PrintMatrix(c, sizeC, n, m);
}
