#include <iostream>
#include <fstream>
using namespace std;



void Citeste(int &n, int &x) {
    cin >> n >> x;
}

int NumarZile(int n) {
    int zile = 0, i = 2;
    while (i <= n - 1) {
        zile++;
        i *= 2;
    }
    return zile;
}

int Pozitie(int n, int x) {
    int lungime = n;
    int pozitie = x;
    for (int i = 1; i <= NumarZile(n); i++) {
        /*
        if (pozitie % 2 == 1) {
            pozitie = pozitie / 2 + ;
            if (lungime % 2 == 0) {
                lungime /= 2;
            } else {
                lungime = lungime / 2 + i;
            }
        } else {
            if (lungime % 2 == 0) {
                lungime /= 2;
            } else {
                lungime = lungime / 2 + i;
            }
            pozitie = pozitie / 2 + lungime;
        }
        */
        if (lungime % 2 == 1) {
            if (pozitie % 2 == 0) {
                pozitie = (pozitie / 2) + (lungime / 2 + 1);
                lungime = lungime / 2 + 1;
            }
        }
    }
}


int main() {
    freopen("pesti.in", "r", stdin);
    freopen("pesti.out", "w", stdout);
    int n, x;
    int z, y, x;
}
