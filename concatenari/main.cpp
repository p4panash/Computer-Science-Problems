#include <iostream>
#include <fstream>
using namespace std;

void Citire(char s[], int cifre[], int &n) {
    cin.get(s, 11);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cifre[i];
}

void SubSir(char destinatie[], char sursa[], int lungime) {
    int i;
    for (i = 0; i < lungime; i++)
        destinatie[i] = sursa[i];
    destinatie[i] = NULL;
}

void Concatenare(char destinatie[], char sursa[]) {
    int i, j;
    for (i = 0; destinatie[i] != NULL; i++);
    for (j = 0; sursa[j] != NULL; j++)
        destinatie[i + j] = sursa[j];
    destinatie[i + j] = NULL;
}

void InversareSir(char destinatie[], char sursa[]) {
    int i, j;
    for (i = 0; sursa[i] != NULL; i++);
    i--;
    for (j = 0; i >= 0; i-- && j++)
        destinatie[j] = sursa[i];
    j++;
    destinatie[j] = NULL;
}

void ConcatenareSubSiruri(char s[], int cifre[], int n) {
    for (int i = 0; i < n; i++) {
        if (cifre[i] % 2 == 0) {
            char sir[10];
            SubSir(sir, s, cifre[i]);
            Concatenare(s, sir);
        } else {
            char sir[10], aux[10];
            SubSir(sir, s, cifre[i]);
            InversareSir(aux, sir);
            Concatenare(s, aux);
        }
    }
}

int main() {
    freopen("concatenari.in", "r", stdin);
    freopen("concatenari.out", "w", stdout);
    char s[250];
    int n, cifre[100];
    Citire(s, cifre, n);
    ConcatenareSubSiruri(s, cifre, n);
    cout << s;
    return 0;
}
