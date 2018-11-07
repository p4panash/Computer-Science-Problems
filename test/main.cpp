#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

void Citire(char dictionar[][MAX_SIZE], int &marimeDictionar, int taste[], int &numarTaste) {
    cin >> marimeDictionar;
    for (int i = 0; i < marimeDictionar; i++) {
        cin.get();
        cin.get(dictionar[i], 105);
    }
    cin >> numarTaste;
    for (int i = 0; i < numarTaste; i++)
        cin >> taste[i];
}

int main() {
    freopen("test.in", "r", stdin);
    char sir[MAX_SIZE][MAX_SIZE];
    int n , m;
    int sirM[20];
    Citire(sir, n, sirM, m);
    for (int i = 0; i < n; i++) {
        cout << sir[i] << endl;
    }
}
