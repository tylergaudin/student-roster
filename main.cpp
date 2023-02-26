#include <iostream>
#include <string>
#include <vector>
#include "degree.h"
#include "student.h"
#include "roster.h"

int main()
{
    //Personal info added to array
    const std::string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tyler,Gaudin,tgaudi1@wgu.edu,29,7,3,5,SOFTWARE"
    };
    
    //Print Class and Title Information
    std::cout << "C867-Scripting & Programming: Applications\nLanguage: C++\nStudent ID: 010760147\nName: Tyler Gaudin\n\n";
    
    //Instantiate classRoster
    Roster classRoster;
    
    //Add Students to classRoster
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }
    
    //Print Students
    classRoster.printAll();
    
    //Print Invalid Emails
    classRoster.printInvalidEmails();
    
    //Print Average DaysInCourse
    classRoster.printAverageDaysInCourse("A1");
    classRoster.printAverageDaysInCourse("A2");
    classRoster.printAverageDaysInCourse("A3");
    classRoster.printAverageDaysInCourse("A4");
    classRoster.printAverageDaysInCourse("A5");
    
    std::cout << std::endl;
    
    //Print Students by Degree
    classRoster.printByDegreeProgram(SOFTWARE);
    
    //Remove Student A3
    classRoster.remove("A3");
    
    //Print Remaining Students
    classRoster.printAll();
    
    //2nd attempt delete student and display fail message
    classRoster.remove("A3");
    
    //destructor is called upon exit from main
};
