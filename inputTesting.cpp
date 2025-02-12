#include <iostream>

using namespace std;

int main() {

    // declare a variable to store the user's annual salary
	float annualSalary;

    // prompt the user to enter their annual salary
	cout << "Enter your annual salary: ";
	
    // cin stands for console input and is used to get input from the console
    // >> is the extraction operator and is used to extract data from the stream
    // Everything user inputs after the >> will be stored until the user presses enter
    cin >> annualSalary;

    // calculate the monthly salary by dividing the annual salary by 12
	float monthlySalary = annualSalary / 12;

    // print the monthly salary to the console
	cout << "Your monthly salary is: " << monthlySalary << endl;

    // calculate the salary in 10 years by multiplying the annual salary by 10
    // and print it to the console
	cout << "In 10 years you will earn: " << annualSalary * 10 << endl;

	system("pause>0");
    system("cls");

    return 0;
}