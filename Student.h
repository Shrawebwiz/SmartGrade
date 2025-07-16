// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    string subject;
    float marks;
    char grade;

public:
    // Constructors
    Student();
    Student(int r, string n, string s, float m);

    // Input student details from user
    void inputDetails();

    // Calculate grade based on marks
    void calculateGrade();

    // Display student details in a formatted way
    void display() const;

    // Getters
    int getRollNumber() const;
    string getName() const;
    string getSubject() const;
    float getMarks() const;
    char getGrade() const;

    // Setters
    void setName(string n);
    void setSubject(string s);
    void setMarks(float m);

    // Serialize and Deserialize methods for file handling
    string toString() const;         // Converts student data to string for writing to file
    void fromString(string data);    // Loads student data from string read from file
};

#endif // STUDENT_H
