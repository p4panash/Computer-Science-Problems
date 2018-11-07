#include <fstream>
#include <iostream>
using namespace std;

ifstream in("cd1.in");
ofstream out("cd1.out");

void Citire(int &n, int &s, pair<int, int> mutari[]) {
    in >> n >> s;
    for (int i = 1; i <= n; i++) {
        in >> mutari[i].first;
        in >> mutari[i].second;
    }
}

void Init(int sir[], int n, int s) {
    for (int i = 1; i <= n; i++)
        sir[i] = s / n;
}

void FormaInitiala(int sir[], pair<int, int> mutari[], int n) {
    for (int i = 1; i <= n; i++) {
        sir[mutari[i].second] -= mutari[i].first;
        sir[i] += mutari[i].first;
    }
}

int NumarModalitati(int sir[], int n) {
    int modalitati = 1;
    for (int i = 1; i <= n; i++) {
        modalitati *= sir[i] - 1;
        modalitati = modalitati % 9901;
    }
    return modalitati % 9901;
}

int main() {
    int n, s;
    pair<int, int> mutari[301];
    Citire(n, s, mutari);
    int sir[301];
    Init(sir, n, s);
    FormaInitiala(sir, mutari, n);
    out << NumarModalitati(sir, n);
    in.close();
    out.close();
    return 0;
}
