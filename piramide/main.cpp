#include <iostream>
#include <fstream>
using namespace std;

void Citire(int &n, int &x, int &k, int a[]) {
    cin >> n >> x >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
}

int Suma(int n) {
    return (n * (n + 1)) / 2;
}

int PiramideComplete(int n) {
    int i;
    for (i = 2 ; n - Suma(i) >= 0; i++)
        n -= Suma(i);
    return i - 2;
}

int CartiRamase(int n) {
    int carti = 0;
    for (int i = 2; carti + Suma(i) <= n; i++)
        carti += Suma(i);
    return n - carti;
}

int Piramida(int n, int x) {
    int carti = 0;
    for (int i = 2; carti + Suma(i) <= n; i++) {
        if (carti + 1 <= x && x <= carti + 1 + Suma(i))
            return i - 1;
        carti += Suma(i);
    }
    return 0;
}

int Cauta(int a[], int k, int numar) {
    int st = 0, dr = k - 1;
    while (st != dr && st >= 0 && dr >= 0) {
        if (a[(st + dr) / 2] > numar) {
            dr = ((st + dr) / 2) - 1;
        } else if (a[(st + dr) / 2] < numar) {
            st = ((st + dr) / 2) + 1;
        } else {
            return (st + dr) / 2;
        }
    }
    return st;
}

int NumarCartiAlbe(int a[], int k, int i, int inceput, int sfarsit) {
    int carti = 0;
    while (a[i] >= inceput && a[i] <= sfarsit) {
        carti++;
        i++;
    }
    return carti;
}

int PiramidaCuCeleMaiMulteCartiAlbe(int a[], int k, int n) {
    int max = 0, piramida = 0, carti = 0;
    int j = 0;
    for (int i = 2; carti + Suma(i) <= n; i++) {
        int inceput = carti + 1, sfarsit = carti + Suma(i);
        int cartiAlbe = NumarCartiAlbe(a, k, j, inceput, sfarsit);
        j += cartiAlbe;
        if (cartiAlbe > max) {
            max = cartiAlbe;
            piramida = i - 1;
        }
        carti += Suma(i);
    }
    return piramida;
}

void Scrie(int a[], int n, int x, int k) {
    cout << Piramida(n, x) << '\n' << PiramideComplete(n) << '\n' << CartiRamase(n) << '\n' << PiramidaCuCeleMaiMulteCartiAlbe(a, k, n);
}

int main() {
    freopen("piramide.in", "r", stdin);
    freopen("piramide.out", "w", stdout);
    int n, x, k;
    int a[100000];
    Citire(n, x, k, a);
    Scrie(a, n, x, k);
    return 0;
}
