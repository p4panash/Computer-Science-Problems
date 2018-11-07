#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int fete[1000005], baieti[1000005];
long maxInterval = LONG_MIN;

void Citire() {
    long n, m;
    cin >> n >> m;
    for (long i = 1; i <= n; i++) {
        long inceput, sfarsit;
        cin >> inceput >> sfarsit;
        if (sfarsit > maxInterval)
            maxInterval = sfarsit;
        fete[inceput] += 1;
        fete[sfarsit + 1] -= 1;
    }
    for (long i = 1; i <= m; i++) {
        long inceput, sfarsit;
        cin >> inceput >> sfarsit;
        if (sfarsit > maxInterval)
            maxInterval = sfarsit;
        baieti[inceput] += 1;
        baieti[sfarsit + 1] -= 1;
    }
}

long DeterminareMaxim() {
    long max = 0;
    long numarFete = 0;
    long numarBaieti = 0;
    for (long i = 1; i <= maxInterval; i++) {
        numarFete += fete[i];
        numarBaieti += baieti[i];
        long aux;
        if (numarFete < numarBaieti) {
            aux = numarFete;
        } else {
            aux = numarBaieti;
        }
        if (aux > max)
            max = aux;
    }
    return max;
}

int main() {
    freopen("bal.in", "r", stdin);
    freopen("bal.out", "w", stdout);
    Citire();
    cout << DeterminareMaxim();
    return 0;
}
