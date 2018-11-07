#include <iostream>
#include <fstream>
using namespace std;

int intensitate[28];
char banda[100001];

void Citire(char nuante[]) {
    cin >> nuante;
    cin.get();
    cin >> banda;
}

void OrdineIntensitate(char nuante[]) {
    for (int i = 0; nuante[i] != NULL; i++)
        intensitate[nuante[i] - 'a'] = i + 1;
}

int LungimeDegrade(int &i) {
    int lungime = 1;
    for (; banda[i + 1] != NULL && intensitate[banda[i] - 'a'] <= intensitate[banda[i + 1] - 'a']; i++)
        lungime++;
    return lungime;
}

void LungimeMaxima(int &lungimeMax, int &nrMax) {
    lungimeMax = 0;
    nrMax = 0;
    for (int i = 0; banda[i] != NULL; i++) {
        int lungime = LungimeDegrade(i);
        if (lungime > lungimeMax) {
            lungimeMax = lungime;
            nrMax = 1;
        } else if (lungime == lungimeMax) {
            nrMax++;
        }
    }
}

int main() {
    freopen("degrade.in", "r", stdin);
    freopen("degrade.out", "w", stdout);
    char nuante[15] = "";
    int lungimeMax, nrMax;
    Citire(nuante);
    OrdineIntensitate(nuante);
    LungimeMaxima(lungimeMax, nrMax);
    cout << lungimeMax << " " << nrMax;
    return 0;
}
