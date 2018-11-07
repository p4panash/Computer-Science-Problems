#include <iostream>
using namespace std;

double SquareRoot(double x, double eps) {
    double left, right, middle;
    left = 0;
    right = x;
    middle = (left + right) / 2;
    while (right - left > eps) {
        if (middle *  middle > x) {
            right = middle;
        } else {
            left = middle;
        }
        middle = double((right + left) / 2);
    }
    return middle;
}

int main() {
    //double x, eps;
    //cin >> x >> eps;
    cout << SquareRoot(5, 0.01) << '\n';
    cout << SquareRoot(5, 0.0001) << '\n';
    cout << SquareRoot(100, 0.0000001) << '\n';
    cout << SquareRoot(100, 0.1) << '\n';
    cout << SquareRoot(2, 0.01) << '\n';
}
