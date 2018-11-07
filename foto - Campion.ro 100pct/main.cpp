#include <iostream>
#include <fstream>
using namespace std;

const int MARIME_MAXIMA = 105;

void Citire(bool fotografie[][MARIME_MAXIMA], int &n, int &m) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> fotografie[i][j];
        }
}

void InitializareVizitat(bool vizitat[][MARIME_MAXIMA], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vizitat[i][j] = false;
}

void NumarElementeLuminoase(int yPos, int xPos, int n, int m, bool fotografie[][MARIME_MAXIMA], bool vizitat[][MARIME_MAXIMA], int &elemente) {
    vizitat[yPos][xPos] = true;
    elemente++;
    int dX[4] = {-1, 0, 1, 0};
    int dY[4] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        if (xPos + dX[i] >= 0 && xPos + dX[i] < m && yPos + dY[i] >= 0 && yPos + dY[i] < n && !vizitat[yPos + dY[i]][xPos + dX[i]] && !fotografie[yPos + dY[i]][xPos + dX[i]])
            NumarElementeLuminoase(yPos + dY[i], xPos + dX[i], n, m, fotografie, vizitat, elemente);
    }
}

void ZonaMaximLuminata(bool fotografie[][MARIME_MAXIMA], bool vizitat[][MARIME_MAXIMA], int n, int m, int &maximElemente) {
    InitializareVizitat(vizitat, n, m);
    maximElemente = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!fotografie[i][j] && !vizitat[i][j]) {
                int elemente = 0;
                NumarElementeLuminoase(i, j, n, m, fotografie, vizitat, elemente);
                if (elemente > maximElemente)
                    maximElemente = elemente;
            }
}

int main() {
    freopen("foto.in", "r", stdin);
    freopen("foto.out", "w", stdout);
    int n, m, elementeZonaMaxima;
    bool fotografie[MARIME_MAXIMA][MARIME_MAXIMA], vizitat[MARIME_MAXIMA][MARIME_MAXIMA];
    Citire(fotografie, n, m);
    ZonaMaximLuminata(fotografie, vizitat, n, m, elementeZonaMaxima);
    cout << elementeZonaMaxima;
    return 0;
}
