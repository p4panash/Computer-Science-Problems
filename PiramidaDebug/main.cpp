#include <iostream>
#include <fstream>
#include <cstddef>
using namespace std;

int MAX_SIZE = 85;

void Citire(char nume[]) {
    cin >> nume;
}

void ConstruireSirCifre(char nume[], int cifre[], int &lungime) {
    lungime = 0;
    for (int i = 0; nume[i] != NULL; i++) {
        if (nume[i] >= 'a' && nume[i] <= 'z') {
            cifre[lungime] = (nume[i] - 'a') % 9 + 1;
        } else if (nume[i] >= 'A' && nume[i] <= 'Z') {
            cifre[lungime] = (nume[i] - 'A') % 9 + 1;
        }
        lungime++;
    }
}


void Scrie(int cifre[], int lungime, int elementeSterse) {
    for (int i = 1; i <= elementeSterse; i++)
        cout << " ";
    for (int i = 0; i < lungime; i++)
        cout << cifre[i] << " ";
    cout << '\n';
}

int CalculPiramida(int cifre[], int lungime) {
    int elementeSterse = 0;
    while (lungime != 0) {
        Scrie(cifre, lungime, elementeSterse);
        for (int i = 0; i < lungime - 1; i++) {
            int cifra = cifre[i] + cifre[i + 1];
            while (cifra > 9) {
                cifra = cifra % 10 + 1;
            }
            cifre[i] = cifra;
        }
        lungime--;
        elementeSterse++;
    }
    return cifre[0];
}

void ScrieSir(char nume[]) {
    for (int i = 0; nume[i] != NULL; i++)
        if (nume[i] >= 'A' && nume[i] <= 'Z') {
            cout << (char)(nume[i] + 32);
        } else {
            cout << nume[i];
        }
    cout << '\n';
}


int main() {
    freopen("piramida.in", "r", stdin);
    freopen("piramida.out", "w", stdout);
    char nume[MAX_SIZE];
    int cifre[MAX_SIZE], lungime;
    Citire(nume);
    ScrieSir(nume);
    ConstruireSirCifre(nume, cifre, lungime);
    CalculPiramida(cifre, lungime);
}
