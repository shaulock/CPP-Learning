#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isValidMonth(int month) {
    return month >= 1 && month <= 12;
}

bool isValidYear(int year) {
    return year > 0;
}

bool isValidChoice(char choice) {
    return (choice == 'y' || choice == 'n');
}

int main() {
    char choice = 'n';
    int year, month;
    while(true) {   
        cin.clear();
        while(true) {
            cin.clear();
            cout << "Enter the year: ";
            cin >> year;
            if (isValidYear(year)) {
                break;
            } else {
                cout << "Invalid year." << endl;
                cin.clear();
                while(cin.get() != '\n');
                continue;
            }
        }
        
        while(true) {
            cin.clear();
            cout << "Enter the month (1-12): ";
            cin >> month;
            if (isValidMonth(month)) {
                break;
            } else {
                cout << "Invalid month." << endl;
                cin.clear();
                while(cin.get() != '\n');
                continue;
            }
        }

        switch(month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                cout << "There are 31 days in this month." << endl;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                cout << "There are 30 days in this month." << endl;
                break;
            case 2:
                if (isLeapYear(year)) {
                    cout << "There are 29 days in this month." << endl;
                } else {
                    cout << "There are 28 days in this month." << endl;
                }
                break;
        }
        while (true) {
            cin.clear();
            cout << "Do you want to continue? (y/n): ";
            cin >> choice;
            if (isValidChoice(choice)) {
                break;
            } else {
                cout << "Invalid choice." << endl;
                cin.clear();
                while(cin.get() != '\n');
                continue;
            }
        }
        if (choice == 'n') {
            break;
        }
        cin.clear();
        while(cin.get() != '\n');
    }
    cout << "Goodbye!" << endl;
    system("cls");
    return 0;
}