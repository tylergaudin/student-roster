#include <iostream>
#include <string>
#include "roster.h"

//Constructor
Roster::Roster(){};

//Destructor
Roster::~Roster()
{
    for (int i = 0; i < SIZE; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
};

//Add Function
void Roster::add(std::string studentID, std::string firstName, std::string lastName,
std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
int daysInCourse3, DegreeProgram degreeprogram)
{
    classRosterArray[++start] = new Student(studentID, firstName, lastName,
    emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

//Remove Function
void Roster::remove(std::string studentID)
{
    bool found = false;
    
    for (int i = 0; i < Roster::start; i++)
    {
        if (classRosterArray[i]->get_studentID() == studentID)
        {
            found = true;
            Student* hold = classRosterArray[i];
            classRosterArray[i] = classRosterArray[SIZE - 1];
            classRosterArray[SIZE - 1] = hold;
            Roster::start--;
            hold = classRosterArray[i];
            classRosterArray[i] = classRosterArray[i + 1];
            classRosterArray[i + 1] = hold;
        }
    }
    if (found)
    {
        std::cout << "Removing " << studentID << ":" << std::endl << std::endl;
    }
    else
    {
        std::cout << "Removing " << studentID << " again\n\nThe student with the ID: " << studentID << " was not found." << std::endl;
    }
}

//Print All Function
void Roster::printAll()
{
    std::cout << "Displaying all students:" << std::endl;
    for (int i = 0; i <= Roster::start; i++) {
        Roster::classRosterArray[i]->print();
    }
    std::cout << std::endl;
};

//Print Average Days in Course Function
void Roster::printAverageDaysInCourse(std::string studentID)
{
    for (int i = 0; i <= Roster::start; i++)
    {
        if (classRosterArray[i]->Student::get_studentID() == studentID)
        {
            std::cout << "Student ID: " << studentID << ", average days in course is: ";
            classRosterArray[i]->avg();
            std::cout << std::endl;
        }
    }
}

//Parsing function
void Roster::parse(std::string text)
{
    size_t rhs = text.find(",");
    std::string student_id = text.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = text.find("," , lhs);
    std::string first_name = text.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = text.find("," , lhs);
    std::string last_name = text.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = text.find("," , lhs);
    std::string email = text.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = text.find("," , lhs);
    int age = stoi(text.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = text.find("," , lhs);
    int days_completed_1 = stoi(text.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = text.find("," , lhs);
    int days_completed_2 = stoi(text.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = text.find("," , lhs);
    int days_completed_3 = stoi(text.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = text.find("," , lhs);
    std::string strDegree = text.substr(lhs, rhs - lhs);
    
    DegreeProgram Degree = DegreeProgram::SOFTWARE;
    if (strDegree == "SECURITY")
    {
        Degree = DegreeProgram::SECURITY;
    }
    else if (strDegree == "NETWORK")
    {
        Degree = DegreeProgram::NETWORK;
    }
    add(student_id, first_name, last_name, email, age, days_completed_1, days_completed_2, days_completed_3, Degree);
};

//Print Invalid Emails Function
void Roster::printInvalidEmails()
{
    std::cout << "Displaying invalid emails:" << std::endl << std::endl;
    
    for (int i = 0; i <= Roster::start; i++)
        if (classRosterArray[i]->verifyEmail(classRosterArray[i]->get_emailAddress()) == false)
        {
            std::cout << Roster::classRosterArray[i]->get_emailAddress() << " - is invalid." << std::endl;
        }
        else
        {
            continue;
        }
    std::cout << std::endl;
};

//Print By Degree Function
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    int n = -1;
    
    if (degreeProgram == 0)
    {
        n = 0;
    }
    else if (degreeProgram == 1)
    {
        n = 1;
    }
    else if (degreeProgram == 2)
    {
        n = 2;
    }
    else
    {
        std::cout << "Invalid degree, try again.";
    }
    
    std::cout << "Showing students in degree program: " << degreeString[n] << std::endl << std::endl;
    
    for (int i = 0; i <= Roster::start; i++)
    {
        if (classRosterArray[i]->get_degreeprogram() == degreeProgram)
        {
            Roster::classRosterArray[i]->print();
        }
        else
        {
            continue;
        }
    }
    std::cout << std::endl;
}
