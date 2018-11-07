#include <iostream>
#include <fstream>
using namespace std;

struct apartii{
    int numar;
    int nrAparitii;
} nrPrime[1005];

int a = 1;

void Citire(char sir[]) {
    cin.getline(sir, 30005);
}

void ExtragereNumere(char sir[], int numere[], int &n) {
    n = 0;
    for (int i = 0; sir[i] != NULL; i++) {
        int nrCifre = sir[i] - '0';
        numere[n] = 0;
        int j = i + 1;
        for ( ; j - i <= nrCifre && sir[j] != NULL; j++) {
            numere[n] = numere[n] * 10 + (sir[j] - '0');
        }
        i = j - 1;
        n++;
    }
}

bool Prim(int nr) {
    if (nr < 2)
        return false;
    for (int i = 2; i * i <= nr; i++)
        if (nr % i == 0)
            return false;
    return true;
}

int NumarMaxim(int numere[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (numere[i] > max)
            max = numere[i];
    return max;
}

bool vizitat[99999];

void GenerareNumerePrime(int numere[], int n, int &contorNrPrime) {
    contorNrPrime = 0;
    int maxim = NumarMaxim(numere, n);
    for (int i = 2; i <= maxim; i++)
        if (vizitat[i] == false) {
            nrPrime[contorNrPrime].numar = i;
            nrPrime[contorNrPrime].nrAparitii = 0;
            contorNrPrime++;
            for (int j = i; j <= maxim; j += i)
                vizitat[j] = true;
        }
}

void DescompunereFactoriPrimi(int numar) {
    int indicePrim = 0;
    while (numar != 1) {
        if (numar % nrPrime[indicePrim].numar == 0) {
            numar /= nrPrime[indicePrim].numar;
            nrPrime[indicePrim].nrAparitii++;
        } else {
            indicePrim++;
        }
    }
}

void DescompunereSir(int numere[], int n) {
    for (int i = 0; i < n; i++)
        DescompunereFactoriPrimi(numere[i]);
}

void Afisare(int n, int contorNrPrime) {
    cout << n << '\n';
    for (int i = 0; i < contorNrPrime; i++) {
        if (nrPrime[i].nrAparitii != 0)
            cout << nrPrime[i].numar << " " << nrPrime[i].nrAparitii << '\n';
    }
}

int main() {
    freopen("prodnr.in", "r", stdin);
    freopen("prodnr.out", "w", stdout);
    char sir[30005];
    int n, numere[15005], contorNrPrime;
    Citire(sir);
    ExtragereNumere(sir, numere, n);
    GenerareNumerePrime(numere, n, contorNrPrime);
    DescompunereSir(numere, n);
    Afisare(n, contorNrPrime);
    return 0;
}
