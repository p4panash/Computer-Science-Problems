#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
using namespace std;

const int MAX_SIZE = 20;

char litera[2], cuvant[MAX_SIZE];

struct cartonas {
    char litera;
    char secventa[MAX_SIZE];
} cartonase[MAX_SIZE];
int numarCartonase;

void Citire() {
    cin.get(litera, 2);
    cin.get();
    cin.get(cuvant, MAX_SIZE);
    cin.get();
    cin >> numarCartonase;
    for (int i = 0; i < numarCartonase; i++) {
        cin.get();
        cin >> cartonase[i].litera;
        cin.get();
        cin.get(cartonase[i].secventa, MAX_SIZE);
    }
}

bool PotrivireCuvant(char cuvantFormat[], char literaCartonas) {
    for (int i = 0; cuvantFormat[i] != NULL; i++) {
        if (cuvantFormat[i] == literaCartonas) {
            return true;
        }
    }
    return false;
}

void GasireCartonase(int indiciCartonase[], int &cartonaseGasite, char cuvantFormat[]) {
    cartonaseGasite = 0;
    for (int i = 0; i < numarCartonase; i++) {
        if (PotrivireCuvant(cuvantFormat, cartonase[i].litera)) {
            indiciCartonase[cartonaseGasite] = i;
            cartonaseGasite++;
        }
    }
}

void Inlocuire(char cuvant[], char cuvant2[], int indice) {
    for (int i = strlen(cuvant) - 1; i > indice; i--) {
        cuvant[i + strlen(cuvant2) - 1] = cuvant[i];
    }
    for (int i = indice, j = 0; j < strlen(cuvant2); i++, j++) {
        cuvant[i] = cuvant2[j];
    }
}

bool Verificare(char cuvantFormat[], int numarMutari) {
    for (int i = 0; i <= numarMutari; i++)
        if (cuvantFormat[i] != cuvant[i])
            return false;
    return true;
}

void FormareCuvant(char cuvantFormat[], int numarMutari, int &numarMinim) {
    if (strcmp(cuvantFormat, cuvant) == 0) {
        if (numarMutari < numarMinim)
            numarMinim = numarMutari;
    } else if (strlen(cuvantFormat) < strlen(cuvant)) {
        int indiciCartonase[MAX_SIZE], cartonaseGasite;
        GasireCartonase(indiciCartonase, cartonaseGasite, cuvantFormat);
        for (int i = 0; i < cartonaseGasite; i++) {
            for (int j = 0; j <= strlen(cuvantFormat) - 1; j++) {
                if (cuvantFormat[j] == cartonase[indiciCartonase[i]].litera) {
                    char varianta[MAX_SIZE] = "";
                    strcpy(varianta, cuvantFormat);
                    Inlocuire(varianta, cartonase[indiciCartonase[i]].secventa, j);
                    if (Verificare(varianta, numarMutari)) {
                        FormareCuvant(varianta, numarMutari + 1, numarMinim);
                    }
                }
            }
        }
    }
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    char cuvantFormat[MAX_SIZE] = "";
    int numarMinim = INT_MAX;
    Citire();
    strcat(cuvantFormat, litera);
    cout << FormareCuvant(cuvantFormat, 0, numarMinim);
    cout << numarMinim;
    return 0;
}
