#include <iostream>

using namespace std;

bool isValidateTriangle(double a, double b, double c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    double a, b, c;
    cout << "Enter the length of side a: ";
    cin >> a;
    cout << "Enter the length of side b: ";
    cin >> b;
    cout << "Enter the length of side c: ";
    cin >> c;

    if (isValidateTriangle(a, b, c)) {
        if (a == b && b == c) {
            cout << "The sides form an equilateral triangle." << endl;
        } else if (a == b || b == c || a == c) {
            cout << "The sides form an isosceles triangle." << endl;
        } else {
            cout << "The sides form a scalene triangle." << endl;
        }
    } else {
        cout << "The sides do not form a valid triangle." << endl;
    }

    system("pause>0");
    system("cls");

    return 0;
}