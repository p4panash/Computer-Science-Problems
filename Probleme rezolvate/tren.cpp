#include <iostream>
#include <fstream>

using namespace std;
ifstream in("tren.in");
ofstream out("tren.out");

int Pow(int no, int power) {
    int result = 1;
    for (int i = 1; i <= power; i++)
        result *= no;
    return result;
}

void Citire(int sir[], int &n, int &etapa) {
    int power;
    in >> power >> etapa;
    n = Pow(2, power);
    for (int i = 1; i <= n; i++) {
        in >> sir[i];
    }
}

int Suma(int sir[], int n, int etapa, int start) {
    int result = 0;
    if (etapa == 1) {
        for (int i = 1; i <= n; i++)
            result += sir[i];
    } else {
        for (int i = start; i <= n; i+= Pow(2, etapa - 1))
            result += sir[i];
    }
    return result;
}

int Calatori(int sir[], int n, int etapa) {
    int max = 0;
    for (int i = 1; i <= Pow(2, etapa - 1); i++) {
        int result = Suma(sir, n, etapa, i);
        if (result > max)
            max = result;
    }
    return max;
}

int main() {
    int sir[2049], n, etapa;
    Citire(sir, n, etapa);
    out << Calatori(sir, n, etapa);
    in.close();
    out.close();
    return 0;
}
