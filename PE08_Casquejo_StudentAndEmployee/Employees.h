// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 29 May 2024

// This '.h' (header) file defines the Employees class.
// This class is a child class of Person — therefore inheriting all Person's attributes and member methods.
#include <iostream>
#include <cmath> // Included to allow calling for the round() function.
#include "Person.h" // Included to call the class Person in this file.

using namespace std;

// This class block provides the class definition of Employees.
// ': public Person' allows the inheritance of class Employees from class Person
class Employees: public Person{
    private: // Attribute set Private in compliance with the given instructions
        string EmployeeNumber;
    
    public: // Attribute set Public in compliance with the given instructions
        string Position;
        string Office;
        float Salary;

        // Constructor for class Employees with no parameters
        // ': Person' allows the constructor to inherit the constructor with no parameter
        // as defined in class Person.
        Employees() : Person(){}

        // Constructor for class Employees with parameters
        // ': Person (*person attributes*)' allows this constructor to create an instance of 
        // Employees that inherits from Person (the parent class). It makes sure that the parent class
        // is initialized together with the specific attributes for this class.
        Employees(string firstName, string lastName, string gender, string emailAddress, string cpNumber,
                string employeeNumber, string position, string office, float salary): 
            Person(firstName, lastName, gender, emailAddress, cpNumber){
                EmployeeNumber = employeeNumber;
                Position = position;
                Office = office;
                Salary = round(salary * 100.0) / 100.0; // Strictly rounds off the salary value to two decimal places regardless of parameter value
        }

        // Unique Setter Member Methods for this class
        void setEmployeeNumber(string employeeNumber){ EmployeeNumber = employeeNumber; }
        void setPosition(string position){ Position = position; }
        void setOffice(string office){ Office = office; }
        void setSalary(float salary){ 
            // Strictly rounds off the salary value to two decimal places regardless of parameter value
            Salary = round(salary * 100.00) / 100.00; 
        }

        // Unique Getter Member Methods for this class
        string getEmployeeNumber(){ return EmployeeNumber; }
        string getPosition(){ return Position; }
        string getOffice(){ return Office; }
        float getSalary(){ return Salary; }
};