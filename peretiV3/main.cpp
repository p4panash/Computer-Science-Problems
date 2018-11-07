#include <iostream>
#include <fstream>
//#include <assert.h>
using namespace std;

//ofstream out("debug.out");
int const MAX_SIZE = 105;

void Citire(int harta[][MAX_SIZE], int &n, int &m) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> harta[i][j];
}

struct hartaBinara{
    bool pereti[5];
} binara[MAX_SIZE][MAX_SIZE];
bool vizitat[MAX_SIZE][MAX_SIZE];

int pow(int numar, int putere) {
    int rezultat = 1;
    for (int i = 1; i <= putere; i++) {
        rezultat *= numar;
    }
    return rezultat;
}

void Descompunere(int harta[][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int valoare = harta[i][j];
            for (int p = 3; p >= 0; p--) {
                if (valoare >= pow(2, p)) {
                    binara[i][j].pereti[p] = true;
                    valoare -= pow(2, p);
                }
            }
        }
}

void InitVizitat(int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vizitat[i][j] = false;
}

bool PereteComun(int yElement, int xElement, int coordonata, int n, int m) {
    if (coordonata == 0) {
        if (xElement - 1 >= 0 && binara[yElement][xElement - 1].pereti[2])
            return true;
    }
    if (coordonata == 1) {
        if (yElement + 1 < n && binara[yElement + 1][xElement].pereti[3])
            return true;
    }
    if (coordonata == 2) {
        if (xElement + 1 < m && binara[yElement][xElement + 1].pereti[0])
            return true;
    }
    if (coordonata == 3) {
        if (yElement - 1 >= 0 && binara[yElement - 1][xElement].pereti[1])
            return true;
    }
    return false;
}

bool FormaInchisa(int yElement, int xElement, int n, int m) {
    vizitat[yElement][xElement] = true;
    if (binara[yElement][xElement].pereti[0] == false && binara[yElement][xElement].pereti[1] == false
        && binara[yElement][xElement].pereti[2] == false  && binara[yElement][xElement].pereti[3] == false)
            return false;
	//verific daca exista un drum "liber" pe directiile în care nu sunt pereți
    if(!binara[yElement][xElement].pereti[0]) {
        if (xElement - 1 >= 0) {
            if (!vizitat[yElement][xElement - 1])
                if(FormaInchisa(yElement, xElement - 1, n, m) == false)
                    return false;
        } else {
            return false;
        }
    }
    if (!binara[yElement][xElement].pereti[1]) {
        if (yElement + 1 < n) {
                if (!vizitat[yElement + 1][xElement])
                    if(FormaInchisa(yElement + 1, xElement, n, m) == false)
                        return false;
            } else {
                return false;
            }
    }
    if (!binara[yElement][xElement].pereti[2]) {
        if (xElement + 1 < m) {
            if (!vizitat[yElement][xElement + 1])
                if(FormaInchisa(yElement, xElement + 1, n, m) == false)
                    return false;
        } else {
            return false;
        }
    }
    if (!binara[yElement][xElement].pereti[3]) {
        if (yElement - 1 >= 0) {
            if (!vizitat[yElement - 1][xElement])
                if(FormaInchisa(yElement - 1, xElement, n, m) == false)
                    return false;
        } else {
            return false;
        }
    }
    return true;
}

int NumarPereti(int n, int m) {
    int numar = 0;
    bool vizitat[MAX_SIZE][MAX_SIZE];
    int dX[4] = {-1, 0, 1, 0};
    int dY[4] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            for (int p = 0; p <= 3; p++) {
                if (binara[i][j].pereti[p]) {
                    InitVizitat(n, m);
                    bool formaElement = FormaInchisa(i, j, n, m);
                    bool vecin = false, formaVecin = false;
                    if ((i + dY[p] >= 0 && i + dY[p] < n) && (j + dX[p] >= 0 && j + dX[p] < m)) {
                        vecin = true;
                        InitVizitat(n, m);
                        formaVecin = FormaInchisa(i + dY[p], j + dX[p], n, m);
                    }
                    if (formaElement) {
                        if (vecin && !formaVecin) {
                            if (!PereteComun(i, j, p, n, m)) {
                                //out << i << " " << j << " " << p << " +1" << '\n';
                                numar++;
                            } else if (p != 0 && p != 3) {
                                //out << i << " " << j << " " << p << " +1" << '\n';
                                numar++;
                            }
                        } else if (!vecin) {
                            if (!PereteComun(i, j, p, n, m)) {
                                //out << i << " " << j << " " << p << " +1" << '\n';
                                numar++;
                            } else if (p != 0 && p != 3) {
                                //out << i << " " << j << " " << p << " +1" << '\n';
                                numar++;
                            }
                        }
                    } else {
                        if (vecin && !formaVecin) {
                            if (!PereteComun(i, j, p, n, m)) {
                                //out << i << " " << j << " " << p << " +2" << '\n';
                                numar += 2;
                            } else if (p != 0 && p != 3) {
                                //out << i << " " << j << " " << p << " +2" << '\n';
                                numar += 2;
                            }
                        } else {
                            if (!PereteComun(i, j, p, n, m)) {
                                //out << i << " " << j << " " << p << " +2" << '\n';
                                numar += 2;
                            } else if (p != 0 && p != 3) {
                                //out << i << " " << j << " " << p << " +1" << '\n';
                                numar += 1;
                            }
                        }
                    }
                }
            }
        }
    return numar;
}

void Afisare(int harta[][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << harta[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    freopen("pereti.in", "r", stdin);
    freopen("pereti.out", "w", stdout);
    int harta[MAX_SIZE][MAX_SIZE], n, m;
    Citire(harta, n, m);
    Descompunere(harta, n, m);
    cout << NumarPereti(n, m);
    return 0;
}
