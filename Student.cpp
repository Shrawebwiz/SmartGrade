// Student.cpp

#include "Student.h"
#include <sstream>   // for stringstream

// Default Constructor
Student::Student() {
    rollNumber = 0;
    name = "";
    subject = "";
    marks = 0.0;
    grade = 'F';
}

// Parameterized Constructor
Student::Student(int r, string n, string s, float m) {
    rollNumber = r;
    name = n;
    subject = s;
    marks = m;
    calculateGrade();
}

// Take user input
void Student::inputDetails() {
    cout << "\nEnter Roll Number: ";
    cin >> rollNumber;
    cin.ignore(); // clear input buffer

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Subject: ";
    getline(cin, subject);

    cout << "Enter Marks: ";
    cin >> marks;

    calculateGrade();
}

// Calculate grade based on marks
void Student::calculateGrade() {
    if (marks >= 90)
        grade = 'A';
    else if (marks >= 80)
        grade = 'B';
    else if (marks >= 70)
        grade = 'C';
    else if (marks >= 60)
        grade = 'D';
    else if (marks >= 40)
        grade = 'E';
    else
        grade = 'F';
}

// Display student details
void Student::display() const {
    cout << "\n------------------------------------";
    cout << "\nRoll Number: " << rollNumber;
    cout << "\nName: " << name;
    cout << "\nSubject: " << subject;
    cout << "\nMarks: " << marks;
    cout << "\nGrade: " << grade;
    cout << "\n------------------------------------\n";
}

// Getters
int Student::getRollNumber() const {
    return rollNumber;
}

string Student::getName() const {
    return name;
}

string Student::getSubject() const {
    return subject;
}

float Student::getMarks() const {
    return marks;
}

char Student::getGrade() const {
    return grade;
}

// Setters
void Student::setName(string n) {
    name = n;
}

void Student::setSubject(string s) {
    subject = s;
}

void Student::setMarks(float m) {
    marks = m;
    calculateGrade();  // update grade when marks change
}

// Serialize data for file saving
string Student::toString() const {
    stringstream ss;
    ss << rollNumber << "," << name << "," << subject << "," << marks << "," << grade;
    return ss.str();
}

// Deserialize data from file string
void Student::fromString(string data) {
    stringstream ss(data);
    string token;

    getline(ss, token, ',');
    rollNumber = stoi(token);

    getline(ss, name, ',');

    getline(ss, subject, ',');

    getline(ss, token, ',');
    marks = stof(token);

    getline(ss, token, ',');
    grade = token[0];
}
