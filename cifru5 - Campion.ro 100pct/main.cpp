#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

const int MAX_SIZE = 9;

void Citire(int cifre[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cifra;
        cin >> cifra;
        cifre[cifra]++;
    }
}

int Diferenta(int cifra1, int cifra2) {
    int dif1 = 0, dif2 = 0;
    if (cifra1 > cifra2) {
        dif1 = cifra1 - cifra2;
        dif2 = cifra2 + 10 - cifra1;
    } else {
        dif1 = cifra2 - cifra1;
        dif2 = cifra1 + 10 - cifra2;
    }
    if (dif1 < dif2)
        return dif1;
    return dif2;
}

int CifraMaxima(int cifre[]) {
    for (int i = 9; i >= 0; i--)
        if (cifre[i] > 0)
            return i;
}

void CifruIdentic(int cifre[], int &minPasi, int &repetari, int &cifraMin) {
    minPasi = INT_MAX, repetari = 0;
    for (int c = 0; c <= 9; c++) {
            int pasi = 0;
            for (int i = 0; i <= 9; i++)
                if (cifre[i] != 0) {
                    pasi += (Diferenta(c, i) * cifre[i]);
                }
            if (pasi < minPasi) {
                minPasi = pasi;
                repetari = 1;
                cifraMin = c;
            } else if (pasi == minPasi) {
                repetari++;
            }
    }
}

void teste() {
    cout << Diferenta(9, 3) << " " << Diferenta(3, 9) << '\n';
}

int main() {
    freopen("cifru5.in", "r", stdin);
    freopen("cifru5.out", "w", stdout);
    int cifre[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int minPasi, repetari, cifraMinima;
    Citire(cifre);
    cout << CifraMaxima(cifre) << endl;
    CifruIdentic(cifre, minPasi, repetari, cifraMinima);
    cout << minPasi << endl <<  cifraMinima << endl << repetari;
    return 0;
}
