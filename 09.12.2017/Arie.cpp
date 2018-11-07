#include <iostream>
using namespace std;

const int MAX_SIZE = 101;

int Read(int plan[][MAX_SIZE], int &n, int &m) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> plan[i][j];
}

void init(bool visited[][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
}

void Walk(int plan[][MAX_SIZE], bool visited[][MAX_SIZE], int n, int m, int i, int j, int &steps) {
    int dX[4] = {-1, 0, 1, 0};
    int dY[4] = {0, -1, 0, 1};
    if (i >= 0 && i < n && j >= 0 && j < m && plan[i][j] != 0 && !visited[i][j]) {
        steps++;
        visited[i][j] = true;
        for (int h = 0; h < 4; h++)
            Walk(plan, visited, n, m, i + dX[h], j + dY[h], steps);
    }
}

int GetMaximalArea(int plan[][MAX_SIZE], bool visited[][MAX_SIZE], int n, int m) {
    int max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (plan[i][j] != 0 && !visited[i][j]) {
                int steps = 0;
                Walk(plan, visited, n, m, i, j, steps);
                if (steps > max) {
                    max = steps;
                }
            }
        }
    return max;
}

int main() {
    int plan[MAX_SIZE][MAX_SIZE];
    bool visited[MAX_SIZE][MAX_SIZE];
    int n, m;

    Read(plan, n, m);
    init(visited, n, m);
    cout << GetMaximalArea(plan, visited, n, m);
}
