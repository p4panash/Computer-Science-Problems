#include <fstream>
using namespace std;

ifstream in("comori.in");
ofstream out("comori.out");

void read(int steps[]) {
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        int step, number_of_steps;
        in >> step >> number_of_steps;
        steps[step - 1] += number_of_steps;
    }
}

void walk(int steps[], int &x, int &y) {
    int step_x[9] = { 0, 1, 1, 1, 0, -1, -1, -1};
    int step_y[9] = { 1, 1, 0, -1, -1, -1, 0, 1};
    for (int i = 0; i <= 7; i++) {
        x += step_x[i] * steps[i];
        y += step_y[i] * steps[i];
    }
}

int main() {
    int steps[41] = {0};
    read(steps);
    int x = 0, y = 0;
    walk(steps, x, y);
    out << x << " " << y;
    return 0;
}
