#ifndef roster_h
#define roster_h

#include "degree.h"
#include "student.h"


class Roster
{
private:
    int start = -1;
    const static int SIZE = 5;
    
    //Array of pointers
    Student* classRosterArray[SIZE] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    
public:
    //Constructor
    Roster();
    
    //Destructor
    ~Roster();
    
    //Getter
    Student** getStudent();
    
    //Add Function
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
    //Remove Function
    void remove(std::string studentID);
    
    //Print All Function
    void printAll();
    
    //Print Average Days in Course Function
    void printAverageDaysInCourse(std::string studentID);
    
    //Parsing function
    void parse(std::string text);
    
    //Print Invalid Emails Function
    void printInvalidEmails();
    
    //Print By Degree Function
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
#endif//
