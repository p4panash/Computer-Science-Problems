#include <iostream>
#include <fstream>
#include <strings.h>
using namespace std;
const int MAX_SIZE = 10;

char dictionar[MAX_SIZE][MAX_SIZE];
int taste[MAX_SIZE], nrTaste, marimeDictionar;

void Citire() {
    cin >> marimeDictionar;
    cin.get();
    for (int i = 0; i < marimeDictionar; i++) {
        cin.get(dictionar[i], 100);
        cin.get();
    }
    cin >> nrTaste;
    for (int i = 0; i < nrTaste; i++)
        cin >> taste[i];
}

bool T9(char cuvantDictionar[], char cuvantT9[]) {
    int i;
    for (i = 0; cuvantDictionar[i] != NULL && cuvantT9[i] != NULL; i++) {
        if ((((cuvantDictionar[i] - 'A') / 3 + 2) != (cuvantT9[i] - '0') && cuvantDictionar[i] < 'Z') ||
            (cuvantDictionar[i] == 'Z' && cuvantT9[i] != '9')) {
            return false;
        }
    }
    if (cuvantDictionar[i] != NULL || cuvantT9[i] != NULL)
        return false;
    return true;
}

int CautaCuvant(char cuvant[]) {
    for (int i = 0; i < marimeDictionar; i++)
        if (T9(dictionar[i], cuvant))
            return i;
    return -1;
}

void AfisareCuvantInexistent(int inceput, int sfarsit) {
    for (int i = inceput; i < sfarsit; i++)
        cout << "*";
}

void SimulareT9() {
    int inceputCuvant = -1, sfarsitCuvant;
    char cuvant[100] = "";
    for (int i = 0; i < nrTaste; i++) {
        if (inceputCuvant == -1 && taste[i] != 1) {
            inceputCuvant = i;
            sfarsitCuvant = i;
            cuvant[sfarsitCuvant - inceputCuvant] = char(taste[i] + '0');
        } else if (taste[i] != 1) {
            sfarsitCuvant++;
            cuvant[sfarsitCuvant - inceputCuvant] = char(taste[i] + '0');
        } else if (taste[i] == 1) {
            sfarsitCuvant++;
            cuvant[sfarsitCuvant - inceputCuvant] = NULL;
            int indexCuvant = CautaCuvant(cuvant);
            if (indexCuvant != -1) {
                cout << dictionar[indexCuvant];
                strcpy(cuvant, "");
            } else {
                AfisareCuvantInexistent(inceputCuvant, sfarsitCuvant);
            }
            inceputCuvant = -1;
            cout << " ";
        }
        if (i == nrTaste - 1 && inceputCuvant != -1) {
            sfarsitCuvant++;
            cuvant[sfarsitCuvant - inceputCuvant] = NULL;
            int indexCuvant = CautaCuvant(cuvant);
            if (indexCuvant != -1) {
                cout << dictionar[indexCuvant];
            } else {
                AfisareCuvantInexistent(inceputCuvant, sfarsitCuvant);
            }
        }
    }

}

int main() {
    freopen("sms.in", "r", stdin);
    //freopen("dictionar.out", "w", stdout);
    Citire();
    SimulareT9();
    return 0;
}
