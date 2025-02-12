// This is a comment
// This is a simple program that prints "Hello World!" to the console

// The include directive is used to include libraries in the program
// iostream is a library that is used for input and output operations
#include <iostream>

// This line is used to use everything in the std library without having to refernce it everytime
// This is not recommended in larger projects
using namespace std;

// This is the main function of the program
// This is where the program starts
int main() {
	// cout stands for console output and is used to print to console
	// << is the insertion operator and is used to insert data into the stream
	// endl is used to end the line it is similar to \n
	// All strings need to be in double quotes
	cout << "Hello World!" << endl;

	// System function will call a system command to be executed in the terminal
	// This is used to pause the terminal so the user can see the output
	// This is not recommended in larger projects as it is not portable
	// pause > 0 is used to pause the terminal and wait for a key press and divert the result from the pause command into a file called 0
	system("pause>0");

	// This is used to clear the terminal screen
	// This is not recommended in larger projects as it is not portable
    system("cls");

	// This is the return statement of the main function
	// 0 denotes that the program ran successfully
	return 0;
}