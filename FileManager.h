

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
  
    FileManager(string fname);


    void addStudent(const Student& s);


    void viewAllStudents();

 
    bool searchStudent(int roll);

    void updateStudent(int roll);


    void deleteStudent(int roll);


    void flagPerformance();

private:

    vector<Student> loadAllStudents();

    void saveAllStudents(const vector<Student>& students);
};

#endif
