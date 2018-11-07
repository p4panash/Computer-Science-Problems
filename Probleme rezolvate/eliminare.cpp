#include <fstream>
#include <iostream>
using namespace std;

int eliminate[100005];
int numere[100005];

void Citire(int &n, int &q) {
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> eliminate[i];
    for (int i = 0; i < q; i++)
        cin >> numere[i];
}

int MaiMic(int n, int numar) {
    int st = 0, dr = n - 1;
    while (st <= dr) {
        int mij = st + (dr - st) / 2;
        if (eliminate[mij] < numar) {
            st = mij + 1;
        } else if (eliminate[mij] > numar) {
            dr = mij - 1;
        } else if (eliminate[mij] == numar){
            return numar;
        }
    }
    return st;
}

void Pozitie(int n, int q) {
    for (int i = 0; i < q; i++)
        cout << numere[i] - MaiMic(n, numere[i]) << endl;
}


int main() {
    freopen("eliminare.in", "r", stdin);
    freopen("eliminare.out", "w", stdout);
    int n, q;
    Citire(n, q);
    Pozitie(n, q);
    return 0;
}
