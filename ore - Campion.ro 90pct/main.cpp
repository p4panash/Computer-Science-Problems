#include <iostream>
#include <fstream>
using namespace std;

void Citire(int cifre[]) {
    int ora;
    int numarCifre = 0;
    cin >> ora;
    while (ora != 0) {
        cifre[ora % 10]++;
        ora /= 10;
        numarCifre++;
    }
    while (numarCifre != 4) {
        cifre[0]++;
        numarCifre++;
    }
}

bool Verifica(int cifre[], int folosit[]) {
    int contor = 0;
    for (int i = 9; i >= 6; i--)
        if (cifre[i] - folosit[i] > 0)
            contor += cifre[i] - folosit[i];
    if (contor > 1)
        return true;
    return false;
}

void MinOra(int cifre[], char oraMinima[]) {
    int folosit[11] = {0};
    bool descrescator = false;
    int i = 0;
    for (i = 0; i <= 1; i++) {
        int j;
        if (i == 1 && Verifica(cifre, folosit)) {
            j = 9;
            descrescator = true;
        } else {
            j = 0;
        }
        while (cifre[j] - folosit[j] <= 0 && j <= 9 && !descrescator)
            j++;
        while (cifre[j] - folosit[j] <= 0 && j >= 0 && descrescator)
            j--;
        if (descrescator)
            descrescator = false;
        folosit[j]++;
        oraMinima[i] = '0' + j;
    }
    oraMinima[i] = ':';
    i++;
    for (; i <= 4; i++) {
        int j = 0;
        while (cifre[j] - folosit[j] <= 0 && j <= 9)
            j++;
        folosit[j]++;
        oraMinima[i] = '0' + j;
    }
}

void MaxOra(int cifre[], char oraMaxima[]) {
    int folosit[11] = {0};
    int j = 2;
    while (cifre[j] - folosit[j] <= 0 && j >= 0)
            j--;
    folosit[j]++;
    oraMaxima[0] = '0' + j;
    if (oraMaxima[0] == '2') {
        j = 4;
    } else {
        j = 9;
    }
    while (cifre[j] - folosit[j] <= 0 && j >= 0)
            j--;
    folosit[j]++;
    oraMaxima[1] = '0' + j;
    oraMaxima[2] = ':';
    for (int i = 3; i <= 4; i++) {
        if (oraMaxima[i - 1] == ':') {
            j = 5;
        } else {
            j = 9;
        }
        while (cifre[j] - folosit[j] <= 0 && j >= 0)
            j--;
        folosit[j]++;
        oraMaxima[i] = '0' + j;
    }
}

void DiferentaOra(char oraMaxima[], char oraMinima[], char oraDiferenta[]) {
    for (int i = 4; i >= 0; i--) {
        if (oraMaxima[i] - '0' < oraMinima[i] - '0') {
            if (i == 4) {
                oraDiferenta[i] = '0' + ((oraMaxima[i] - '0') - (oraMinima[i] - '0') + 10);
                if (oraMaxima[3] >= '1') {
                    oraMaxima[3] -= 1;
                } else {
                    oraMaxima[3] = '5';
                    if (oraMaxima[1] >= '1') {
                        oraMaxima[1] -= 1;
                    } else {
                        oraMaxima[1] = '9';
                        oraMaxima[0] -= 1;
                    }
                }
            }
            if (i == 3) {
                oraDiferenta[i] = '0' + ((oraMaxima[i] - '0') - (oraMinima[i] - '0') + 6);
                if (oraMaxima[1] >= '1') {
                    oraMaxima[1] -= 1;
                } else {
                    oraMaxima[1] = '9';
                    oraMaxima[0] -= 1;
                }
            }
            if (i == 1) {
                oraDiferenta[i] = '0' + ((oraMaxima[i] - '0') - (oraMinima[i] - '0') + 10);
                oraMaxima[0] -= 1;
            }
        } else {
            oraDiferenta[i] = oraMaxima[i] - oraMinima[i] + '0';
        }
    }
    oraDiferenta[2] = ':';
}

void ScrieOra(char ora[]) {
    for (int i = 0; i < 5; i++)
        cout << ora[i];
    cout << '\n';
}

int main() {
    freopen("ore.in", "r", stdin);
    freopen("ore.out", "w", stdout);
    int cifre[11] = {0};
    char oraMinima[6], oraMaxima[6], oraDiferenta[6];
    Citire(cifre);
    MinOra(cifre, oraMinima);
    ScrieOra(oraMinima);
    MaxOra(cifre, oraMaxima);
    ScrieOra(oraMaxima);
    DiferentaOra(oraMaxima, oraMinima, oraDiferenta);
    ScrieOra(oraDiferenta);
    return 0;
}
