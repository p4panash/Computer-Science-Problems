#include <iostream>
#include <fstream>
using namespace std;

void Citire(long long &numarPesti, long long &peste) {
    cin >> numarPesti >> peste;
}

void Simulare(long long numarPesti, long long peste, long long &z, long long &y, long long &u) {
    z = 0; y = 0; u = peste;
    long long inceput = 1, sfarsit = numarPesti, putere = 1, pozitie = peste;
    bool dreapta = true;
    //simulare grupare acvarii pana cand grupele sunt formate din maxim 2 acvarii
    while (sfarsit - inceput > 1) {
        if (dreapta) {
            if ((peste / putere) % 2 == 0) {
                inceput = (sfarsit + inceput) / 2 + 1;
            } else {
                dreapta = false;
                sfarsit = (sfarsit + inceput) / 2;
            }
        } else {
            if ((peste / putere + 1) % 2 == 0) {
                inceput = (sfarsit + inceput) / 2 + 1;
            } else {
                dreapta = false;
                sfarsit = (sfarsit + inceput) / 2;
            }
        }
        z++;
        putere *= 2;
        if (pozitie != inceput + (peste - 1) / putere) {
            y = z;
            pozitie = inceput + (peste - 1) / putere;
        }
    }
    // pozitie peste
    if (sfarsit - inceput == 1) {
        if ((peste / putere) % 2 == 0) {
            u = inceput;
        } else {
            u = sfarsit;
        }
    } else {
        u = inceput;
    }
    // aflare numar zile
    while (putere * 2 <= numarPesti - 1) {
        z++;
        putere *= 2;
    }
}

void Scrie(long long z, long long y, long long u) {
    cout << z << " " << u << " " <<  y;
}

int main() {
    freopen("pesti.in", "r", stdin);
    freopen("pesti.out", "w", stdout);
    long long numarPesti, peste, z, y, u;
    Citire(numarPesti, peste);
    Simulare(numarPesti, peste, z, y, u);
    Scrie(z, y, u);
}
