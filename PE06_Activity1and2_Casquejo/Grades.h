#include <iostream>

using namespace std;

class Grades{
    private:
        int Grade;
        string Subject;

    public:
        Grades(){}

        void setGrade(int grade){
            Grade = grade;
        }

        void setSubject(string subject){
            Subject = subject;
        }

        void getGrade(){
            if(Grade > 100 || Grade < 0)
                cout << "\t\t\tTheir grade in this subject is " << Grade << ". \n\t\t\tThis grade is invalid.";

            else if(Grade >= 60)
                cout << "\t\t\tTheir grade in this subject is " << Grade << ". \n\t\t\tThey passed.";

            else 
                cout << "\t\t\tTheir grade in this subject is " << Grade << ". \n\t\t\tThey failed.";
        }

        string getSubject(){
            return Subject;
        }
};