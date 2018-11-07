#include <fstream>
#include <iostream>
using namespace std;

int numerePrime[700005];
int nr = 0;
bool vizitat[700005];

void Citeste(int numere[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> numere[i];
}

void GenerareNumere() {
    for (int i = 2; i <= 700000; i++)
        if (vizitat[i] == false) {
            numerePrime[nr] = i;
            nr++;
            vizitat[i] = true;
            for (int j = i + i; j <= 700000; j += i)
                vizitat[j] = true;
        }
}

int NumarDivizori(int numar) {
    int divizori = 1;
    int putere = 0;
    for (int i = 0; i < nr && numar != 1; i++) {
        while (numar % numerePrime[i] == 0) {
            putere++;
            numar = numar / numerePrime[i];
        }
        if (putere > 0) {
            putere++;
            divizori *= putere;
        }
        putere = 0;
    }
    return divizori;
}

void Afisare(int numere[55], int n) {
    for (int i = 0; i < n; i++)
        cout << NumarDivizori(numere[i]) << '\n';
}



int main() {
    freopen("nrdiv.in", "r", stdin);
    freopen("nrdiv.out", "w", stdout);
    int numere[55], n;
    Citeste(numere, n);
    GenerareNumere();
    Afisare(numere, n);
}
