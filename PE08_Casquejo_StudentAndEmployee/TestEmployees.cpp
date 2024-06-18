// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 29 May 2024

// This program aims to test instance creation for class Employees and test all of its expected
// attribute assignments, inherited member methods, and unique member methods.

#include <iostream>
#include <limits> // Included for character-checking functions
#include <sstream> // Included to allow attempt of parsing string into float.
#include <iomanip> // Included to allow setting a specific floating point precision 
#include "Employees.h" // Included to call the class Employees in this file.

using namespace std;

/* FUNCTION PROTOTYPES */
void executeProgram();
void printProgramHeading();
void enterFirstName(string &firstName);
void enterLastName(string &lastName);
void enterGender(string &gender);
void enterEmailAddress(string &emailAddress);
void enterCPNumber(string &cpNumber);
void enterEmployeeNumber(string &EmployeeNumber);
void enterPosition(string &position);
void enterOffice(string &office);
void enterSalary(float &salary);
void printEmployeeDetails(Employees employees);

// The main function executes the C++ program.
int main(){
    executeProgram();
}

// The executeProgram() is separated from the main() function  
// to allow recursion of the program demonstration.
void executeProgram(){
    // Class instance where demonstration is to be executed
    Employees employee;

    // Holds the temporary values of the attributes to be assigned to the class instance.
    string firstName, lastName, gender, emailAddress, cpNumber;
    string employeeNumber, position, office;
    float salary;

    // Holds the character response if program execution should be done again.
    char again;

    system("cls");
    printProgramHeading();
    
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                 INPUT EMPLOYEE DETAILS                   |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    // Input Employee Details
    // The inputs are separated from this function due to the extensive error handling
    // employed in this program — provided that each user input is enclosed in a do-while loop.
    enterFirstName(firstName);
    enterLastName(lastName);
    enterGender(gender);
    enterEmailAddress(emailAddress);
    enterCPNumber(cpNumber);
    enterEmployeeNumber(employeeNumber);
    enterPosition(position);
    enterOffice(office);
    enterSalary(salary); // The Salary value saved in the class instance will automatically round up to two decimal places.

    // Sets the Attribute Values
    employee.setFirstName(firstName);
    employee.setLastName(lastName);
    employee.setGender(gender);
    employee.setEmailAddress(emailAddress);
    employee.setCPNumber(cpNumber);
    employee.setEmployeeNumber(employeeNumber);
    employee.setPosition(position);
    employee.setOffice(office);
    employee.setSalary(salary);

    // Print the Employee Attributes
    printEmployeeDetails(employee);

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
    cout << "\t| populating and displaying the attributes of an Employee  |" << endl;
    cout << "\t| instance. Information would be populated with user input |" << endl;
    cout << "\t| and be displayed right after entering all information.   |" << endl;
    cout << "\t============================================================" << endl;
}

