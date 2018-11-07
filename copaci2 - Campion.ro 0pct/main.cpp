#include <iostream>
#include <fstream>
using namespace std;

void Citire(int copaci[], int &n) {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> copaci[i];
}

int AflareNumarModuri(int copaci[], int n) {
    int nr = 0;
    for (int a = 2; a <= n - 1; a++) {
        int b, c;
        for (b = a - 1; b >= 1 && copaci[b] <= copaci[a]; b--);
        for (c = a + 1; c <= n && copaci[c] <= copaci[a]; c++);
        if (copaci[a] < copaci[b] && copaci[a] < copaci[c] && b >= 1 && c <= n)
            nr++;
    }
    return nr;
}

int main() {
    freopen("copaci2.in", "r", stdin);
    freopen("copaci2.out", "w", stdout);
    int copaci[200005], n, nrModuri;
    Citire(copaci, n);
    cout << AflareNumarModuri(copaci, n);
    return 0;
}
