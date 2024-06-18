// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 29 May 2024

// This '.h' (header) file will define the attributes and member functions of the Person class.
// This class is expected to be the parent class of 'Student.h' and 'Employees.h'.

#include <iostream>

using namespace std;

// This class block provides the class definition of Person.
class Person{
    public: // Attributes to be shared with the child classes, hence, set in public.
        string FirstName;
        string LastName;
        string Gender;
        string EmailAddress;
        string CPNumber;

        // Constructor for class Person with no parameters
        Person(){}

        // Constructor for class Person with parameters
        // This can assign values to the class attributes upon its instance creation
        Person(string firstName, string lastName, string gender, string emailAddress, string cpNumber){
            FirstName = firstName;
            LastName = lastName;
            Gender = gender;
            EmailAddress = emailAddress;
            CPNumber = cpNumber;
        }

        // Setter Member Methods
        // Sets the value of a specific class attribute
        void setFirstName(string firstName){ FirstName = firstName; }
        void setLastName(string lastName){ LastName = lastName; }
        void setGender(string gender){ Gender = gender; }
        void setEmailAddress(string emailAddress){ EmailAddress = emailAddress; }
        void setCPNumber(string cpNumber){ CPNumber = cpNumber; }

        // Getter Member Methods
        // Gets the value of a specific attribute in a specific class instance
        string getFirstName(){ return FirstName; }
        string getLastName(){ return LastName; }
        string getGender(){ return Gender; }
        string getEmailAddress(){ return EmailAddress; }
        string getCPNumber(){ return CPNumber; }
};