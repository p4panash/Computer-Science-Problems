#include <iostream>
using namespace std;

void Read(int values[], int &lenght) {
    lenght = 0;
    int number;
    cin >> number;
    while (number != 0) {
        values[lenght] = number;
        lenght++;
        cin >> number;
    }
}

int WalkThroughTribonacci(int values[], int startPoint, int lenght) {
    int a = 1, b = 1, c = 2;
    int i = startPoint;
    if (i + 1 < lenght && values[i] == 1 && values[i + 1] == 1) {
        i += 2;
    } else if (values[i] == 1) {
        i++;
    } else while (values[i] < c) {
        int aux = c;
        c = a + b + c;
        a = b;
        b = aux;
    }
    while (i < lenght && values[i] == c) {
        i++;
        int aux = c;
        c = a + b + c;
        a = b;
        b = aux;
    }
    return i;
}

void GetMaximalSubList(int values[], int lenght, int &startPos, int &endPos) {
    int i = 0, max = -1;
    while (i < lenght) {
        int j = WalkThroughTribonacci(values, i, lenght);
        if (j - i > max) {
            startPos = i;
            endPos = j;
            max = j - i;
        }
        if (j == i) {
            i++;
        } else {
            i = j;
        }
    }
}

void PrintSolution(int values[], int startPos, int endPos) {
    if (endPos - startPos < 0) {
        cout << "There is no Tribonacci sublist !";
    } else {
        for (int i = startPos; i < endPos; i++)
            cout << values[i] << " ";
    }
}

int main() {
    const int MAX_SIZE = 1005;
    int values[MAX_SIZE], lenght = 0;

    Read(values, lenght);

    int startPos = -1, endPos = -1;
    GetMaximalSubList(values, lenght, startPos, endPos);
    PrintSolution(values, startPos, endPos);
}
