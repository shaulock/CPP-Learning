#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <c++ file name without extension>" << endl;
        return 1;
    } else {
        string fileName = argv[1];
        string command = "g++ -o " + fileName + ".exe " + fileName + ".cpp" ;
        string runCommand = ".\\" + fileName + ".exe";
        system(command.c_str());
        system(runCommand.c_str());
        return 0;
    }
}