// The enterFirstName() function asks the user for the value of the FirstName attribute.
// Error handling has been employed for no-input values.
void enterFirstName(string &firstName){
    do{
        cout << "\t\tEnter Employee's First Name: ";
        getline(cin, firstName); 

        if(firstName.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(firstName.empty());
}

// The enterLastName() function asks the user for the value of the LastName attribute.
// Error handling has been employed for no-input values.
void enterLastName(string &lastName){
    do{
        cout << "\t\tEnter Employee's Last Name: ";
        getline(cin, lastName); 

        if(lastName.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(lastName.empty());
}

// The enterGender() function asks the user for the value of the Gender attribute.
// Error handling has been employed for no-input values.
void enterGender(string &gender){
    do{
        cout << "\t\tEnter Employee's Gender: ";
        getline(cin, gender); 

        if(gender.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(gender.empty());
}

// The enterEmailAddress() function asks the user for the value of the EmailAddress attribute.
// Error handling is employed for no-input values and invalid email formats (Valid Format: 'abc@def.ghi').
void enterEmailAddress(string &emailAddress){
    do {
        cout << "\t\tEnter Employee's Email Address: ";
        getline(cin, emailAddress);
        if (emailAddress.empty()) {
            cout << "\t\t\tYou entered nothing. Please try again." << endl << endl;
            continue;
        }

        // Gets the index positions of specific characters needed in the input validation.
        size_t atPos = emailAddress.find('@');
        size_t dotPos = emailAddress.find('.', atPos);

        // Checks for the correct positions of '@' and '.'
        if (atPos == 0 || atPos == string::npos || dotPos == string::npos || dotPos <= atPos + 1 || dotPos == emailAddress.length() - 1) {
            cout << "\t\t\tInvalid email format. Please enter a valid email address." << endl << endl;
            emailAddress.clear();
        }
    } while (emailAddress.empty());
}


// The enterCPNumber() function asks the user for the value of the CPNumber attribute.
// Error handling has been employed for no-input values.
void enterCPNumber(string &cpNumber){
    do{
        cout << "\t\tEnter Employee's Contact Number: ";
        getline(cin, cpNumber); 

        if(cpNumber.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(cpNumber.empty());
}

// The enterEmployeeNumber() function asks the user for the value of the EmployeeNumber attribute.
// Error handling has been employed for no-input values.
void enterEmployeeNumber(string &employeeNumber){
    do{
        cout << "\t\tEnter Employee's ID Number: ";
        getline(cin, employeeNumber); 

        if(employeeNumber.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(employeeNumber.empty());
}

// The enterPosition() function asks the user for the value of the Position attribute.
// Error handling has been employed for no-input values.
void enterPosition(string &position){
    do{
        cout << "\t\tEnter Employee's Position: ";
        getline(cin, position); 

        if(position.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(position.empty());
}

// The enterOffice() function asks the user for the value of the Office attribute.
// Error handling has been employed for no-input values.
void enterOffice(string &office){
    do{
        cout << "\t\tEnter Employee's Office (the specific office/unit they work): ";
        getline(cin, office); 

        if(office.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(office.empty());
}

// The enterSalary() function asks the user for the value of the Salary attribute.
// Error handling has been employed for no-input values and non-numeric inputs.
void enterSalary(float &salary){
    string inputSalary;

    do{
        cout << "\t\tEnter Employee's Salary (in Php): ";
        getline(cin, inputSalary);

        if (inputSalary.empty()) {
            cout << "\t\t\tYou entered nothing. Please try again." << endl << endl;
            continue;
        }

        stringstream ss(inputSalary); // Creates a stringstream object 'ss' to parse inputSalary into float
        
        if (ss >> salary && ss.eof()) { // Checks if inputSalary is converted into float and is valid 
            break;
        } 
        
        else {
            cout << "\t\t\tInvalid input. Please enter a numeric value." << endl << endl;
        }
    }while (true);
}

// The printEmployeeDetails() function prints the information collected from the user
// and is formatted by the programmer accordingly.
void printEmployeeDetails(Employees employee){
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                  PRINT EMPLOYEE DETAILS                  |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    cout << "\t\tHello! Here are the employee details entered in this program: " << endl << endl;
    cout << "\t\t\tEmployee's Full Name: " << employee.getFirstName() << " " << employee.getLastName() << endl;
    cout << "\t\t\tEmployee's Gender: " << employee.getGender() << endl;
    cout << "\t\t\tEmployee's Email Address: " << employee.getEmailAddress() << endl;
    cout << "\t\t\tEmployee's Contact Number: " << employee.getCPNumber() << endl << endl;

    cout << "\t\t\tEmployee's ID Number: " << employee.getEmployeeNumber() << endl;
    cout << "\t\t\tEmployee's Position: " << employee.getPosition() << endl;
    cout << "\t\t\tEmployee's Office/Unit: " << employee.getOffice() << endl;
    cout << "\t\t\tEmployee's Salary: Php " << fixed << setprecision(2) << employee.getSalary() << endl;
}