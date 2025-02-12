#include <iostream>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

bool hasDecimal(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            return true;
        }
    }
    return false;
}

bool hasDecimal(double num) {
    return num != (int)num;
}

bool isValidInput(string str) {
    if (str.length() == 0) {
        return false;
    }
    if (str[0] == '-') {
        str = str.substr(1);
        if (str.length() == 0) {
            return false;
        } else if (str.length() == 1 && !isdigit(str[0])) {
            return false;
        }
    }
    int countOfDecimal = 0;
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]) && str[i] != '.') {
            return false;
        }
        if (str[i] == '.') {
            countOfDecimal++;
        }
    }
    if (countOfDecimal > 1) {
        return false;
    }
    return true;
}

int convertToInt(char c) {
    return c - '0';
}

long long int power(int base, int exponent) {
    long long int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double convertStringToDouble(string str) {
    bool decimalDetected = false;
    short int numberOfDecimalPlaces = 0;
    long long int decimalPart = 0;
    long long int wholePart = 0;
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            decimalDetected = true;
            count = 0;
        } else {
            if (decimalDetected) {
                numberOfDecimalPlaces++;
                decimalPart = decimalPart*10 +  convertToInt(str[i]);
            } else {
                wholePart = wholePart*10 + convertToInt(str[i]);
                count++;
            }
        }
    }
    return (double)wholePart + ((double)decimalPart / power(10, numberOfDecimalPlaces));
}

double getDoubleInput(string inputPrompt) {
    string input;
    double number;
    bool isValid = false;
    while (!isValid) {
        cout << inputPrompt;
        cin >> input;
        if (isValidInput(input)) {
            number = convertStringToDouble(input);
            isValid = true;
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return number;
}

char getOperatorInput(string inputPrompt) {
    string input;
    char op;
    bool isValid = false;
    while (!isValid) {
        cout << inputPrompt;
        cin >> input;
        if (input.length() == 1 && (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')) {
            op = input[0];
            isValid = true;
        } else {
            cout << "Invalid input. Please enter a valid operator." << endl;
        }
    }
    return op;
}

bool getContinueInput(string inputPrompt) {
    string input;
    bool isValid = false;
    while (!isValid) {
        cout << inputPrompt;
        cin >> input;
        if (input.length() == 1 && (input[0] == 'y' || input[0] == 'n')) {
            isValid = true;
        } else {
            cout << "Invalid input. Please enter y or n." << endl;
        }
    }
    return input[0] == 'y';
}

int main() {
    double num1, num2;
    char op;
    bool continueCalculation = true;
    while (continueCalculation) {
        num1 = getDoubleInput("Enter the first number: ");
        num2 = getDoubleInput("Enter the second number: ");
        op = getOperatorInput("Enter the operator (+, -, *, /): ");
        double result;
        switch (op) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
        }
        if (hasDecimal(result)) {
            cout << "The result is: " << result << endl;
        } else {
            cout << "The result is: " << (int)result << endl;
        }
        continueCalculation = getContinueInput("Do you want to perform another calculation? (y/n): ");
    }

    system("cls");

    return 0;
}