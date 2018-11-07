#include <iostream>
using namespace std;

void Read(int &x, int &y) {
    cin >> x >> y;
}

bool CheckDigit(int number, int digit) {
    while (number != 0) {
        if (number % 10 == digit)
            return true;
        number /= 10;
    }
    return false;
}

bool Alike(int number1, int number2) {
    if (number1 == number2)
        return true;
    int aux = number1;
    while (number1 != 0) {
        if (!CheckDigit(number2, number1 % 10))
            return false;
        number1 /= 10;
    }
    while (number2 != 0) {
        if (!CheckDigit(aux, number2 % 10))
            return false;
        number2 /= 10;
    }
    return true;
}

int main() {
    int x, y;
    //Read(x, y);
    cout << Alike(1222331, 123) << '\n';
    cout << Alike(122235, 123) << '\n';
    cout << Alike(5656565, 56) << '\n';
    cout << Alike(5656565, 5) << '\n';
    cout << Alike(1, 8) << '\n';
    return 0;
}
