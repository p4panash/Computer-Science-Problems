#include <iostream>
#include <fstream>

using namespace std;
ifstream in("tren.in");
ofstream out("tren.out");

/*
void Read(int sir[], int &n) {
    in >> n;
    for (int i = 0; i < n; i++)
        in >> sir[i];
}

void ReadBook(int sir[], int n, int &zile, int &ziuaMax, int &paginiMax) {
    int ziua = 1, pagina = 1, paginiCitite = 0;
    paginiMax = 0;
    while (pagina < n) {
        int i = 0;
        while (i < n) {
            if (sir[i] == pagina) {
                pagina++;
                paginiCitite++;
            }
            i++;
        }
        if (paginiCitite > paginiMax) {
            ziuaMax = ziua;
            paginiMax = paginiCitite;
        }
        ziua++;
        paginiCitite = 0;
    }
    zile = ziua - 1;
}

void Write(int zile, int ziuaMax, int paginiMax) {
    out << zile << " " << ziuaMax << " " << paginiMax;
}

int main()
{
    int sir[10002], n, zile, ziuaMax, paginiMax;
    Read(sir, n);
    ReadBook(sir, n, zile, ziuaMax, paginiMax);
    Write(zile, ziuaMax, paginiMax);
    in.close();
    out.close();
}
*/


int Pow(int no, int power) {
    int result = 1;
    for (int i = 1; i <= power; i++)
        result *= no;
    return result;
}

void Citire(int sir[], int &n) {
    int power;
    in >> power;
    n = pow(n, power);
    for (int i = 1; i <= n; i++)
        in >> sir[i];
}

int Suma(int sir[], int n, int etapa, int start) {
    int result = 0;
    if (etapa == 1) {
        for (int i = 1; i <= n; i++)
            result += sum[i];
    } else {
        for (int i = start; i <= n; i+= pow(2, etapa - 1))
            result += sum[i];
    }
    return result;
}

int Calatori(int sir[], int n, int etapa) {
    int k = 1;
    int numarCalatori = 0;
    while (k <= etapa) {

    }
}
