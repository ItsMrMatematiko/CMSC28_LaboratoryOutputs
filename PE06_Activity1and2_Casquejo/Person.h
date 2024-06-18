#include <iostream>

using namespace std;

class Person{
    private:
        int Age;
        string Gender;

    public:
        Person(){}

        void setAge(int age){
            Age = age;
        }

        void setGender(string gender){
            Gender = gender;
        }

        int getAge(){
            return Age;
        }

        string getGender(){
            return Gender;
        }
};