#include "student.h"
#include <iostream>
#include <string>

//Constructor
Student::Student(std::string studentID, std::string firstName,
std::string lastName,std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
    int daysInCourse3, DegreeProgram degreeprogram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
    this->degreeprogram = degreeprogram;
}
    
//Destructor
Student::~Student(){};

//Getters
std::string Student::get_studentID() {return studentID;}
std::string Student::get_firstName() {return firstName;}
std::string Student::get_lastName() {return lastName;}
std::string Student::get_emailAddress() {return emailAddress;}
int Student::get_age() {return age;}
int Student::get_daysInCourse1() {return daysInCourse[0];}
int Student::get_daysInCourse2() {return daysInCourse[1];}
int Student::get_daysInCourse3() {return daysInCourse[2];}
DegreeProgram Student::get_degreeprogram() {return degreeprogram;}

//Setters
void Student::set_studentID(std::string studentID) {this->studentID = studentID;}
void Student::set_firstName(std::string firstName) {this->firstName = firstName;}
void Student::set_lastName(std::string lastName) {this->lastName = lastName;}
void Student::set_emailAddress(std::string emailAddress) {this->emailAddress = emailAddress;}
void Student::set_age(int age) {this->age = age;}
void Student::set_daysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}
void Student::set_degreeprogram(DegreeProgram degreeprogram) {this->degreeprogram = degreeprogram;}
    
//print function
void Student::print()
{
    std::cout << get_studentID() << "\t";
    std::cout << get_firstName() << "\t";
    std::cout << get_lastName() << "\t";
    std::cout << get_age() << "\t";
    std::cout << "{" << get_daysInCourse1() << "," << get_daysInCourse2() << "," << get_daysInCourse3() << "}\t";
    std::cout << degreeString[(int)get_degreeprogram()] << std::endl;
}

//Local function to output average daysInCourse
void Student::avg()
{
    int average = (get_daysInCourse1() + get_daysInCourse2() + get_daysInCourse3()) / 3;
    std::cout << average;
}
    
//local function to verify email
bool Student::verifyEmail(std::string email)
{
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}
