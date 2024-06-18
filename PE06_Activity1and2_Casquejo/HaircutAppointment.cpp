// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 15 May 2024

// This '.cpp' file allows the creation of a class named 'HaircutAppointment'
// and access its contents all under the same file. The main function
// simply calls the public functions set in the said class.
#include <iostream>

using namespace std;

// This entire class block provides the class definition of HaircutAppointment.
class HaircutAppointment{
    private: // The private variables in this class are treated as the object's attributes.
        string PreferredBarber;
        string AppointmentDate;
        string AppointmentTime;

    public:
        // This constructor creates an instance of the class HaircutAppointment and
        // simultaneously populates it with information upon its creation.
        HaircutAppointment(string preferredBarber, string date, string time){
            PreferredBarber = preferredBarber;
            AppointmentDate = date;
            AppointmentTime = time;
        }

        // This function displays the values held on a specific instance of HaircutAppointment.
        void displayAttributes(){
            cout << "\t\tPreferred Barber: " << PreferredBarber << endl;
            cout << "\t\tAppointment Date: " << AppointmentDate << endl;
            cout << "\t\tAppointment Time: " << AppointmentTime << endl;
        }
};

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