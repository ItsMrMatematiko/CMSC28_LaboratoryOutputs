#include <iostream>
#include "Person.h"
#include "Grades.h"

using namespace std;

/* FUNCTION PROTOTYPES */
void displayProgramHeader();
void inputInformation(Person &person, Grades &grades);
void displayAllInformation(Person &person, Grades &grades);
void printProgramFooter();

int main(){
    Person firstPerson;
    Grades firstPersonGrade;

    displayProgramHeader();
    inputInformation(firstPerson, firstPersonGrade);
    displayAllInformation(firstPerson, firstPersonGrade);
    printProgramFooter();

    return 0;
}

void displayProgramHeader(){
    cout << endl;
    cout << "\t============================================================" << endl;
    cout << "\t|              CMSC 28 Programming Exercise 06             |" << endl;
    cout << "\t|            by Jann Dave Rhodore Gotas Casquejo           |" << endl;
    cout << "\t============================================================" << endl;
    cout << "\t| This programming exercise will demonstrate and practice  |" << endl;
    cout << "\t| connecting two header files in one '.cpp' file. Each     |" << endl;
    cout << "\t| header file has their own attributes and functions.      |" << endl;
    cout << "\t============================================================" << endl;
}

void inputInformation(Person &person, Grades &grades){
    int age, grade;
    string gender, subject;
    
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|              INPUT CORRESPONDING INFORMATION             |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    cout << "\t\tWhat is the Person's Age? ";
    cin >> age;

    cout << "\t\tWhat is the Person's Gender? ";
    cin >> gender;

    cout << "\t\tWhat Subject does this Person take? ";
    cin >> subject;

    cout << "\t\tWhat Grade did this Person get for the Subject? ";
    cin >> grade;

    person.setAge(age);
    person.setGender(gender);
    
    grades.setSubject(subject);
    grades.setGrade(grade);
}

void displayAllInformation(Person &person, Grades &grades){
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|              DISPLAY ALL ENCODED INFORMATION             |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    cout << "\t\tThis person is " << person.getAge() << " year(s) old." << endl;
    cout << "\t\tThis person is a " << person.getGender() << "." << endl << endl;
    cout << "\t\tThis person enrolled in a subject titled '" << grades.getSubject() << "'." << endl;
    grades.getGrade();
    cout << endl;
}

void printProgramFooter(){
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                 END OF PROGRAM EXECUTION                 |" << endl;
    cout << "\t------------------------------------------------------------" << endl;
}

