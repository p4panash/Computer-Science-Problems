#include <iostream>
#include <fstream>
using namespace std;

void Citire(int &n, int &m, int prajituraI[], int prajituraD[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> prajituraI[i];
    for (int i = 0; i < m; i++)
        cin >> prajituraD[i];
}

//Functia verifica daca de pe pozitia i se poate regasi sirul prajituraD
bool VerificareExistentaSubsir(int &i, int n, int m, int prajituraI[], int prajituraD[]) {
    int pozitieInitiala = i;
    for (; i < n && i - pozitieInitiala < m; i++)
        if (prajituraI[i] != prajituraD[i - pozitieInitiala])
            return false;
    if (i - pozitieInitiala != m)
        return false;
    return true;
}

void ExtragereTort(int n, int m, int prajituraI[], int prajituraD[], int &stanga, int &dreapta, int &identice) {
    stanga = -1;
    dreapta = -1;
    identice = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        if (VerificareExistentaSubsir(j, n, m, prajituraI, prajituraD)) {
            if (stanga == -1 && dreapta == -1) {
                stanga = i;
                dreapta = n - j;
            }
            identice++;
            i = j - 1;
        } else {
            i = j;
        }
    }
}

void ExtragereStraturi(int n, int prajitura[], int straturi[]) {
    for (int i = 0; i < n; i++)
        straturi[prajitura[i]]++;
}

int NumarMaximPrajituri(int n, int m, int prajituraI[], int prajituraD[]) {
    int straturiI[105] = {0}, straturiD[105] = {0}, maxim = 10005;
    ExtragereStraturi(n, prajituraI, straturiI);
    ExtragereStraturi(m, prajituraD, straturiD);
    for (int i = 0; i <= 100; i++) {
        if (straturiD[i] != 0 && straturiI[i] / straturiD[i] < maxim)
            maxim = straturiI[i] / straturiD[i];
    }
    return maxim;
}

int main() {
    freopen("prajituri.in", "r", stdin);
    freopen("prajituri.out", "w", stdout);
    int n, m, prajituraI[10000], prajituraD[10000], dreapta, stanga, identice;
    Citire(n, m, prajituraI, prajituraD);
    ExtragereTort(n, m, prajituraI, prajituraD, stanga, dreapta, identice);
    cout << stanga << " " << dreapta << '\n' << identice << '\n' << NumarMaximPrajituri(n, m, prajituraI, prajituraD);
    return 0;
}
