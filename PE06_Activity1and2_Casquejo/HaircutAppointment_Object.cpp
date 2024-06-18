// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 15 May 2024

// This '.cpp' file executes the implementation of integrating a header file to a '.cpp' file.
// It will show how Object-Oriented Programming is done for the context of the 'HaircutAppointment' class definition.
#include <iostream>
#include "HaircutAppointment.h"

using namespace std;

// The main function exectues the entire '.cpp' program.
int main(){
    
    // This code block prints the program heading stating relevant information in this programming exercise.
    cout << endl;
    cout << "\t============================================================" << endl;
    cout << "\t|              CMSC 28 Programming Exercise 06             |" << endl;
    cout << "\t|            by Jann Dave Rhodore Gotas Casquejo           |" << endl;
    cout << "\t============================================================" << endl;
    cout << "\t| This programming exercise will demonstrate and practice  |" << endl;
    cout << "\t| the basic structure of a '.cpp' file in object-oriented  |" << endl;
    cout << "\t| program. Variations of this file will implement ways to  |" << endl;
    cout << "\t| construct a class and connect it to the main function.   |" << endl;
    cout << "\t============================================================" << endl;

    // This code block creates a dividing header to denote the creation of a
    // class instance (HaircutAppointment) and displaying their attribute values.
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t| CREATE A CLASS INSTANCE AND DISPLAY ITS ATTRIBUTE VALUES |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    // Creates an instance of HaircutAppointment and populates corresponding attribute values.
    HaircutAppointment firstAppointment("Kuya Ben", "18 May 2024", "04:00 PM");

    // Displays the attribute values kept in this specified instance
    firstAppointment.displayAttributes();

    // Prints a closing footer for the program, signifying the end of the program execution.
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                 END OF PROGRAM EXECUTION                 |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    return 0;
}