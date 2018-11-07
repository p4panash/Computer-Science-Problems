#include <iostream>
#include <fstream>
using namespace std;

void Citire(long &n, long &a, long &b) {
    cin >> n >> a >> b;
}

long Factorial(long numar) {
    long rezultat = 1;
    for (long i = 1; i <= numar; i++)
        rezultat *= i;
    return rezultat;
}

long Diferenta(long a, long b) {
    if (a - b == 0)
        return 1;
    if (a > b) {
        return a - b + 1;
    }
    return b - a + 1;
}

long Combinari(long n, long a, long b) {
    return ((Factorial(n % 666013) % 666013) / (Factorial(Diferenta(a, b) % 666013) % 666013 * Factorial((n - Diferenta(a, b ))% 666013) % 666013));
}

int main() {
    freopen("ssmax.in", "r", stdin);
    freopen("ssmax.out", "w", stdout);
    long n, a, b;
    Citire(n, a, b);
    cout << Combinari(n, a, b);
    return 0;
}
