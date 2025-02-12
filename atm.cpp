#include <iostream>
#include <chrono>
#include <thread>

#define ATM_PIN 1234
#define ATM_INITIAL_BALANCE 2000.0

using namespace std;

double currentBalance = ATM_INITIAL_BALANCE;

bool canWithdraw(double amount);
void withdraw(double amount);
void deposit(double amount);
void displayBalance();
void displayMenu();
void showProcessing();
int getChoice();
int getPin();

int main() {
    system("cls");
    int pin;
    bool isValid = false;
    int attempts = 0;
    while (!isValid && attempts < 3) {
        pin = getPin();
        isValid = pin == ATM_PIN;
        if (!isValid) {
            attempts++;
            cout << "Invalid PIN. Attempts Remaining: " << 3 - attempts << endl;
        }
    }
    if (!isValid) {
        cout << "Too many incorrect attempts. Exiting..." << endl;
        this_thread::sleep_for(chrono::seconds(3));
        system("cls");
        return 0;
    }
    cout << "Successfully logged in." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Welcome to the ATM!" << endl;
    while (true) {    
        system("cls");
        displayMenu();
        int choice;
        isValid = false;
        while (!isValid) {
            choice = getChoice();
            isValid = choice >= 1 && choice <= 4;
            if (!isValid) {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        switch (choice) {
            case 1:
                double withdrawAmount;
                cout << "Enter the amount you want to withdraw: ";
                cin >> withdrawAmount;
                isValid = false;
                attempts = 0;
                while (!isValid && attempts < 3) {
                    pin = getPin();
                    isValid = pin == ATM_PIN;
                    if (!isValid) {
                        attempts++;
                        cout << "Invalid PIN. Attempts Remaining: " << 3 - attempts << endl;
                    }
                }
                if (canWithdraw(withdrawAmount)) {
                    withdraw(withdrawAmount);
                    showProcessing();
                    cout << "Withdrawal successful." << endl;
                    displayBalance();
                } else {
                    cout << "Withdrawal failed." << endl;
                    cout << "Insufficient balance." << endl;
                }
                system("pause>0");
                break;
            case 2:
                double depositAmount;
                cout << "Enter the amount you want to deposit: ";
                cin >> depositAmount;
                isValid = false;
                attempts = 0;
                while (!isValid && attempts < 3) {
                    pin = getPin();
                    isValid = pin == ATM_PIN;
                    if (!isValid) {
                        attempts++;
                        cout << "Invalid PIN. Attempts Remaining: " << 3 - attempts << endl;
                    }
                }
                deposit(depositAmount);
                showProcessing();
                cout << "Deposit successful." << endl;
                displayBalance();
                system("pause>0");
                break;
            case 3:
                showProcessing();
                displayBalance();
                system("pause>0");
                break;
            case 4:
                cout << "Exiting..." << endl;
                this_thread::sleep_for(chrono::seconds(3));
                system("cls");
                return 0;
        }
    }
}

void displayMenu() {
    cout << "Please select an option:" << endl;
    cout << "\t1. Withdraw" << endl;
    cout << "\t2. Deposit" << endl;
    cout << "\t3. Display Balance" << endl;
    cout << "\t4. Exit" << endl;
}

int getChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int getPin() {
    int pin;
    cout << "Enter your PIN: ";
    cin >> pin;
    return pin;
}

bool canWithdraw(double amount) {
    return amount <= currentBalance;
}

void withdraw(double amount) {
    currentBalance -= amount;
}

void deposit(double amount) {
    currentBalance += amount;
}

void displayBalance() {
    cout << "Your current balance is: " << currentBalance << endl;
}

void showProcessing() {
    cout << "Processing... <";
    for (int i = 0; i < 10; i++) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "#";
    }
    cout << ">";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "\r";
    int _ = 50;
    for (int i = 0; i < _; i++) {
        cout << " ";
    }
    cout << "\r";
}