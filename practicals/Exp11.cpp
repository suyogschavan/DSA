#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
    string rollNumber;
    string name;
    string division;
    string address;
};

void createFile() {
    ofstream file("student_info.txt");
    file << "Roll Number,Name,Division,Address\n";
    file.close();
}

void addStudent() {
    string rollNumber, name, division, address;

    cout << "Enter Roll Number: ";
    getline(cin, rollNumber);

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Division: ";
    getline(cin, division);

    cout << "Enter Address: ";
    getline(cin, address);

    Student student;
    student.rollNumber = rollNumber;
    student.name = name;
    student.division = division;
    student.address = address;

    ofstream file("student_info.txt", ios::app);
    file << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
    file.close();
}

void deleteStudent() {
    string rollNumber;
    cout << "Enter Roll Number of the student to delete: ";
    getline(cin, rollNumber);

    ifstream inputFile("student_info.txt");
    ofstream outputFile("temp.txt");

    string line;
    getline(inputFile, line);
    outputFile << line << endl;  // Write the header line

    bool deleted = false;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string roll;
        getline(iss, roll, ',');

        if (roll == rollNumber) {
            deleted = true;
            continue;
        }

        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    remove("student_info.txt");
    rename("temp.txt", "student_info.txt");

    if (deleted) {
        cout << "Student record deleted successfully." << endl;
    } else {
        cout << "Student record not found." << endl;
    }
}

void displayStudent() {
    string rollNumber;
    cout << "Enter Roll Number of the student to display: ";
    getline(cin, rollNumber);

    ifstream file("student_info.txt");
    string line;

    getline(file, line);  // Skip the header line

    while (getline(file, line)) {
        istringstream iss(line);
        string roll;
        getline(iss, roll, ',');

        if (roll == rollNumber) {
            cout << "Student Details:" << endl;
            cout << line << endl;
            file.close();
            return;
        }
    }

    cout << "Student record not found." << endl;
    file.close();
}

int main() {
    int choice;

    while (true) {
        cout << "\n***** Student Information System *****" << endl;
        cout << "1. Create File" << endl;
        cout << "2. Add Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                createFile();
                cout << "File created successfully." << endl;
                break;
            case 2:
                addStudent();
                cout << "Student added successfully." << endl;
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                displayStudent();
                break;
            case 5:
                cout << "Exiting program." <<endl;
                return 0;
            default:
            cout << "Invalid choice. Please try again." << endl;
}
}
}