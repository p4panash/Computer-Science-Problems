#include <iostream>
#include <fstream>
using namespace std;

void GasireCuvinte(char text[], char cuvinte[][25], int &numarCuvinte) {
    int inceput = -1;
    numarCuvinte = 0;
    for (int i = 0; text[i] != NULL; i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || text[i] == '-') {
            if (inceput == - 1) {
                inceput = i;
            }
            cuvinte[numarCuvinte][i - inceput] = text[i];
        } else {
            if (inceput != -1) {
                cuvinte[numarCuvinte][i - inceput] = NULL;
                numarCuvinte++;
                inceput = -1;
            }
        }
    }
}

int LungimeCuvant(char cuvant[]) {
    int i;
    for (i = 0; cuvant[i] != NULL; i++);
    return i;
}

int NumarVocaleCuvant(char cuvant[]) {
    int vocale = 0;
    for (int i = 0; cuvant[i] != NULL; i++)
        if (cuvant[i] == 'a' || cuvant[i] == 'e' || cuvant[i] == 'i' || cuvant[i] == 'o' || cuvant[i] == 'u' ||
            cuvant[i] == 'A' || cuvant[i] == 'E' || cuvant[i] == 'I' || cuvant[i] == 'O' || cuvant[i] == 'U')
            vocale++;
    return vocale;
}

void CopiereCuvant(char cuvantCopiat[], char cuvantDeCopiat[]) {
    int i;
    for (i = 0; cuvantDeCopiat[i] != NULL; i++)
        cuvantCopiat[i] = cuvantDeCopiat[i];
    cuvantCopiat[i] = NULL;
}

void SortareCuvinte(char cuvinte[][25], int numarCuvinte) {
    for (int i = 0; i < numarCuvinte - 1; i++)
        for (int j = i + 1; j < numarCuvinte; j++)
            if (NumarVocaleCuvant(cuvinte[i]) < NumarVocaleCuvant(cuvinte[j])) {
                char aux[26];
                CopiereCuvant(aux, cuvinte[j]);
                CopiereCuvant(cuvinte[j], cuvinte[i]);
                CopiereCuvant(cuvinte[i], aux);
            } else if (NumarVocaleCuvant(cuvinte[i]) == NumarVocaleCuvant(cuvinte[j]) &&
                       LungimeCuvant(cuvinte[i]) < LungimeCuvant(cuvinte[j])) {
                        char aux[26];
                        CopiereCuvant(aux, cuvinte[j]);
                        CopiereCuvant(cuvinte[j], cuvinte[i]);
                        CopiereCuvant(cuvinte[i], aux);
                    }
}

void AfisareCuvinte(char cuvinte[][25], int numarCuvinte) {
    for (int i = 0; i < numarCuvinte; i++) {
        cout << cuvinte[i] << '\n';
    }
}

int main() {
    freopen("text.in", "r", stdin);
    freopen("text.out", "w", stdout);
    char text[260];
    char cuvinte[260][25];
    int numarCuvinte;
    cin.get(text, 255);
    GasireCuvinte(text, cuvinte, numarCuvinte);
    SortareCuvinte(cuvinte, numarCuvinte);
    AfisareCuvinte(cuvinte, numarCuvinte);
    return 0;
}
