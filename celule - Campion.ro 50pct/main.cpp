#include <iostream>
#include <fstream>
using namespace std;

int prim[700005], numerePrime;

void Citire(int &numar1, int &numar2) {
    cin >> numar1 >> numar2;
}

void GenerarePrim(int numar) {
    bool vizitat[700005] = {false};
    numerePrime = 0;
    for (int i = 2; i <= numar; i++) {
        if (!vizitat[i]) {
            prim[numerePrime] = i;
            numerePrime++;
            for (int j = i; j <= numar; j += i)
                vizitat[j] = true;
        }
    }
}

int DivizoriPrimiDiferiti(int numar1, int numar2) {
    int diferiti = 0;
    for (int divizor = 0; (numar1 != 1 || numar2 != 1) && divizor < numerePrime; divizor++) {
        while (numar1 % prim[divizor] == 0 || numar2 % prim[divizor] == 0) {
            if (numar1 % prim[divizor] == 0 && numar2 % prim[divizor] != 0) {
                diferiti++;
                numar1 /= prim[divizor];
            } else if (numar1 % prim[divizor] != 0 && numar2 % prim[divizor] == 0) {
                diferiti++;
                numar2 /= prim[divizor];
            } else {
                numar1 /= prim[divizor];
                numar2 /= prim[divizor];
            }
        }
    }
    return diferiti;
}

int main() {
    freopen("celule.in", "r", stdin);
    freopen("celule.out", "w", stdout);
    int numar1, numar2;
    Citire(numar1, numar2);
    if (numar1 > numar2) {
        GenerarePrim(numar1);
    } else {
        GenerarePrim(numar2);
    }
    cout << DivizoriPrimiDiferiti(numar1, numar2);
    return 0;
}
