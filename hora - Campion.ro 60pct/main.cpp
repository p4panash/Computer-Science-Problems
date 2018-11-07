#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream in("hora.in");
ofstream out("hora.out");

char copii[145010][15];

void Citire(int &numarCopii) {
    char copil[20];
    numarCopii = 0;
    while (in >> copil) {
        strcpy(copii[numarCopii], copil);
        numarCopii++;
    }
}


void InitHora(int numarCopii) {
    for (int i = 0; i < numarCopii; i++)
        hora[i] = i;
}


bool VerificareCopil(int i, int numarCopii) {
    if (numarCopii <= 1)
        return true;
    if (copii[i][strlen(copii[i]) - 1] == '*') {
            if (i == 0) {
                if(copii[numarCopii - 1][strlen(copii[numarCopii - 1]) - 1] == '*' ||
                   copii[i + 1][strlen(copii[i + 1]) - 1] == '*')
                   return false;
            } else if (i == numarCopii - 1) {
                if(copii[i - 1][strlen(copii[i - 1]) - 1] == '*' ||
                   copii[0][strlen(copii[0]) - 1] == '*')
                   return false;
            } else {
                if(copii[i - 1][strlen(copii[i - 1]) - 1] == '*' ||
                   copii[i + 1][strlen(copii[i + 1]) - 1] == '*')
                   return false;
            }
        } else {
            if (i == 0) {
                if(copii[numarCopii - 1][strlen(copii[numarCopii - 1]) - 1] != '*' ||
                   copii[i + 1][strlen(copii[i + 1]) - 1] != '*')
                   return false;
            } else if (i == numarCopii - 1) {
                if(copii[i - 1][strlen(copii[i - 1]) - 1] != '*' ||
                   copii[0][strlen(copii[0]) - 1] != '*')
                   return false;
            } else {
                if(copii[i - 1][strlen(copii[i - 1]) - 1] != '*' ||
                   copii[i + 1][strlen(copii[i + 1]) - 1] != '*')
                   return false;
            }
        }
        return true;
}

bool Verificare(int numarCopii) {
    for (int i = 0; i < numarCopii; i++) {
        if (!VerificareCopil(i, numarCopii))
            return false;
    }
    return true;
}

void EliminareCopil(int i, int &numarCopii) {
    for (; i < numarCopii - 1; i++)
        strcpy(copii[i], copii[i + 1]);
    numarCopii--;
}

int EliminareHora(int numarCopii) {
    int copiiEliminati = 0;
    for (int i = 0; !Verificare(numarCopii); i++) {
        if (i == numarCopii) {
            i = 0;
        }
        if (!VerificareCopil(i, numarCopii) && i < numarCopii) {
            EliminareCopil(i, numarCopii);
            copiiEliminati++;
        }
    }
    return copiiEliminati;
}

int main() {
    int numarCopii;
    Citire(numarCopii);
    out << EliminareHora(numarCopii);
    return 0;
}
