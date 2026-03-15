#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

int ids[MAX_STUDENTS];
string names[MAX_STUDENTS];
float marks[MAX_STUDENTS];
char grades[MAX_STUDENTS];

int studentCount = 0;

// Calculate grade
char calculateGrade(float mark) {
    if (mark >= 90) return 'A';
    else if (mark >= 75) return 'B';
    else if (mark >= 60) return 'C';
    else if (mark >= 50) return 'D';
    else return 'F';
}

// Add student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student limit reached!\n";
        return;
    }

    cout << "Enter Student ID: ";
    cin >> ids[studentCount];
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, names[studentCount]);

    while (true){
        cout << "Enter Marks (Out of 100): ";
        cin >> marks[studentCount];
        if (marks[studentCount] >100){
            cout << "Invalid Marks,\nPlease enter within the specified range [0-100]" << endl;
        } else {
            break;
        }
    }
    grades[studentCount] = calculateGrade(marks[studentCount]);
    studentCount++;

    cout << "Student added successfully!\n";
}

// Display students in tabular format
void viewStudents() {
    if (studentCount == 0) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    cout << left << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(8) << "Grade" << endl;
    cout << string(44, '-') << endl;

    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(6) << ids[i]
             << setw(20) << names[i]
             << setw(10) << marks[i]
             << setw(8) << grades[i] << endl;
    }
}

// Update student
void updateStudent() {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (ids[i] == id) {
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, names[i]);
            cout << "Enter New Marks: ";
            cin >> marks[i];
            grades[i] = calculateGrade(marks[i]);
            cout << "Record updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Delete student
void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (ids[i] == id) {
            for (int j = i; j < studentCount - 1; j++) {
                ids[j] = ids[j + 1];
                names[j] = names[j + 1];
                marks[j] = marks[j + 1];
                grades[j] = grades[j + 1];
            }
            studentCount--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Show report card
void showReportCard() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (ids[i] == id) {
            cout << "\n--- Report Card ---\n";
            cout << left << setw(15) << "ID:" << ids[i] << endl;
            cout << left << setw(15) << "Name:" << names[i] << endl;
            cout << left << setw(15) << "Marks:" << marks[i] << endl;
            cout << left << setw(15) << "Grade:" << grades[i] << endl;

            cout << left << setw(15) << "Performance:";
            if (grades[i] == 'A') cout << "Excellent\n";
            else if (grades[i] == 'B') cout << "Very Good\n";
            else if (grades[i] == 'C') cout << "Good\n";
            else if (grades[i] == 'D') cout << "Average\n";
            else cout << "Fail\n";

            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n=== Student Grade Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Show Report Card\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: showReportCard(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}