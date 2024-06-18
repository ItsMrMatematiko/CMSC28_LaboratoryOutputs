// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 17 May 2024

// This '.h' (header) file will define the attributes and member functions of the Movie class.
// This class is expected to call the Person class as an object type.

#include <iostream>
#include <vector> // Included to allow the creation of a vector list (dynamic arrays in C++).
#include "Person.h" // Included to call the class Person in this file.

using namespace std;

// This class block provides the class definition of Movie.
class Movie{
    private: // The private attributes of this class are treated as the object's attributes.
        string Title;
        string Synopsis;
        string MPAA_Rating;
        vector<string> Genre; // a vector list of type string can allow multiple genres to be stored in one attribute.
        vector<Person> Directors; // a vector list of type Person can allow multiple directors to be stored in one attribute.
        vector<Person> Actors; // a vector list of type Person can allow multiple actors to be stored in one attribute.
    public:
        // Constructor for class Movie with no parameters
        Movie(){}

        // Constructor for class Person with parameters
        // This can assign values to the class attributes upon its instance creation
        Movie(string title, string synopsis, string mpaa_rating, vector<string> genre, 
                vector<Person> directors, vector<Person> actors){
            Title = title;
            Synopsis = synopsis;
            MPAA_Rating = mpaa_rating;
            Genre = genre;
            Directors = directors;
            Actors = actors;
        }

        // Setter Member Methods
        // Sets the value of a specific class attribute
        void setTitle(string title){ Title = title; }
        void setSynopsis(string synopsis){ Synopsis = synopsis; }
        void setMPAARating(int ratingCode){
            switch(ratingCode){ // Specifies which rating to save in this class' attribute based on the ratingCode parameter.
                case 1: MPAA_Rating = "G"; break;
                case 2: MPAA_Rating = "PG"; break;
                case 3: MPAA_Rating = "PG-13"; break;
                case 4: MPAA_Rating = "R"; break;
                case 5: MPAA_Rating = "NC-17"; break;
                default: MPAA_Rating = "No Valid Rating"; break;
            }
        }
        void setGenre(vector<string> genre){ Genre = genre; }
        void setDirectors(vector<Person> directors){ Directors = directors; }
        void setActors(vector<Person> actors){ Actors = actors; }

        // Getter Member Methods
        // Gets the value of a specific attribute in a specific class instance
        string getTitle(){ return Title; }
        string getSynopsis(){ return Synopsis; }
        string getMPAARating(){ return MPAA_Rating; }
        vector<string> getGenre(){ return Genre; }
        vector<Person> getDirectors(){ return Directors; }
        vector<Person> getActors(){ return Actors; }
};
