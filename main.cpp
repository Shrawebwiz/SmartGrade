// main.cpp

#include "FileManager.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << "\n========== 📚 SmartGrade: Student Performance Tracker ==========\n";
    cout << "1️⃣  Add Student\n";
    cout << "2️⃣  View All Students\n";
    cout << "3️⃣  Search Student by Roll Number\n";
    cout << "4️⃣  Update Student by Roll Number\n";
    cout << "5️⃣  Delete Student by Roll Number\n";
    cout << "6️⃣  Flag Students Below Passing Marks\n";
    cout << "0️⃣  Exit\n";
    cout << "===============================================================\n";
    cout << "Enter your choice: ";
}

int main() {
    FileManager fm("records.txt");
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                Student s;
                s.inputDetails();
                fm.addStudent(s);
                break;
            }
            case 2: {
                fm.viewAllStudents();
                break;
            }
            case 3: {
                int roll;
                cout << "Enter Roll Number to Search: ";
                cin >> roll;
                fm.searchStudent(roll);
                break;
            }
            case 4: {
                int roll;
                cout << "Enter Roll Number to Update: ";
                cin >> roll;
                fm.updateStudent(roll);
                break;
            }
            case 5: {
                int roll;
                cout << "Enter Roll Number to Delete: ";
                cin >> roll;
                fm.deleteStudent(roll);
                break;
            }
            case 6: {
                fm.flagPerformance();
                break;
            }
            case 0: {
                cout << "\n👋 Exiting SmartGrade. Have a productive day!\n";
                return 0;
            }
            default:
                cout << "\n⚠️ Invalid choice. Please enter a valid option.\n";
        }
    }
}
