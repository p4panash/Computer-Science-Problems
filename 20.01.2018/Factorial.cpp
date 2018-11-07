#include <iostream>
using namespace std;

void Read(int &n) {
    cin >> n;
}

long Result(int n) {
    long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int Count(long result) {
    int count = 0;
    while (result % 10 == 0) {
        count++;
        result /= 10;
    }
    return count;
}

int cifre0_2(int n) {
    int nr = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        nr += n / i;
    }
    return nr;
}

int main() {
    int n;
    Read(n);

    long result = Result(n);
    cout << Count(result);
    cout << 20/25;
}
