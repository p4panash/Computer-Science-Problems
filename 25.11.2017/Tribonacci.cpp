#include <iostream>
using namespace std;

void Read(int data[], int &lenght) {
    lenght = 0;
    int number;
    cin >> number;
    while (number != 0) {
        data[lenght] = number;
        lenght++;
        cin >> number;
    }
}

bool IsTribonacci(int number) {
    int a = 0;
    int b = 1;
    int c = 1;
    while (c < number) {
        int aux = c;
        c = a + b + c;
        a = b;
        b = aux;
    }
    if (c == number)
        return true;
    return false;
}

bool SubListIsTribonacci(int data[], int startPos, int endPos) {
    int a = 1;
    int b = 1;
    int c = 2;
    if (data[startPos] == 1 && data[startPos + 1] == 1) {
        startPos+=2;
    } else if (data[startPos] == 1) {
        startPos++;
    } else {
        while (c < data[startPos]) {
            int aux = c;
            c = a + b + c;
            a = b;
            b = aux;
        }
    }
    for (int i = startPos; i < endPos; i++) {
        if (c != data[i]) {
            return false;
        } else {
            int aux = c;
            c = a + b + c;
            a = b;
            b = aux;
        }
    }
    return true;
}

void GetMaximalSubList(int data[], int lenght, int &startPos, int &endPos) {
    int max = 0;
    for (int i = 0; i < lenght; i++) {
        if (IsTribonacci(data[i])) {
            for (int j = i; j < lenght; j++) {
                if (SubListIsTribonacci(data, i, j)) {
                    if ((j - i) + 1 > max) {
                        startPos = i;
                        endPos = j;
                        max = (j - i) + 1;
                    }
                }
            }
        }
    }
}

void PrintResult(int data[], int startPos, int endPos) {
    for (int i = startPos; i < endPos; i++)
        cout << data[i] << " ";
    cout << endl;
}

int main() {
    int const MAX_SIZE = 1005;
    int data[MAX_SIZE];
    int lenght = 0;

    Read(data, lenght);

    int startPos = -1, endPos = -1;

    //cout << SubListIsTribonacci(data, 6, 16);
    GetMaximalSubList(data, lenght, startPos, endPos);
    PrintResult(data, startPos, endPos);
}
