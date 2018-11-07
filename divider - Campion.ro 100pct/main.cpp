#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int sirDivizori[2005];

void Citire(int &a, int &b, int &n) {
    cin >> a >> b >> n;
}

void Sortare(int numarDivizori) {
    for (int i = 0; i < numarDivizori - 1; i++)
        for (int j = i + 1; j < numarDivizori; j++)
            if (sirDivizori[i] > sirDivizori[j]) {
                int aux = sirDivizori[j];
                sirDivizori[j] = sirDivizori[i];
                sirDivizori[i] = aux;
            }
}

void Divizori(int a, int b, int n, int &numarDivizori) {
    numarDivizori = 0;
    if (a == b) {
        for (int i = 0; i <= n * 2; i++) {
                sirDivizori[numarDivizori] = pow(a, i);
                numarDivizori++;
        }
    } else {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) {
                sirDivizori[numarDivizori] = pow(a, i) * pow(b, j);
                numarDivizori++;
            }
    }
}

void Afisare(int numarDivizori) {
    for (int i = 0; i < numarDivizori; i++)
        cout << sirDivizori[i] << " ";
}

int main() {
    freopen("divider.in", "r", stdin);
    freopen("divider.out", "w", stdout);
    int a, b, n, numarDivizori;
    Citire(a, b, n);
    Divizori(a, b, n, numarDivizori);
    Sortare(numarDivizori);
    Afisare(numarDivizori);
    return 0;
}
