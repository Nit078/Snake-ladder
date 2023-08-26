#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

int playTurn(int player, int position, int roll) {
    position += roll;
    
    int snakes[] = {16, 47, 49, 56, 62, 64, 87, 93, 95, 98};
    int ladders[] = {1, 4, 9, 21, 28, 36, 51, 71, 80};
    
    for (int i = 0; i < 10; i++) {
        if (position == snakes[i]) {
            cout << "Oops! Snake at position " << position << ". ";
            position -= (rand() % 10) + 1; // Move back a random number of steps
            break;
        }
        if (position == ladders[i]) {
            cout << "Yay! Ladder at position " << position << ". ";
            position += (rand() % 10) + 1; // Move forward a random number of steps
            break;
        }
    }
    
    cout << "Player " << player << " rolled a " << roll << ". New position: " << position << endl;
    return position;
}

int main() {
    srand(time(0));
    
    int positions[2] = {0};
    string playerNames[2];
    
    cout << "Welcome to Snake and Ladder Game!" << endl;
    
    cout << "Enter name for Player 1: ";
    getline(cin, playerNames[0]);
    
    cout << "Enter name for Player 2: ";
    getline(cin, playerNames[1]);
    
    int currentPlayer = 0;
    bool gameFinished = false;
    
    while (!gameFinished) {
        cout << playerNames[currentPlayer] << ", enter any input to roll the dice: ";
        cin.ignore();
        
        int roll = rollDice();
        positions[currentPlayer] = playTurn(currentPlayer + 1, positions[currentPlayer], roll);
        
        if (positions[currentPlayer] >= 100) {
            cout << playerNames[currentPlayer] << " wins!" << endl;
            gameFinished = true;
        }
        
        currentPlayer = (currentPlayer + 1) % 2;
    }
    
    cout << "Thanks for playing!" << endl;
    
    return 0;
}
