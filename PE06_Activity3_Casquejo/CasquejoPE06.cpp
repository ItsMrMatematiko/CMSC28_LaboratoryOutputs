// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 17 May 2024

// This program aims to implement the member methods under class Movie.
// It will also check if the implementation of a class in another class is done
// correctly — provided that class Movie also has attributes that are of class Person. 

#include <iostream>
#include <vector> // Included to allow vector lists (a dynamic array in C++)
#include <limits> // Included for character-checking functions
#include "Movie.h" // Included to call the class Movie in this file.

using namespace std;

/* FUNCTION PROTOTYPES */
void executeProgram();
void printProgramHeading();
void enterTitle(string &title);
void enterSynopsis(string &synopsis);
void enterMPAARating(int &rating);
void enterGenres(vector<string> &genreList);
void enterDirector(vector<Person> &directorsList);
void enterActor(vector<Person> &actorsList);
void printMovieDetails(Movie movie);

// The main function executes the C++ program.
int main(){
    executeProgram();
}

// The executeProgram() is separated from the main() function  
// to allow recursion of the program demonstration.
void executeProgram(){
    // Class instance where demonstration is to be executed
    Movie movie;
    
    // Holds the temporary values of the attributes to be assigned to the class instance.
    string title, synopsis, genre;
    vector<string> genreList;  
    vector<Person> directorsList, actorsList;
    int rating;

    // Holds the character response if program execution should be done again.
    char again;

    system("cls");
    printProgramHeading();

    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                   INPUT MOVIE DETAILS                    |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    // Input Movie Details
    // The inputs are separated from this function due to the extensive error handling
    // employed in this program — provided that each user input is enclosed in a do-while loop.
    enterTitle(title);
    enterSynopsis(synopsis);   
    enterMPAARating(rating);
    enterGenres(genreList);
    enterDirector(directorsList);
    enterActor(actorsList);

    // Sets the Attribute Values
    movie.setTitle(title);
    movie.setSynopsis(synopsis);
    movie.setMPAARating(rating);
    movie.setGenre(genreList);
    movie.setDirectors(directorsList);
    movie.setActors(actorsList);

    // Print the Movie Attributes
    printMovieDetails(movie);

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
    cout << "\t|              CMSC 28 Programming Exercise 06             |" << endl;
    cout << "\t|            by Jann Dave Rhodore Gotas Casquejo           |" << endl;
    cout << "\t============================================================" << endl;
    cout << "\t| This programming exercise will focus on implementing a   |" << endl;
    cout << "\t| object-oriented approach for populating attributes about |" << endl;
    cout << "\t| a specific Movie. This program will involve calling a    |" << endl;
    cout << "\t| class in another class and populate the called class     |" << endl;
    cout << "\t| with information via the calling class.                  |" << endl;
    cout << "\t|                                                          |" << endl;
    cout << "\t| To make things easier, the calling class is Movie        |" << endl;
    cout << "\t| and the called class is Person. Each person in the       |" << endl;
    cout << "\t| program will be saved in a vector list in C++.           |" << endl;
    cout << "\t============================================================" << endl;
}

