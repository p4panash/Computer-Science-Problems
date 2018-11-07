#include <iostream>
#include <fstream>
using namespace std;

void pow10(long long putere) {
    for (int i = 1; i <= putere; i++)
        cout << "0";
}



void NumerePatrat(long long n) {
    if (n < 9) {
        cout << 0;
    } else if (n == 9) {
        cout << 8;
    } else {
        cout << 8 * 9;
        pow10(n - 10);
    }
}

int main() {
    freopen("secv9.in", "r", stdin);
    freopen("secv9.out", "w", stdout);
    long long n;
    cin >> n;
    NumerePatrat(n);
}
