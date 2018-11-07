#include <iostream>
#include <fstream>
using namespace std;

ofstream out("debug.out");
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
	//verific daca exista un drum "liber" pe directiile în care nu sunt pereți
    if (!pereti[0]) {
        if (xElement - 1 >= 0) {
            if (!vizitat[yElement][xElement - 1])
                return FormaInchisa(yElement, xElement - 1, harta, n, m);
        } else {
            return false;
        }
    }
    if (!pereti[1]) {
        if (yElement + 1 < n) {
            if (!vizitat[yElement + 1][xElement])
                return FormaInchisa(yElement + 1, xElement, harta, n, m);
        } else {
            return false;
        }
    }
    if (!pereti[2]) {
        if (xElement + 1 < m) {
            if (!vizitat[yElement][xElement + 1])
                return FormaInchisa(yElement, xElement + 1, harta, n, m);
        } else {
            return false;
        }
    }
    if (!pereti[3]) {
        if (yElement - 1 >= 0) {
            if (!vizitat[yElement - 1][xElement])
                return FormaInchisa(yElement - 1, xElement, harta, n, m);
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

bool VerificareForma(int yElement, int xElement, int c, int harta, int n, int m) {
    bool vizitat[MAX_SIZE][MAX_SIZE], formaElementCurent, formaElementVecin;
    InitVizitat(vizitat, n, m);
    formaElementCurent = FormaInchisa(yElement, xElement, harta, vizitat, n, m);
    InitVizitat(vizitat, n, m);
	//verific forma vecinilor in functie de coordonata
    if (c == 0) {
        if (xElement - 1 >= 0) {
            formaElementVecin = FormaInchisa(yElement, xElement - 1, harta, vizitat, n, m);
        } else {
            formaElementVecin = false;
        }
    }
    if (c == 1) {
        if (yElement + 1 < n) {
            formaElementVecin = FormaInchisa(yElement + 1, xElement, harta, vizitat, n, m);
        } else {
            formaElementVecin = false;
        }
    }
    if (c == 2) {
        if (xElement + 1 < m) {
            formaElementVecin = FormaInchisa(yElement, xElement + 1, harta, vizitat, n, m);
        } else {
            formaElementVecin = false;
        }
    }
    if (c == 3) {
        if (yElement - 1 >= 0) {
            formaElementVecin = FormaInchisa(yElement - 1, xElement, harta, vizitat, n, m);
        } else {
            formaElementVecin = false;
        }
    }
    return formaElementCurent && formaElementVecin;
}

int NumarPereti(int harta[][MAX_SIZE], int n, int m) {
    int numar = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            bool pereti[4] = {false};
            Descompunere(harta[i][j], pereti);
            for (int c = 0; c < 4; c++) {
                if (pereti[c]) {
                    if (VerificareForma(i, j, harta, n, m)) {
                        //forma inchisa
                        if (!PereteComun(i, j, c, harta, n, m))
                            numar++;
                    } else {
                        //forma deschisa
                        if (!PereteComun(i, j, c, harta, n, m))
                            numar += 2;
                    }
                }
            }
        }
    return numar;
}


int main() {
    freopen("pereti.in", "r", stdin);
    //freopen("pereti.out", "w", stdout);
    int n, m;
    int harta[MAX_SIZE][MAX_SIZE];
    Citire(harta, n, m);
    cout << NumarPereti(harta, n, m);
}
