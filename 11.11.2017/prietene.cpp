#include <iostream>
#include <climits>
using namespace std;

void Read(int &a, int &b) {
    cin >> a >> b;
}

int DivisorSum(int number) {
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
        if (number % i == 0)
            sum += i;
    sum += number;
    return sum;
}

void GatherSums(int sum[], int a, int b) {
    for (int i = 0; i <= b - a; i++)
        sum[i] = DivisorSum(a + i);
}

void PrintGroups(int sum[], int a, int b) {
    for (int i = 0; i <= b - a; i++)
        for (int j = i + 1; j <= b - a; j++)
            if (sum[i] == sum[j])
                cout << a + i << " " << a + j << '\n';
}

int main() {
    int a, b;
    int sum[1005];
    Read(a, b);
    GatherSums(sum, a, b);
    PrintGroups(sum, a, b);
    return 0;
}
