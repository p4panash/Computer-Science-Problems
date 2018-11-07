#include <iostream>
#include <fstream>

using namespace std;
ifstream in("carte1.in");
ofstream out("carte1.out");

void Read(int sir[], int &n) {
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> sir[i];
}

void ReadBook(int sir[], int n, int &zile, int &ziuaMax, int &paginiMax) {
    int ziua = 0, pagina = 1, paginiCitite = 0;
    paginiMax = 0;
    while (pagina < n) {
        for (int i = 1; i <= n; i++)
            if (sir[i] == pagina) {
                pagina++;
                paginiCitite++;
            }
        if (paginiCitite > paginiMax) {
            ziuaMax = ziua;
            paginiMax = paginiCitite;
        }
        ziua++;
        paginiCitite = 0;
    }
    zile = ziua;
}

void Write(int zile, int ziuaMax, int paginiMax) {
    out << zile << " " << ziuaMax + 1 << " " << paginiMax;
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
