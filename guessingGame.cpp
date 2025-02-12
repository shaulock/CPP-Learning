#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber(int min, int max) {
    srand(time(0));
    return rand() % (max - min + 1) + min;
}

int main() {
    int numberOfGuesses = 3;
    int randomNumber = generateRandomNumber(1, 10);
    int guess;
    string hotOrCold;
    bool hasWon = false;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 10." << endl;
    for (int i = 0; i < numberOfGuesses; i++) {
        cout << "You have " << numberOfGuesses - i << " guesses to guess my number." << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess == randomNumber) {
            hasWon = true;
            break;
        } else {
            if (i < numberOfGuesses - 1) {
                if (guess < randomNumber) {
                    hotOrCold = "cold";
                } else {
                    hotOrCold = "hot";
                }
                cout << "Incorrect " << hotOrCold << " guess. Try again." << endl;
            }
        }
    }
    if (hasWon) {
        cout << "Congratulations! You guessed the correct number." << endl;
    } else {
        cout << "Sorry! You ran out of guesses. The correct number was " << randomNumber << "." << endl;
    }

    system("pause>0");
    system("cls");
    
    return 0;
}