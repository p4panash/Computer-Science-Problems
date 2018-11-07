#include <iostream>
#include <fstream>
#include <thread>
#include <time.h>
#include <string.h>
using namespace std;

int contor;

void Adunare(char numere[], int termen) {
    int ordin = 0;
    int i = 8;
    ordin = ((numere[i] - '0') + termen) / 10;
    numere[i] = (((numere[i] - '0') + termen) % 10) + '0';
    while (ordin != 0 && i > 0) {
        i--;
        numere[i] = (((numere[i] - '0') + ordin) % 10) + '0';
        ordin = ((numere[i] - '0') + ordin) / 10;
    }
}

void Patrat(char numar[], char rezultat[], int lungime) {
    for (int i = lungime - 1; i >= 0; i--) {
        int ordin = 0;
        int cifra = lungime - i - 1;
        for (int j = lungime - 1; j >= 0 && j - cifra >= 0; j--) {
            int cifraAnterioara = rezultat[j - cifra] - '0';
            rezultat[j - cifra] = (((rezultat[j - cifra] - '0') + ((numar[i] - '0') * (numar[j] - '0')) + ordin) % 10) + '0';
            ordin = (ordin + cifraAnterioara + ((numar[i] - '0') * (numar[j] - '0'))) / 10;
        }
    }
}

bool Egal(char numar1[], char numar2[], int lungime) {
    for (int i = lungime - 1; i >= 0; i--)
        if (numar1[i] != numar2[i])
            return false;
    return true;
}

void NumarPatrate(string numarString, string limitaString) {
    char numar[10], limita[10];
    strcpy(numar, numarString.c_str());
    strcpy(limita, limitaString.c_str());
    while (!Egal(numar, limita, 9)) {
        char rezultat[10] = "000000000";
        Patrat(numar, rezultat, 9);
        if (Egal(rezultat, "987654321", 9))
            contor++;
        Adunare(numar, 1);
        cout << numar << " " << contor << endl;
    }
    cout << numar << " terminat !" << endl;
}

void Citeste(int &n) {
    cin >> n;
}

void Scrie(int &n) {
    cout << n;
}


void Run() {
    thread t[21];
    contor = 0;
    t[0] = thread(NumarPatrate, "100000000", "150000000");
    t[1] = thread(NumarPatrate, "150000001", "200000000");
    t[2] = thread(NumarPatrate, "200000001", "250000000");
    t[3] = thread(NumarPatrate, "250000001", "300000000");
    t[4] = thread(NumarPatrate, "300000001", "350000000");
    t[5] = thread(NumarPatrate, "350000001", "400000000");
    t[6] = thread(NumarPatrate, "400000001", "450000000");
    t[7] = thread(NumarPatrate, "450000001", "500000000");
    t[8] = thread(NumarPatrate, "500000001", "550000000");
    t[9] = thread(NumarPatrate, "550000001", "600000000");
    t[10] = thread(NumarPatrate, "600000001", "650000000");
    t[11] = thread(NumarPatrate, "650000001", "700000000");
    t[12] = thread(NumarPatrate, "700000001", "750000000");
    t[13] = thread(NumarPatrate, "750000001", "800000000");
    t[14] = thread(NumarPatrate, "800000001", "850000000");
    t[15] = thread(NumarPatrate, "850000001", "900000000");
    t[16] = thread(NumarPatrate, "900000001", "950000000");
    t[17] = thread(NumarPatrate, "950000001", "999999999");
    for (int i = 0; i <= 17; i++)
        t[i].join();
    cout << contor;
}

int main() {
    Run();
    return 0;
}
