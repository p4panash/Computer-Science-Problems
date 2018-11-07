#include <iostream>
#include <fstream>
using namespace std;
const int MAX_SIZE = 1005;

void Citire(int cifre[], int &n, int &m) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> cifre[i];
}

void Eliminare(int pos, int cifre[], int &n) {
    for (int i = pos; i < n - 1; i++)
        cifre[i] = cifre[i + 1];
    n--;
}

void EliminareCifreMinime(int cifre[], int &n, int m) {
    for (int j = 0; j < m; j++) {
        bool eliminat = false;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && cifre[i + 1] > cifre[i]) {
                Eliminare(i, cifre, n);
                eliminat = true;
                break;
            }
        }
        if (!eliminat) {
            n--;
        }
    }
}

void AfisareNumar(int cifre[], int n) {
    for (int i = 0; i < n; i++)
        cout << cifre[i];
}

int main() {
    freopen("comoara1.in", "r", stdin);
    freopen("comoara1.out", "w", stdout);
    int n, m;
    int cifre[MAX_SIZE];
    Citire(cifre, n, m);
    EliminareCifreMinime(cifre, n, m);
    AfisareNumar(cifre, n);
    return 0;
}

//5271