// The enterTitle() function asks the user for the value of the Title attribute.
// Error handling has been employed for no-input values.
void enterTitle(string &title){
    do{
        cout << "\t\tMovie Title: ";
        getline(cin, title); 

        if(title.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(title.empty());
}

// The enterSynopsis() function asks the user for the value of the Synopsis attribute.
// Error handling has been employed for no-input values.
void enterSynopsis(string &synopsis){
    do{
        cout << "\t\tMovie Synopsis: ";
        getline(cin, synopsis); 

        if(synopsis.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(synopsis.empty());
}

// The enterMPAARating() function asks the user for the value of the MPAARating attribute.
// Error handling has been employed for no-input values and invalid character/string inputs.
void enterMPAARating(int &rating){
    cout << endl;
    cout << "\t\tMPAA (Motion Picture Association of America) Ratings" << endl;
    cout << "\t\t\t[1] G    [2] PG    [3] PG-13    [4] R    [5] NC-17" << endl << endl;

    do {
        cout << "\t\tEnter the rating number from MPAA: ";
        if (!(cin >> rating) || rating < 1 || rating > 5) {
            cout << "\t\t\tYou did not enter a valid rating number. Please try again." << endl << endl;
            
            // Clears the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        
        else {
            // Check if there are any characters left in the input buffer
            char remaining;
            
            if (cin.get(remaining) && remaining != '\n') {
                cout << "\t\t\tInvalid input. Please enter an integer value." << endl << endl;
                
                // Clears the input buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
            
            else {
                break;
            }
        }
    } while (true);
}

// The enterGenre() function asks the user for the value of the Genre attribute.
// It does this by first asking the genre and then pushing the value to a vector list.
// Error handling has been employed for no-input values and terminating the genre input loop.
void enterGenres(vector<string> &genreList){
    string genre;

    cout << endl;
    do {
        cout << "\t\tEnter Movie Genre(s) [Input '=' to stop]: ";
        getline(cin, genre);

        if (genre.empty()) {
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;
        } 
        
        // Checks for terminating genre input loop
        else if (genre == "=") {
            if (genreList.empty()) {
                cout << "\t\t\tAt least one genre must be provided. Please try again." << endl << endl;
            } 
            
            else {
                cin.clear();
                break;
            }
        } 
        
        // Pushes the genre as a list item on the specified vector.
        else {
            genreList.push_back(genre);
        }
    } while (true);
}

// The enterDirector() function asks the user for the value of the Director attribute.
// It does this by first creating a Person instance and populate the said instance with their
// corresponding attributes (i.e., FirstName, LastName, and Gender). Each completed instance
// information inputs will be pushed to a vector list of type Person — allowing multiple directors.
// Error handling has been employed for no-input values and terminating the director input loop.
void enterDirector(vector<Person> &directorsList){
    char addMore;
    string firstName, lastName, gender;
    Person director;

    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                 ENTER DIRECTOR DETAILS                   |" << endl;
    cout << "\t------------------------------------------------------------";
    
    do {
        cout << endl;

        // Director's First Name
        do {
            cout << "\t\tEnter Director's First Name: ";
            getline(cin, firstName); 

            if (firstName.empty())
                cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;    
        } while (firstName.empty());

        // Director's Last Name
        do {
            cout << "\t\tEnter Director's Last Name: ";
            getline(cin, lastName); 

            if (lastName.empty())
                cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;    
        } while (lastName.empty());

        // Director's Gender
        do {
            cout << "\t\tEnter Director's Gender: ";
            getline(cin, gender); 

            if (gender.empty())
                cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;    
        } while (gender.empty());

        // Populate the created instance with their respective attribute values
        director.setFirstName(firstName);
        director.setLastName(lastName);
        director.setGender(gender);

        // Pushes the completed director instance into a vector list to allow recording multiple directors.
        directorsList.push_back(director);
        
        // Checks if there are more directors to be added
        cout << endl;
        cout << "\t\tAdd more directors for this movie? [Y] Yes     [Other Inputs] No: ";
        cin >> addMore;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while (addMore == 'Y' || addMore == 'y');
}

// The enterActor() function asks the user for the value of the Actor attribute.
// It does this by first creating a Person instance and populate the said instance with their
// corresponding attributes (i.e., FirstName, LastName, and Gender). Each completed instance
// information inputs will be pushed to a vector list of type Person — allowing multiple actors.
// Error handling has been employed for no-input values and terminating the actor input loop.
void enterActor(vector<Person> &actorsList){
    char addMore;
    string firstName, lastName, gender;
    Person actor;

    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                   ENTER ACTOR DETAILS                    |" << endl;
    cout << "\t------------------------------------------------------------";
    
    do {
        cout << endl;

        // Actor's First Name
        do {
            cout << "\t\tEnter Actor's First Name: ";
            getline(cin, firstName); 

            if (firstName.empty())
                cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;    
        } while (firstName.empty());

        // Actor's Last Name
        do {
            cout << "\t\tEnter Actor's Last Name: ";
            getline(cin, lastName); 

            if (lastName.empty())
                cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;    
        } while (lastName.empty());

        // Actor's Gender
        do {
            cout << "\t\tEnter Actor's Gender: ";
            getline(cin, gender); 

            if (gender.empty())
                cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;    
        } while (gender.empty());

        // Populate the created instance with their respective attribute values
        actor.setFirstName(firstName);
        actor.setLastName(lastName);
        actor.setGender(gender);

        // Pushes the completed director instance into a vector list to allow recording multiple directors.
        actorsList.push_back(actor);
        
        // Checks if there are more actors to be added
        cout << endl;
        cout << "\t\tAdd more actors for this movie? [Y] Yes     [Other Inputs] No: ";
        cin >> addMore;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while (addMore == 'Y' || addMore == 'y');
}

// The printMovieDetails() function prints the information collected from the user
// and is formatted by the programmer accordingly.
void printMovieDetails(Movie movie){
    int idxCtr01;
    vector<string> genres = movie.getGenre();
    vector<Person> directors = movie.getDirectors();
    vector<Person> actors = movie.getActors();

    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                   PRINT MOVIE DETAILS                    |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    cout << "\t\tMovie Title: " << movie.getTitle() << endl << endl;
    cout << "\t\tMovie Synopsis: " << endl;
        cout << "\t\t\t" << movie.getSynopsis() << endl << endl;
    cout << "\t\tMovie MPAA Rating: " << movie.getMPAARating() << endl << endl; 
    cout << "\t\tMovie Genre(s): " << endl; 
        for (size_t i = 0; i < genres.size(); ++i) { // Checks and prints each entry stored in the vector list
            cout << "\t\t\t" << genres[i] << endl;
        }

    cout << endl;
    cout << "\t\tMovie Director(s): " << endl; 
        for (size_t i = 0; i < directors.size(); ++i) { // Checks and prints each entry stored in the vector list
            cout << "\t\t\t" << directors[i].getFirstName() << " " << directors[i].getLastName() << endl;
            cout << "\t\t\tGender: " << directors[i].getGender() << endl << endl;
        }

    cout << "\t\tMovie Actor(s): " << endl;
        for (size_t i = 0; i < actors.size(); ++i) { // Checks and prints each entry stored in the vector list
            cout << "\t\t\t" << actors[i].getFirstName() << " " << actors[i].getLastName() << endl;
            cout << "\t\t\tGender: " << actors[i].getGender() << endl << endl;
        }        
}
