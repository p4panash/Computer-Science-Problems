#include <iostream>
#include <fstream>
using namespace std;

const int MARIME_MAXIMA = 505;

int produse[MARIME_MAXIMA * MARIME_MAXIMA];

void Citire(int &n, int &h, int &s, int magazine[][MARIME_MAXIMA], int preturi[]) {
    cin >> n >> h >> s;
    for (int i = 0; i < n; i++)
        cin >> preturi[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++)
            cin >> magazine[i][j];
    }
}

void Inserare(int produs, int &numarProduse) {
    int i;
    for (i = 0; produse[i] < produs && i < numarProduse; i++);
    if (i == numarProduse) {
        produse[numarProduse] = produs;
        numarProduse++;
    } else {
        numarProduse++;
        for (int j = numarProduse - 1; j > i; j--)
            produse[j] = produse[j - 1];
        produse[i] = produs;
    }
}

void ProduseValabile(int n, int h, int magazine[][MARIME_MAXIMA], int preturi[], int s, int &numarProduse) {
    numarProduse = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < h; j++) {
            if (magazine[i][j] < preturi[i] && magazine[i][j] < s)
                Inserare(magazine[i][j], numarProduse);
        }
}

int MaximProduse(int numarProduse, int s) {
    int nrProduse = 0;
    for (int i = 0; s > 0 && i < numarProduse; i++) {
        s -= produse[i];
        if (s > 0)
            nrProduse++;
    }
    return nrProduse;
}

int main() {
    freopen("palma.in", "r", stdin);
    freopen("palma.out", "w", stdout);
    int n, h, s, numarProduse;
    int magazine[MARIME_MAXIMA][MARIME_MAXIMA];
    int preturi[MARIME_MAXIMA];
    Citire(n, h, s, magazine, preturi);
    ProduseValabile(n, h, magazine, preturi, s, numarProduse);
    cout << MaximProduse(numarProduse, s);
    return 0;
}
