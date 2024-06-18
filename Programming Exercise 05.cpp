// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 15 May 2024

// This program aims to execute basic statistical functions to at most 10 non-zero integer values.

#include <iostream>
#include <iomanip> // Included for Numerical Output Formatting
#include <limits> // Included for Integer-Checking Functions
#include <cmath> // Included for Complex Mathematical Operations

using namespace std;

/* FUNCTION PROTOTYPES */
void inputData(int inputArray[], int &ctr);
int findLargestNumber(int inputArray[]);
int findSmallestNumber(int inputArray[]);
float getAverage(int inputArray[]);
float getPopulationVariance(int inputArray[]);
float getPopulationStandardDeviation(int inputArray[]);
void displayOutputs(int largestNumber, int smallestNumber, float average, float variance, float standardDeviation);

// The main function executes the C++ program.
int main() {
    /*
        numArray values are all assumed as 0 to avoid garbage values in unfilled indices, 
        as the program specification allows a maximum of 10 integer inputs.
    */
    int numArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
    int inputCtr = 0;

    // This code block prints necessary information prior to performing program operations.
    cout << endl;
    cout << "\t============================================================" << endl;
    cout << "\t|              CMSC 28 Programming Exercise 05             |" << endl;
    cout << "\t|            by Jann Dave Rhodore Gotas Casquejo           |" << endl;
    cout << "\t============================================================" << endl;
    cout << "\t| This programming exercise will calculate for the largest |" << endl;
    cout << "\t| and smallest number, average, variance, and the standard |" << endl;
    cout << "\t| deviation of atmost 10 integers. Simply enter '0' if you |" << endl;
    cout << "\t| wish to stop entering values and terminate the program.  |" << endl;
    cout << "\t============================================================" << endl;
    cout << endl;
    
    // Calls the inputData function to populate integers in numArray and keep track
    // of the number of inputs prompted by the user 
    inputData(numArray, inputCtr);

    // Prints the header of the expected displays. It also prompts an error
    // should there be no integer input values provided by the user.
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                     PROGRAM OUTPUTS                      |" << endl;
    cout << "\t------------------------------------------------------------" << endl;
    
    if(inputCtr <= 0){
        cout << "\t\tERROR: There are no integer inputs for solving. " << endl;
    }

    // Assigns the values of the respective variables which would be passed to
    // the displayOutputs function to print the expected outputs.
    else{        

        // All of the functions called in this code block assumes that there is
        // at least one element in the array, discarding empty inputs as a case 
        // for these functions to process.
        int largestNumber = findLargestNumber(numArray);
        int smallestNumber = findSmallestNumber(numArray);
        float average = getAverage(numArray);
        float variance = getPopulationVariance(numArray);
        float standardDeviation = getPopulationStandardDeviation(numArray);
        
        displayOutputs(largestNumber, smallestNumber, average, variance, standardDeviation);

        cout << endl;
        cout << "\t------------------------------------------------------------" << endl;
        cout << "\t|                 END OF PROGRAM EXECUTION                 |" << endl;
        cout << "\t------------------------------------------------------------" << endl;
    }

    return 0;
}

// The inputData function populates at most 10 non-zero integers to an array.
void inputData(int inputArray[], int &ctr){
    int integerInput;

    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                 INPUT YOUR INTEGER VALUES                |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    while (ctr < 10)
    {
        cout << "\t\tEnter Integer No. " << ctr + 1 << ": ";
        
        // This chained if-else statements employ a stringent filter to only 
        // accept integer values. Other characters or floating point values will be
        // discarded as an input and will be prompted to enter an integer value again.
        if(cin >> integerInput){

            // Should the first set of characters be an integer, this if condition
            // checks if there is a decimal point in the input buffer. If there is none
            // (by assuming that the next character is newline), then it proceeds with
            // performing their respective functions (0 to terminate input and other
            // integer values to populate the array).
            if(cin.peek() == '\n'){
                if(integerInput == 0)   break;
            
                else{
                    inputArray[ctr] = integerInput;
                    
                    // Increments the value of ctr to refer to the next array index.
                    ctr++;	
                }
            }
			
			// If there are other characters besides newline from the input, then
			// this program assumes that the input is not an integer, forcing this
			// else condition to execute an error-handling procedure.
            else{
                cout << "\t\t\tYour input is not an integer. Please try again. "<< endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }            
        }

        else{
            cout << "\t\t\tYour input is not an integer. Please try again. "<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }   
    }    
}

