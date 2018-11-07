#include <iostream>
#include <fstream>
using namespace std;

int acces[105][15];
int asemanatoare[105][15];
bool folosit[105] = {false};

void Citire(int &lAcces, int &lAsemanatoare) {
    cin >> lAcces >> lAsemanatoare;
    for (int i = 0; i < lAcces; i++) {
        int numar;
        cin >> numar;
        while (numar != 0) {
            acces[i][numar % 10]++;
            numar /= 10;
        }
    }
    for (int i = 0; i < lAsemanatoare; i++) {
        int numar;
        cin >> numar;
        while (numar != 0) {
            asemanatoare[i][numar % 10]++;
            numar /= 10;
        }
    }
}

bool Asociat(int numar1[], int numar2[]) {
    int cifre = 0;
    int comun = 0;
    for (int i = 0; i <= 9; i++) {
        cifre += numar1[i];
        if (numar1[i] != 0 && numar2[i] != 0)
            comun++;
    }
    if (cifre % 2 == 0 && comun >= cifre / 2) {
        return true;
    } else if (cifre % 2 != 0 && comun >= (cifre / 2) + 1){
        return true;
    }
    return false;
}

int NumarCifreComune(int numar1[], int numar2[]) {
    int comun = 0;
    for (int i = 0; i <= 9; i++) {
        if (numar1[i] != 0 && numar2[i] != 0)
            comun++;
    }
    return comun;
}

void AflareAsociat(int asociat[], int lAcces, int lAsemanatoare) {
    for (int i = 0; i < lAcces; i++) {
        for (int j = 0; j < lAsemanatoare; j++)
            if (NumarCifreComune(acces[i], asemanatoare[j]) > NumarCifreComune(acces[i], asemanatoare[asociat[i]]) &&
                Asociat(acces[i], asemanatoare[j]) && !folosit[j]) {
                    asociat[i] = j;
                    folosit[j] = true;
                }
    }
}

void init(int cifre[]) {
    for (int i = 0; i <= 9; i++)
        cifre[i] = 0;
}

void GenerareNumere(int asociat[], int lAcces, int transformare[]) {
    int cifre[10] = {0};
    for (int i = 0; i < lAcces; i++) {
        for (int j = 0; j <= 9; j++) {
            if (acces[i][j] != 0 && asemanatoare[asociat[i]][j] == 0)
                cifre[j] = acces[i][j];
        }
        int numar = 0;
        for (int j = 9; j >= 0; j--) {
            while (cifre[j] > 0) {
                numar = numar * 10 + j;
                cifre[j]--;
            }
        }
        if (numar < 12345)
            numar += 12345;
        transformare[i] = numar;
        init(cifre);
    }
}

void AfisareNumere(int transformare[], int lAcces) {
    for (int i = 0; i < lAcces; i++)
        cout << transformare[i] << " ";
}


int main() {
    freopen("cod4.in", "r", stdin);
    freopen("cod4.out", "w", stdout);
    int lAcces, lAsemanatoare;
    int asociat[105] = {0};
    int tranformare[105];
    Citire(lAcces, lAsemanatoare);
    AflareAsociat(asociat, lAcces, lAsemanatoare);
    GenerareNumere(asociat, lAcces, tranformare);
    AfisareNumere(tranformare, lAcces);
}
