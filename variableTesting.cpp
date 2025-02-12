#include <iostream>

using namespace std;

int main() {
    int yearOfBirth = 2004;
    char gender = 'm';
    bool isOlderThan18 = (2025 - yearOfBirth) > 18;
    float averageGrade = 4.5;
    double balance = 456789.123456;

    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Min int value: " << INT_MIN << endl;
    cout << "Size of short int: " << sizeof(short int) << " bytes" << endl;
    cout << "Size of long int: " << sizeof(long int) << " bytes" << endl;
    cout << "Size of long long int: " << sizeof(long long int) << " bytes" << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "Max int value: " << INT_MAX << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;

    system("pause>0");
    system("cls");

    return 0;
}