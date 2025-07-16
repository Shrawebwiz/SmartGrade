// FileManager.cpp

#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Constructor
FileManager::FileManager(string fname) {
    filename = fname;
}

// Add a new student record to the file
void FileManager::addStudent(const Student& s) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << s.toString() << endl;
        file.close();
        cout << "\n✅ Student record added successfully.\n";
    } else {
        cout << "\n❌ Error: Could not open file for writing.\n";
    }
}

// View all student records from the file
void FileManager::viewAllStudents() {
    vector<Student> students = loadAllStudents();

    if (students.empty()) {
        cout << "\n⚠️ No records found.\n";
        return;
    }

    cout << "\n📄 All Student Records:\n";
    for (const auto& s : students) {
        s.display();
    }
}

// Search and display a student by roll number
bool FileManager::searchStudent(int roll) {
    vector<Student> students = loadAllStudents();
    for (const auto& s : students) {
        if (s.getRollNumber() == roll) {
            cout << "\n✅ Student Found:\n";
            s.display();
            return true;
        }
    }
    cout << "\n❌ Student with Roll Number " << roll << " not found.\n";
    return false;
}

// Update student details by roll number
void FileManager::updateStudent(int roll) {
    vector<Student> students = loadAllStudents();
    bool found = false;

    for (auto& s : students) {
        if (s.getRollNumber() == roll) {
            cout << "\n✅ Existing Record:\n";
            s.display();

            cout << "\nEnter new details:\n";
            s.inputDetails(); // allow user to re-enter details

            found = true;
            break;
        }
    }

    if (found) {
        saveAllStudents(students);
        cout << "\n✅ Record updated successfully.\n";
    } else {
        cout << "\n❌ Student with Roll Number " << roll << " not found.\n";
    }
}

// Delete a student record by roll number
void FileManager::deleteStudent(int roll) {
    vector<Student> students = loadAllStudents();
    bool found = false;

    auto it = students.begin();
    while (it != students.end()) {
        if (it->getRollNumber() == roll) {
            it = students.erase(it);
            found = true;
        } else {
            ++it;
        }
    }

    if (found) {
        saveAllStudents(students);
        cout << "\n✅ Record deleted successfully.\n";
    } else {
        cout << "\n❌ Student with Roll Number " << roll << " not found.\n";
    }
}

// Flag and display students below 40 marks
void FileManager::flagPerformance() {
    vector<Student> students = loadAllStudents();
    bool found = false;

    cout << "\n🚩 Students with Marks Below 40 (At Risk):\n";
    for (const auto& s : students) {
        if (s.getMarks() < 40) {
            s.display();
            found = true;
        }
    }

    if (!found) {
        cout << "\n✅ All students are above the passing threshold.\n";
    }
}

// Load all students from the file into a vector
vector<Student> FileManager::loadAllStudents() {
    vector<Student> students;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty()) {
                Student s;
                s.fromString(line);
                students.push_back(s);
            }
        }
        file.close();
    } else {
        cout << "\n⚠️ Note: File not found, a new file will be created upon adding records.\n";
    }

    return students;
}

// Save all students back to the file
void FileManager::saveAllStudents(const vector<Student>& students) {
    ofstream file(filename, ios::trunc); // overwrite the file
    if (file.is_open()) {
        for (const auto& s : students) {
            file << s.toString() << endl;
        }
        file.close();
    } else {
        cout << "\n❌ Error: Could not open file for saving records.\n";
    }
}
