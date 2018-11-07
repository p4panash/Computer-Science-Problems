#include <iostream>
using namespace std;

void ReadActions(int actions[]) {
    for (int i = 0; i < 6; i++)
        cin >> actions[i];
}

bool RockSccisorsPaper(int input1, int input2) {
    if (input1 == 0 && input2 == 1)
        return true;
    if (input1 == 1 && input2 == 2)
        return true;
    if (input1 == 2 && input2 == 0)
        return true;
    return false;
}

void Play(int &Player1, int &Player2, int actions[]) {
    for (int i = 0; i < 6; i += 2) {
        if (RockSccisorsPaper(actions[i], actions[i + 1])) {
            Player1++;
        } else {
            Player2++;
        }
    }
}

void Result(int Player1, int Player2) {
    if (Player1 > Player2) {
        cout << "P1 wins";
    } else {
        cout << "P2 wins";
    }
}

int main() {
    int Player1 = 0, Player2 = 0;
    int actions[10];
    ReadActions(actions);
    Play(Player1, Player2 , actions);
    Result(Player1, Player2);
}
