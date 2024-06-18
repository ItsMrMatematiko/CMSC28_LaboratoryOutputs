// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 29 May 2024

// This '.h' (header) file defines the Student class.
// This class is a child class of Person — therefore inheriting all Person's attributes and member methods.

#include <iostream>
#include "Person.h" // Included to call the class Person in this file.

using namespace std;

// This class block provides the class definition of Person.
// ': public Person' allows the inheritance of class Student from class Person
class Student: public Person{
    private: // Attribute set Private in compliance with the given instructions
        string StudentNumber;
    
    public: // Attribute set Public in compliance with the given instructions
        string Course;
        string Department;
        string College;

        // Constructor for class Student with no parameters
        // ': Person' allows the constructor to inherit the constructor with no parameter
        // as defined in class Person.
        Student() : Person(){}

        // Constructor for class Student with parameters
        // ': Person (*person attributes*)' allows this constructor to create an instance of a
        // Student that inherits from Person (the parent class). It makes sure that the parent class
        // is initialized together with the specific attributes for this class.
        Student(string firstName, string lastName, string gender, string emailAddress, string cpNumber,
                string studentNumber, string course, string department, string college): 
            Person(firstName, lastName, gender, emailAddress, cpNumber){
                StudentNumber = studentNumber;
                Course = course;
                Department = department;
                College = college;
        }

        // Unique Setter Member Methods for this class
        void setStudentNumber(string studentNumber){ StudentNumber = studentNumber; }
        void setCourse(string course){ Course = course; }
        void setDepartment(string department){ Department = department; }
        void setCollege(string college){ College = college; }

        // Unique Getter Member Methods for this class
        string getStudentNumber(){ return StudentNumber; }
        string getCourse(){ return Course; }
        string getDepartment(){ return Department; }
        string getCollege(){ return College; }
};