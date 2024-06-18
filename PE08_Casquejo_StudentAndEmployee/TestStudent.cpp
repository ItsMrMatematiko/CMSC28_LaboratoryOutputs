// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 29 May 2024

// This program aims to test instance creation for class Student and test all of its expected
// attribute assignments, inherited member methods, and unique member methods.

#include <iostream>
#include <limits> // Included for character-checking functions
#include "Student.h" // Included to call the class Student in this file.

using namespace std;

/* FUNCTION PROTOTYPES */
void executeProgram();
void printProgramHeading();
void enterFirstName(string &firstName);
void enterLastName(string &lastName);
void enterGender(string &gender);
void enterEmailAddress(string &emailAddress);
void enterCPNumber(string &cpNumber);
void enterStudentNumber(string &studentNumber);
void enterCourse(string &course);
void enterDepartment(string &department);
void enterCollege(string &college);
void printStudentDetails(Student student);

// The main function executes the C++ program.
int main(){
    executeProgram();
}

// The executeProgram() is separated from the main() function  
// to allow recursion of the program demonstration.
void executeProgram(){
    // Class instance where demonstration is to be executed
    Student student;

    // Holds the temporary values of the attributes to be assigned to the class instance.
    string firstName, lastName, gender, emailAddress, cpNumber;
    string studentNumber, course, department, college;

    // Holds the character response if program execution should be done again.
    char again;

    system("cls");
    printProgramHeading();
    
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                 INPUT STUDENT DETAILS                    |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    // Input Student Details
    // The inputs are separated from this function due to the extensive error handling
    // employed in this program — provided that each user input is enclosed in a do-while loop.
    enterFirstName(firstName);
    enterLastName(lastName);
    enterGender(gender);
    enterEmailAddress(emailAddress);
    enterCPNumber(cpNumber);
    enterStudentNumber(studentNumber);
    enterCourse(course);
    enterDepartment(department);
    enterCollege(college);

    // Sets the Attribute Values
    student.setFirstName(firstName);
    student.setLastName(lastName);
    student.setGender(gender);
    student.setEmailAddress(emailAddress);
    student.setCPNumber(cpNumber);
    student.setStudentNumber(studentNumber);
    student.setCourse(course);
    student.setDepartment(department);
    student.setCollege(college);

    // Print the Student Attributes
    printStudentDetails(student);

    // Asks if program recursion would be performed
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|              END OF PROGRAM DEMONSTRATION                |" << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t\tShould we run the program again?" << endl;
    cout << "\t\t[Y] Yes     [N] No" << endl << endl;

    // Error handling for non-valid character/string inputs
    do {
        cout << "\t\tEnter character input here: ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears the input buffer

        // Converts input character to lowercase to make the input case-insensitive
        again = tolower(again);

        // Check if the input is a valid character
        if (again != 'y' && again != 'n') {
            cout << "\t\t\tInvalid input. Please enter 'Y' for Yes or 'N' for No." << endl << endl;
        }
    } while (again != 'y' && again != 'n');

    if(again == 'y')    executeProgram(); // Executes a program recursion
    else    return; // Goes back to the main function and terminates the program
}

// The printProgramHeading() function prints the necessary information prior to program demonstration
void printProgramHeading(){
    cout << endl;
    cout << "\t============================================================" << endl;
    cout << "\t|              CMSC 28 Programming Exercise 08             |" << endl;
    cout << "\t|            by Jann Dave Rhodore Gotas Casquejo           |" << endl;
    cout << "\t============================================================" << endl;
    cout << "\t| This programming exercise will focus on implementing     |" << endl;
    cout << "\t| inheritance under an object-oriented approach for        |" << endl;
    cout << "\t| populating and displaying the attributes of a Student    |" << endl;
    cout << "\t| instance. Information would be populated with user input |" << endl;
    cout << "\t| and be displayed right after entering all information.   |" << endl;
    cout << "\t============================================================" << endl;
}

