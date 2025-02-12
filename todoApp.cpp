#include <iostream>
#include <fstream>
#include <list>

#define FILE_NAME "todo.csv"


using namespace std;

string makeCSVString(string taskName, string taskDescription, string taskPriority, string taskStatus) {
    return taskName + "," + taskDescription + "," + taskPriority + "," + taskStatus;
}

string convertCSVRowToUserFriendLyString(string csvRow, list<string> HEADERS) {
    string userFriendlyString = "";
    int i = 0;
    for (auto it = HEADERS.begin(); it != HEADERS.end() && i < csvRow.length(); i++) {
        if (i == 0) {
            userFriendlyString = *it + ": " + csvRow[i];
        } else {
            if (csvRow[i] == ',') {
                it++;
                userFriendlyString = userFriendlyString + "\n" + *it + ": ";
            } else {
                userFriendlyString += csvRow[i];
            }
        }
    }
    return userFriendlyString;
}

bool fileExists() {
    ifstream file(FILE_NAME);
    return file.good();
}

bool createFile() {
    ofstream file(FILE_NAME);
    file << "Task Name,Task Description,Task Priority,Task Status" << endl;
    return file.good();
}

void displayMenu() {
    cout << "Please select an option:" << endl;
    cout << "\t1. Add a new task" << endl;
    cout << "\t2. Display all tasks" << endl;
    cout << "\t3. Exit" << endl;
}

int getChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

bool addTask(string task) {
    ofstream file(FILE_NAME, ios::app);
    if (!file.is_open()) {
        return false;
    }
    file << task << endl;
    file.close();
    return true;
}

bool displayTasks(list<string> HEADERS) {
    ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return false;
    }
    string line;
    getline(file, line);
    while (getline(file, line)) {
        cout << convertCSVRowToUserFriendLyString(line, HEADERS) << endl;
    }
    file.close();
    return true;
}

int getLength() {
    ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return -1;
    }
    string line;
    int length = 0;
    while (getline(file, line)) {
        length++;
    }
    cout << "Length " << length << endl;
    file.close();
    return length;
}

int main() {
    list<string> HEADERS = {"Task Name", "Task Description", "Task Priority", "Task Status"};
    int length = getLength();
    if (length == -1) {
        if (!createFile()) {
            cout << "Error creating file." << endl;
            return 1;
        }
    }
    while (true) {
        displayMenu();
        int choice = getChoice();
        string taskName = "", taskDescription = "", taskPriority = "", taskStatus = "";
        switch (choice) {
            case 1:
                cout << "Enter the task name: ";
                cin >> taskName;
                cout << "Enter the task description: ";
                cin >> taskDescription;
                cout << "Enter the task priority: ";
                cin >> taskPriority;
                cout << "Enter the task status: ";
                cin >> taskStatus;
                if (addTask(makeCSVString(taskName, taskDescription, taskPriority, taskStatus))) {
                    cout << "Task added successfully." << endl;
                } else {
                    cout << "Error adding task." << endl;
                }
                break;
            case 2:
                if (!displayTasks(HEADERS)) {
                    cout << "Error displaying tasks." << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
        }
    }
    return 0;
}
