// FileManager.h

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Student.h"
#include <vector>
#include <string>

using namespace std;

class FileManager {
private:
    string filename;

public:
    // Constructor to set the filename
    FileManager(string fname);

    // Add a new student record to the file
    void addStudent(const Student& s);

    // View all student records from the file
    void viewAllStudents();

    // Search and display a student by roll number
    bool searchStudent(int roll);

    // Update student details by roll number
    void updateStudent(int roll);

    // Delete a student record by roll number
    void deleteStudent(int roll);

    // Flag and display students with marks below passing threshold (e.g., <40)
    void flagPerformance();

private:
    // Utility: Load all students from file into a vector
    vector<Student> loadAllStudents();

    // Utility: Save all students from vector back to file (used in update/delete)
    void saveAllStudents(const vector<Student>& students);
};

#endif // FILEMANAGER_H
