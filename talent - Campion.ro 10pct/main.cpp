#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int numere[15005];

void Citire(int &n) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> numere[i];
}

bool Palindrom(int numar, int &distinct) {
    int cifre[11] = {0};
    int numarCifre = 0;
    distinct = 0;
    while (numar != 0) {
        if (cifre[numar % 10] == 0)
            distinct++;
        cifre[numar % 10]++;
        numarCifre++;
        numar /= 10;
    }
    if (numarCifre % 2 == 0) {
        if (distinct > numarCifre / 2)
            return false;
        for (int i = 0; i <= 9; i++)
            if (cifre[i] > numarCifre / distinct)
                return false;
    } else {
        if (distinct > (numarCifre + 1) / 2)
            return false;
        for (int i = 0; i <= 9; i++)
            if (cifre[i] > (numarCifre + 1) / distinct)
                return false;
    }
    return true;
}


void DeterminareSemifinalistiVIP(int n, int &numarSemifin, int &vip) {
    numarSemifin = 0;
    vip = INT_MAX;
    int nrDistinct = 0;
    for (int i = 0; i < n; i++) {
        int distinct;
        if (Palindrom(numere[i], distinct)) {
            numarSemifin++;
            if (distinct > nrDistinct) {
                nrDistinct = distinct;
                vip = numere[i];
            } else if (distinct == nrDistinct && numere[i] < vip) {
                vip = numere[i];
            }
        }
    }
}

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    int vip;
    int numarSemifin, n;
    Citire(n);
    DeterminareSemifinalistiVIP(n, numarSemifin, vip);
    if (numarSemifin != 0) {
        cout << numarSemifin << " " << vip;
    } else {
        cout << "0 0";
    }
    return 0;
}
