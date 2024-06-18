// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 15 May 2024

// This '.h' file defines the 'HaircutAppointment' class.
// The definitions involve its defining attributes and its accessible functions.
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