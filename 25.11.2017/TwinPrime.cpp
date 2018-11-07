#include <iostream>
#include <climits>
using namespace std;

void Read(int numbers[], int &listSize) {
    int number;
    listSize = 0;
    cin >> number;
    while (number != 0) {
        numbers[listSize] = number;
        listSize++;
        cin >> number;
    }
}

bool IsPrime(int number) {
    if (number < 2)
        return false;
    for (int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int modulo(int number) {
    if (number < 0)
        return -number;
    return number;
}

bool IsUnique(pair<int, int> pairs[], int numberOfPairs, pair<int, int> pairToCheck) {
    for (int i = 0; i < numberOfPairs; i++) {
        if ((pairs[i].first == pairToCheck.first && pairs[i].second == pairToCheck.second) ||
            (pairs[i].first == pairToCheck.second && pairs[i].second == pairToCheck.first))
            return false;
    }
    return true;
}

void GetPairs(int numbers[], int listSize, pair<int, int> pairs[], int &numberOfPairs) {
    for (int i = 0; i < listSize; i++)
        for (int j = i + 1; j < listSize; j++) {
            if ((IsPrime(numbers[i]) && IsPrime(numbers[j])) && modulo(numbers[i] - numbers[j]) == 2) {
                pair<int,int> pairToCheck(numbers[i], numbers[j]);
                if (IsUnique(pairs, numberOfPairs, pairToCheck)) {
                    pairs[numberOfPairs] = pairToCheck;
                    numberOfPairs++;
                }
            }
        }
}

void PrintPairs(pair<int, int> pairs[], int numberOfPairs) {
    for (int i = 0; i < numberOfPairs; i++) {
        //if (pairs[i].first < pairs[i].second) {
            cout << pairs[i].first << " " << pairs[i].second << endl;
        //} else {
            //cout << pairs[i].second << " " << pairs[i].first << endl;
        //}
    }
}

int main() {
    int const SIZE = 1000;
    pair<int, int> pairs[SIZE];
    int numberOfPairs = 0;
    int numbers[SIZE];
    int listSize = 0;
    Read(numbers, listSize);
    GetPairs(numbers, listSize, pairs, numberOfPairs);
    PrintPairs(pairs, numberOfPairs);
}
