// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 17 May 2024

// This '.h' (header) file will define the attributes and member functions of the Person class.
// This class is expected to be called in 'Movie.h' as a type for the directors and actors.

#include <iostream>

using namespace std;

// This class block provides the class definition of Person.
class Person{
    private: // The private attributes of this class are treated as the object's attributes.
        string FirstName;
        string LastName;
        string Gender;

    public:        
        // Constructor for class Person with no parameters
        Person(){}

        // Constructor for class Person with parameters
        // This can assign values to the class attributes upon its instance creation
        Person(string firstName, string lastName, string gender){
            FirstName = firstName;
            LastName = lastName;
            Gender = gender;
        }

        // Setter Member Methods
        // Sets the value of a specific class attribute
        void setFirstName(string firstName){ FirstName = firstName; }
        void setLastName(string lastName){ LastName = lastName; }
        void setGender(string gender){ Gender = gender; }

        // Getter Member Methods
        // Gets the value of a specific attribute in a specific class instance
        string getFirstName(){ return FirstName; }
        string getLastName(){ return LastName; }
        string getGender(){ return Gender; }
};
