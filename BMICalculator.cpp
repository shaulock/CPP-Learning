#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double weight, height;
    cout << "Enter your weight in kilograms: ";
    cin >> weight;
    cout << "Enter your height in meters: ";
    cin >> height;

    double bmi = weight / (height * height);

    cout << "Your BMI is: " << bmi << endl;

    if (bmi < 18.6) {
        cout << "You are underweight." << endl;
        cout << "You need to gain " << (18.6*(height*height)) - weight << " kgs to become normal weight." << endl;
    } else if (bmi < 25) {
        cout << "You are normal weight." << endl;
    } else if (bmi < 30) {
        cout << "You are overweight." << endl;
        cout << "You need to lose " << weight - (25*(height*height)) << " kgs to become normal weight." << endl;
    } else {
        cout << "You are obese." << endl;
        cout << "You need to lose " << weight - (25*(height*height)) << " kgs to become normal weight." << endl;
    }

    system("pause>0");
    system("cls");

    return 0;
}