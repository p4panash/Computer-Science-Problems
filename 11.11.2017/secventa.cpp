#include <iostream>
using namespace std;

void Read(int &k) {
    cin >> k;
}

bool IsPrime(int number) {
    if (number < 2)
        return false;
    for (int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int NextPrimeDivisor(int div, int number) {
    while (div <= number / 2) {
        div++;
        if (IsPrime(div) && number % div == 0 && div < number)
            return div;
    }
    return -1;
}


int Value(int k) {
    int value = 1;
    int position = 0;
    int result = 1;
    while (position < k) {
        value++;
        if (NextPrimeDivisor(1, value) == -1) {
            position++;
            result = value;
        } else {
            int div = NextPrimeDivisor(1, value);
            while (div != -1 && position < k) {
                position += div;
                result = div;
                div = NextPrimeDivisor(div, value);
            }
        }
    }
    return result;
}

int main() {
    int k;
    //Read(k);
    cout << Value(1) << endl;
    cout << Value(8) << endl;
    cout << Value(11) << endl;
    cout << Value(20) << endl;
    cout << Value(30) << endl;
    cout << Value(34) << endl;
    cout << Value(35) << endl;
    cout << Value(77) << endl;
    return 0;
}
