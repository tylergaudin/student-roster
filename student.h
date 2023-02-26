#ifndef student_h
#define student_h
#include <iostream>
#include <string>
#include <regex>
#include "degree.h"

class Student
{
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeprogram;
    
    
public:
    //Constructor
    Student(std::string studentID, std::string firstName,std::string lastName,
            std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
            int daysInCourse3, DegreeProgram degreeprogram);
    //Destructor
    ~Student();
    
    //Getters
    std::string get_studentID();
    std::string get_firstName();
    std::string get_lastName();
    std::string get_emailAddress();
    int get_age();
    int get_daysInCourse1();
    int get_daysInCourse2();
    int get_daysInCourse3();
    DegreeProgram get_degreeprogram();
    
    //setters
    void set_studentID(std::string studentID);
    void set_firstName(std::string firstName);
    void set_lastName(std::string lastName);
    void set_emailAddress(std::string emailAddress);
    void set_age(int age);
    void set_daysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void set_degreeprogram(DegreeProgram degreeprogram);
    
    //print function
    void print();
    
    //local function to output average daysInCourse
    void avg();
    
    //local function to verify email
    bool verifyEmail(std::string email);
};

#endif

