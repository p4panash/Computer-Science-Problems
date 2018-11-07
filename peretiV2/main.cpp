#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

//ofstream out("debug.out");
const int MAX_SIZE = 105;

void Citire(int harta[][MAX_SIZE], int &n, int &m) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> harta[i][j];
}

int pow(int numar, int putere) {
    int rezultat = 1;
    for (int i = 1; i <= putere; i++)
        rezultat *= numar;
    return rezultat;
}

void Descompunere(int numar, bool pereti[4]) {
    for (int i = 3; i >= 0; i--) {
        if (numar >= pow(2, i)) {
            pereti[i] = true;
            numar -= pow(2, i);
        }
    }
}

bool PereteComun(int yElement, int xElement, int coordonata, int harta[][MAX_SIZE], int n, int m) {
    bool peretiVecini[4] = {false};
    if (coordonata == 0) {
        if (xElement - 1 >= 0) {
                Descompunere(harta[yElement][xElement - 1], peretiVecini);
                if (peretiVecini[2])
                    return true;
        }
    }
    if (coordonata == 3) {
        if (yElement - 1 >= 0) {
                Descompunere(harta[yElement - 1][xElement], peretiVecini);
                if (peretiVecini[1])
                    return true;
        }
    }
    return false;
}

bool FormaInchisa(int yElement, int xElement, int harta[][MAX_SIZE], bool vizitat[][MAX_SIZE], int n, int m) {
    vizitat[yElement][xElement] = true;
    bool pereti[4] = {false};
    Descompunere(harta[yElement][xElement], pereti);
    if (pereti[0] == false && pereti[1] == false && pereti[2] == false && pereti[3] == false)
        return false;
    if (!pereti[0]) {
        if (xElement - 1 >= 0) {
            if (!vizitat[yElement][xElement - 1])
                if(FormaInchisa(yElement, xElement - 1, harta, vizitat, n, m) == false)
                    return false;
        } else {
            return false;
        }
    }
    if (!pereti[1]) {
        if (yElement + 1 < n) {
            if (!vizitat[yElement + 1][xElement])
                if(FormaInchisa(yElement + 1, xElement, harta, vizitat, n, m) == false)
                    return false;
        } else {
            return false;
        }
    }
    if (!pereti[2]) {
        if (xElement + 1 < m) {
            if (!vizitat[yElement][xElement + 1])
                if(FormaInchisa(yElement, xElement + 1, harta, vizitat, n, m) == false)
                    return false;
        } else {
            return false;
        }
    }
    if (!pereti[3]) {
        if (yElement - 1 >= 0) {
            if (!vizitat[yElement - 1][xElement])
                if(FormaInchisa(yElement - 1, xElement, harta, vizitat, n, m) == false)
                    return false;
        } else {
            return false;
        }
    }
    return true;
}

void InitVizitat(bool vizitat[][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vizitat[i][j] = false;
}

bool VerificareForma(int yElement, int xElement, int c, int harta[][MAX_SIZE], int n, int m) {
    bool vizitat[MAX_SIZE][MAX_SIZE], formaElementCurent, formaElementVecin, vecin = true;
    InitVizitat(vizitat, n, m);
    formaElementCurent = FormaInchisa(yElement, xElement, harta, vizitat, n, m);
    InitVizitat(vizitat, n, m);
    if (c == 0) {
        if (xElement - 1 >= 0) {
            formaElementVecin = FormaInchisa(yElement, xElement - 1, harta, vizitat, n, m);
        } else {
            vecin = false;
        }
    }
    if (c == 1) {
        if (yElement + 1 < n) {
            formaElementVecin = FormaInchisa(yElement + 1, xElement, harta, vizitat, n, m);
        } else {
            vecin = false;
        }
    }
    if (c == 2) {
        if (xElement + 1 < m) {
            formaElementVecin = FormaInchisa(yElement, xElement + 1, harta, vizitat, n, m);
        } else {
            vecin = false;
        }
    }
    if (c == 3) {
        if (yElement - 1 >= 0) {
            formaElementVecin = FormaInchisa(yElement - 1, xElement, harta, vizitat, n, m);
        } else {
            vecin = false;
        }
    }
    if (vecin)
        return formaElementCurent || formaElementVecin;
    return formaElementCurent;
}

int NumarPereti(int harta[][MAX_SIZE], int n, int m) {
    int numar = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            bool pereti[4] = {false};
            Descompunere(harta[i][j], pereti);
            for (int c = 0; c < 4; c++) {
                if (pereti[c]) {
                    if (VerificareForma(i, j, c, harta, n, m)) {
                        //forma inchisa
                        if (!PereteComun(i, j, c, harta, n, m) && ) {
                            numar++;
                            //out << i << " " << j << " " << c << " " << harta[i][j] << " +1" << '\n';
                        }
                    } else {
                        //forma deschisa
                        if (!PereteComun(i, j, c, harta, n, m)) {
                            numar += 2;
                            //out << i << " " << j << " " << c << " " << harta[i][j] << " +2" << '\n';
                        }
                    }
                }
            }
        }
    return numar;
}


void test(int harta[][MAX_SIZE], int n, int m) {
    assert(VerificareForma(3, 1, 2, harta, n, m) == false);
    //bool vizitat[MAX_SIZE][MAX_SIZE];
    //InitVizitat(vizitat, n, m);
    //assert(FormaInchisa(4, 1, harta, vizitat, n, m) == false);
    //InitVizitat(vizitat, n, m);
    //assert(FormaInchisa(4, 3, harta, vizitat, n, m) == false);
}



int main() {
    freopen("pereti.in", "r", stdin);
    freopen("pereti.out", "w", stdout);
    int n, m;
    int harta[MAX_SIZE][MAX_SIZE];
    Citire(harta, n, m);
    test(harta, n, m);
    //cout << NumarPereti(harta, n, m);
}
