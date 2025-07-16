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
  
    Student();
    Student(int r, string n, string s, float m);


    void inputDetails();


    void calculateGrade();


    void display() const;

  
    int getRollNumber() const;
    string getName() const;
    string getSubject() const;
    float getMarks() const;
    char getGrade() const;


    void setName(string n);
    void setSubject(string s);
    void setMarks(float m);

   
    string toString() const;     
    void fromString(string data);    
};

#endif 
