#include <iostream>
#include <fstream>
using namespace std;

int comenzi[5005];
long sume[5005];
int transport[5005];
int marimiTransporturi[5005];

void Citire(int &n) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> comenzi[i];
}

void GenerareSume(int n) {
    long suma = 0;
    for (int i = 0; i < n; i++) {
        if (transport[i] == 0) {
            sume[i] = comenzi[i] + suma;
            suma += comenzi[i];
        }
    }
}

void MarcareTransport(int inceput, int sfarsit, int numarTransport) {
    for (int i = inceput; i <= sfarsit; i++)
        transport[i] = numarTransport;
}

int Vanzare(int n, int &numarTransporturi) {
    int inceput = -1, sfarsit = -1, divizibil = -1;
    GenerareSume(n);
    for (int i = 0; i < n; i++) {
        if (sume[i] % n == 0 && divizibil == -1) {
            divizibil = i;
        }
        for (int j = i + 1; j < n; j++)
            if (sume[i] % n == sume[j] % n) {
                inceput = i + 1;
                sfarsit = j;
                numarTransporturi++;
                marimiTransporturi[numarTransporturi] = sfarsit - inceput + 1;
                MarcareTransport(inceput, sfarsit, numarTransporturi);
                return;
            }
    }
    if (inceput == -1 && divizibil != -1) {
        numarTransporturi++;
        marimiTransporturi[numarTransporturi] = divizibil + 1;
        MarcareTransport(0, divizibil, numarTransporturi);
    }
}

void Vanzari(int n, int &numarTransporturi) {
    numarTransporturi = 0;
    bool ok = true;
    while (n != 0 && ok) {
        int transportAnterior = numarTransporturi;
        Vanzare(n, numarTransporturi);
        if (numarTransporturi != transportAnterior) {
            n -= marimiTransporturi[numarTransporturi];
        } else {
            numarTransporturi = -1;
            ok = false;
        }
    }
    if (n != 0)
        numarTransporturi = -1;
}

void Afisare(int n, int numarTransporturi) {
    if (numarTransporturi > 0) {
        cout << numarTransporturi << '\n';
        for (int t = 1; t <= numarTransporturi; t++) {
            cout << marimiTransporturi[t] << '\n';
            for (int i = 0; i < n; i++)
                if (transport[i] == t)
                    cout << comenzi[i] << '\n';
        }
    } else {
        cout << "Nu exista";
    }
}


int main() {
    freopen("ferma.in", "r", stdin);
    freopen("ferma.out", "w", stdout);
    int n, numarTransporturi;
    Citire(n);
    Vanzari(n, numarTransporturi);
    Afisare(n, numarTransporturi);
    return 0;
}
