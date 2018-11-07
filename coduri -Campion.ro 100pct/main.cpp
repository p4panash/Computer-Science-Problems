#include <iostream>
#include <fstream>
using namespace std;

long long pow(long long nr, long long putere) {
    long long result = 1;
    for (long long i = 1; i <= putere; i++)
        result *= nr;
    return result;
}

long long SumaPatrate(long long n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

void Citire(long long &n) {
    cin >> n;
}

void AfisareCoduri(long long n) {
    long long suma = pow(SumaPatrate(n), 4);
    for (long long i = 1; i <= n; i++) {
        cout << suma * i << '\n';
    }
}

int main()
{
    freopen("coduri.in", "r", stdin);
    freopen("coduri.out", "w", stdout);
    long long n;
    Citire(n);
    AfisareCoduri(n);
    return 0;
}