// The enterFirstName() function asks the user for the value of the FirstName attribute.
// Error handling has been employed for no-input values.
void enterFirstName(string &firstName){
    do{
        cout << "\t\tEnter Student's First Name: ";
        getline(cin, firstName); 

        if(firstName.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(firstName.empty());
}

// The enterLastName() function asks the user for the value of the LastName attribute.
// Error handling has been employed for no-input values.
void enterLastName(string &lastName){
    do{
        cout << "\t\tEnter Student's Last Name: ";
        getline(cin, lastName); 

        if(lastName.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(lastName.empty());
}

// The enterGender() function asks the user for the value of the Gender attribute.
// Error handling has been employed for no-input values.
void enterGender(string &gender){
    do{
        cout << "\t\tEnter Student's Gender: ";
        getline(cin, gender); 

        if(gender.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(gender.empty());
}

// The enterEmailAddress() function asks the user for the value of the EmailAddress attribute.
// Error handling has been employed for no-input values and invalid email formats ('abc@def.ghi')
void enterEmailAddress(string &emailAddress) {
    do {
        cout << "\t\tEnter Student's Email Address: ";
        getline(cin, emailAddress);

        if (emailAddress.empty()) {
            cout << "\t\t\tYou entered nothing. Please try again." << endl << endl;
            continue;
        }

        // Gets the index positions of specific characters needed in the input validation.
        size_t atPos = emailAddress.find('@');
        size_t dotPos = emailAddress.find('.', atPos);

        // Check if there is an '@' followed by a '.', with characters in between and after
        if (atPos == 0 || atPos == string::npos || dotPos == string::npos || dotPos <= atPos + 1 || dotPos == emailAddress.length() - 1) {
            cout << "\t\t\tInvalid email format. Please enter a valid email address." << endl << endl;
            emailAddress.clear();
            continue;
        }

        break; 
    } while (true);
}

// The enterCPNumber() function asks the user for the value of the CPNumber attribute.
// Error handling has been employed for no-input values.
void enterCPNumber(string &cpNumber){
    do{
        cout << "\t\tEnter Student's Contact Number: ";
        getline(cin, cpNumber); 

        if(cpNumber.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(cpNumber.empty());
}

// The enterStudentNumber() function asks the user for the value of the StudentNumber attribute.
// Error handling has been employed for no-input values.
void enterStudentNumber(string &studentNumber){
    do{
        cout << "\t\tEnter Student's ID Number: ";
        getline(cin, studentNumber); 

        if(studentNumber.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(studentNumber.empty());
}

// The enterCourse() function asks the user for the value of the Course attribute.
// Error handling has been employed for no-input values.
void enterCourse(string &course){
    do{
        cout << "\t\tEnter Student's Course: ";
        getline(cin, course); 

        if(course.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(course.empty());
}

// The enterDepartment() function asks the user for the value of the Department attribute.
// Error handling has been employed for no-input values.
void enterDepartment(string &department){
    do{
        cout << "\t\tEnter Student's Department (where the Course is being offered): ";
        getline(cin, department); 

        if(department.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(department.empty());
}

// The enterCollege() function asks the user for the value of the College attribute.
// Error handling has been employed for no-input values.
void enterCollege(string &college){
    do{
        cout << "\t\tEnter Student's College (the College where the Department is housed): ";
        getline(cin, college); 

        if(college.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(college.empty());
}

// The printStudentDetails() function prints the information collected from the user
// that is formatted by the programmer accordingly.
void printStudentDetails(Student student){
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                  PRINT STUDENT DETAILS                   |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    cout << "\t\tWelcome to UP Mindanao, " << student.getFirstName() << "!" << endl << endl;

    cout << "\t\tBeing an 'Iskolar ng Bayan' is not an easy feat as many people like you" << endl;
    cout << "\t\taspire to be part of this University's community. From the wide pool of" << endl;
    cout << "\t\tapplicants to the high admission qualifications, we believe that your" << endl;
    cout << "\t\tpresence in this University will surely make an impact in serving the" << endl;
    cout << "\t\tFilipino people. " << endl << endl;

    cout << "\t\tAs you stay here in the University, please take note of your recorded credentials:" << endl << endl;
    cout << "\t\t\tYour Full Name: " << student.getFirstName() << " " << student.getLastName() << endl;
    cout << "\t\t\tYour Gender: " << student.getGender() << endl;
    cout << "\t\t\tYour Email Address: " << student.getEmailAddress() << endl;
    cout << "\t\t\tYour Contact Number: " << student.getCPNumber() << endl << endl;

    cout << "\t\t\tYour Student Number: " << student.getStudentNumber() << endl;
    cout << "\t\t\tYour Enrolled Course: " << student.getCourse() << endl;
    cout << "\t\t\tYour Department: " << student.getDepartment() << endl;
    cout << "\t\t\tYour College: " << student.getCollege() << endl << endl;

    cout << "\t\tWe wish you the best of luck in your stay here, " << student.getFirstName() << "!" << endl;
    cout << "\t\tLagi't lagi, para sa bayan." << endl;
}