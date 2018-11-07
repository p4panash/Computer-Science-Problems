#include <iostream>
using namespace std;
const int MAX_SIZE = 1005;

void Read(int list[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> list[i];
}

void init(bool visited[MAX_SIZE]) {
    for (int i = 1; i < MAX_SIZE; i++)
        visited[i] = false;
}

bool IsPermutation(bool visited[], int index) {
    int j = 1;
    while (j <= index + 1) {
        if (!visited[j])
            return false;
        j++;
    }
    return true;
}

int CountPrefix(int list[], bool visited[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        visited[list[i]] = true;
        if (IsPermutation(visited, i))
            count++;
    }
    return count;
}

int main() {
    int n;
    int list[MAX_SIZE];
    Read(list, n);

    bool visited[MAX_SIZE];
    init(visited);
    cout << CountPrefix(list, visited, n);
}
