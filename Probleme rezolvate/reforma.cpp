#include <fstream>
#include <iostream>
using namespace std;

ifstream in("reforma.in");
ofstream out("reforma.out");

void Citeste(int &sold) {
    in >> sold;
}


int GenerareModuriPlata(int sold, int monede[]) {
    int numarModuri = 0;
    int soldCurent = sold;
    for (int ron = 0; ron <= sold / monede[3]; ron++)
        for (int rin = 0; rin <= (sold - ron * monede[3]) / monede[2]; rin++)
            for (int ren = 0; ren <= (sold - rin * monede[2] - ron * monede[3]) / monede[1]; ren++)
                    numarModuri++;
    return numarModuri;
}

int main() {
    int const RAN = 1;
    int monede[4] = {RAN, 5 * monede[0], 2 * monede[1], 2 * monede[2]};
    int sold = 0;
    Citeste(sold);
    out << GenerareModuriPlata(sold, monede);
    in.close();
    out.close();
    return 0;
}