// The findLargestNumber function finds the largest number among the non-zero integer array inputs.
int findLargestNumber(int inputArray[]){
    // This assumes that the first element of the array is the largest number.
    int largestNumber = inputArray[0];

    // Runs through all elements in the array.
    for(int idxCtr = 0; idxCtr < 10; idxCtr++){
        
        // If a 0 is encountered, this line terminates reading the rest of the array.
        if(inputArray[idxCtr] == 0) break;
        
        else{
            // Replaces largestNumber should there be an array element
            // that is greater than the current largestNumber.
            if(largestNumber < inputArray[idxCtr]){
                largestNumber = inputArray[idxCtr];
            }
        }
    }

    // Returns the last kept value of the largestNumber.
    return largestNumber;
}

// The findSmallestNumber function finds the smallest number among the non-zero integer array inputs.
int findSmallestNumber(int inputArray[]){
    // This assumes that the first element of the array is the smallest number.
    int smallestNumber = inputArray[0];

    // Runs through all elements in the array.
    for(int idxCtr = 0; idxCtr < 10; idxCtr++){
        
        // If a 0 is encountered, this line terminates reading the rest of the array.
        if(inputArray[idxCtr] == 0) break;
        
        else{
            // Replaces smallestNumber should there be an array element
            // that is smaller than the current smallestNumber.
            if(smallestNumber > inputArray[idxCtr]){
                smallestNumber = inputArray[idxCtr];
            }
        }
    }

    // Returns the last kept value of the largestNumber.
    return smallestNumber;
}

// The getAverage function solves for the average among the non-zero integer array inputs.
float getAverage(int inputArray[]){
    // sumOfInputs will hold the sum of the values in the array.
    // inputCount will hold the number of non-zero values in the array.
    int sumOfInputs = 0, inputCount;

    // Runs through all elements in the array.
    for(int idxCtr = 0; idxCtr < 10; idxCtr++){
        
        // If a 0 is encountered, this code block assigns the value of 
        // the valid input count to the current idxCtr value and terminates  
        // reading the rest of the array.
        if(inputArray[idxCtr] == 0){
            inputCount = idxCtr;
            break;  
        } 
        
        // Adds the non-zero array elements to the sumOfInputs
        else{
            sumOfInputs += inputArray[idxCtr];
        }

        // Assumes the inputCount to 10 if there are no non-zero elements.
        inputCount = 10;
    }

    // Returns the value of average as a floating point number.
    return (float) sumOfInputs / (float) inputCount;
}

// The getPopulationVariance function solves for the population variance among the non-zero integer array inputs.
float getPopulationVariance(int inputArray[]){
    // inputCount will hold the number of non-zero values in the array.
    // sumOfSquares will hold the square of the difference between each non-zero element and the array's average.
    int inputCount;
    float sumOfSquares = 0;
    float average = getAverage(inputArray);

    // Runs through all elements in the array.
    for(int idxCtr = 0; idxCtr < 10; idxCtr++){
        
        // If a 0 is encountered, this code block assigns the value of 
        // the valid input count to the current idxCtr value and terminates  
        // reading the rest of the array.
        if(inputArray[idxCtr] == 0){
            inputCount = idxCtr;
            break;  
        } 
        
        // Adds the square of the difference between each non-zero element and the array's average.
        else{
            sumOfSquares += pow((float) inputArray[idxCtr] - average, 2);
        }

        // Assumes the inputCount to 10 if there are no non-zero elements.
        inputCount = 10;
    }    

    // Returns the value of average as a floating point number.
    return sumOfSquares / (float) inputCount;
}

// The getPopulationStandardDeviation function solves for the population standard deviation among the non-zero integer array inputs.
float getPopulationStandardDeviation(int inputArray[]){
    // Returns the square root of the array's Population Variance.
    return sqrt(getPopulationVariance(inputArray));
}

// The displayOutputs function prints the expected outputs of the C++ program.
void displayOutputs(int largestNumber, int smallestNumber, float average, float variance, float standardDeviation){
    // Displays the program's expected values by using parameters which can be called
    // from the main function.
    cout << "\t\tLargest Number: "<< largestNumber << endl;
    cout << "\t\tSmallest Number: "<< smallestNumber << endl;
    cout << "\t\tAverage: "<< fixed << setprecision(2) << average << endl;
    cout << "\t\tVariance (Population): "<< fixed << setprecision(2) << variance << endl;
    cout << "\t\tStandard Deviation (Population): "<< fixed << setprecision(2) << standardDeviation << endl;
}
