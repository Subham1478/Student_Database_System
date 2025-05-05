#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

void addStudent(vector<Student> &students) {
    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNo;
    cout << "Enter Name: ";
    cin.ignore(); // to ignore leftover newline character from previous input
    getline(cin, newStudent.name);
    cout << "Enter Marks: ";
    cin >> newStudent.marks;
    students.push_back(newStudent);
    cout << "Student Added Successfully!\n";
}

void displayStudents(const vector<Student> &students) {
    cout << "\nStudent Records:\n";
    for (const auto &student : students) {
        cout << "Roll Number: " << student.rollNo << ", Name: " << student.name << ", Marks: " << student.marks << endl;
    }
}

void updateStudent(vector<Student> &students) {
    int rollNo;
    cout << "Enter Roll Number to Update: ";
    cin >> rollNo;
    bool found = false;

    for (auto &student : students) {
        if (student.rollNo == rollNo) {
            cout << "Enter New Name: ";
            cin.ignore(); // to ignore leftover newline character
            getline(cin, student.name);
            cout << "Enter New Marks: ";
            cin >> student.marks;
            cout << "Student Updated Successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << rollNo << " not found.\n";
    }
}

void deleteStudent(vector<Student> &students) {
    int rollNo;
    cout << "Enter Roll Number to Delete: ";
    cin >> rollNo;
    bool found = false;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNo == rollNo) {
            students.erase(it);
            cout << "Student Deleted Successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << rollNo << " not found.\n";
    }
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\nStudent Database Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                deleteStudent(students);
                break;
            case 5:
                cout << "Exiting Program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
