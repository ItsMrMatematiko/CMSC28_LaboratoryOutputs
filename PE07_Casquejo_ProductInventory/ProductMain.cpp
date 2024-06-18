// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 22 May 2024

// This program aims to test instance creation for class Employees and test all of its expected
// attribute assignments, inherited member methods, and unique member methods.

#include <iostream>
#include <limits> // Included for character-checking functions
#include <cmath> // Included to allow function calls for mathematical operations
#include <sstream> // Included to allow casting of numbers to string
#include <string> // Included to allow calls for string-manipulation-related functions
#include <iomanip> // Included to allow setting a specific floating point precision 
#include "ProductInventory.h" // Included to call the Product, Clothing, and Electronics class in this file.

using namespace std;

/* FUNCTION PROTOTYPES */
void executeProgram();
void printProgramHeading();
void productDetails(char category);
void inputItemName(string &name);
void inputItemBrand(string &brand);
void inputItemPrice(float &tempPrice, float &roundedPrice);
void inputItemQuantity(int &quantity);
void inputItemDescription(string &description);
void inputItemColor(string &color);
void inputWarrantyDuration(float &warranty);
void askSpecificClothingDetails(string &firstAttrib, string &secondAttrib);
void askSpecificElectronicsDetails(string &firstAttrib, string &secondAttrib);
void setClothingAttributeValues(Clothing &cloth, string name, string brand, float price, int quantity, string description, 
    string color, char category, float warranty, string size, string material);
void setElectronicsAttributeValues(Electronics &electronics, string name, string brand, float price, int quantity, string description, 
    string color, char category, float warranty, string model, string technicalSpecifications);
void printItemDetails(Clothing clothing);
void printItemDetails(Electronics electronics);

// The main function executes the C++ program.
int main(){
    executeProgram();
}

// The executeProgram() is separated from the main() function  
// to allow recursion of the program demonstration.
void executeProgram(){
    system("cls");
    printProgramHeading();

    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                   SELECT AN ITEM TYPE                    |" << endl;
    cout << "\t------------------------------------------------------------" << endl;
    
    cout << "\t\tWhich item would you like to add? " << endl;
    cout << "\t\t\t[C] Clothing  " << endl;
    cout << "\t\t\t[E] Electronics  " << endl << endl;
    
    // 'tempCategory' holds the initial user input which could be a string (for better error handling)
	// 'itemCategory' holds the category of the item to be added in the program.
    // 'again' holds the character response if program execution should be done again.
    string tempCategory;
	char itemCategory, again;
    
    // This do-while loop will ask the user for the character of the item category to be added in the program.
    do{
        cout << "\t\tEnter the character of your choice: ";
        getline(cin, tempCategory);
        
        // Trim leading and trailing whitespace
        size_t start = tempCategory.find_first_not_of(" \t");
        size_t end = tempCategory.find_last_not_of(" \t");
        
        // Checks if itemCategory is all whitespace
		if (start == string::npos) {
            cout << "\t\t\tYou entered an invalid choice. Please try again. " << endl << endl;
            continue;
        }

        else{
        	// Check if the trimmed input is exactly one character
	        if (tempCategory.length() == 1) {
	            itemCategory = tempCategory[0];
	            if (itemCategory == 'C' || itemCategory == 'c' || itemCategory == 'E' || itemCategory == 'e') {
	                break;
	            }
	        }
	
	        cout << "\t\t\tYou entered an invalid choice. Please try again. " << endl << endl;
		}		
    }while(true);

    // The productDetails() function operates the core functionalities of this program.
    productDetails(itemCategory);

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

// The printProgramHeading() function prints the necessary information prior to program demonstration.
void printProgramHeading(){
    cout << endl;
    cout << "\t============================================================" << endl;
    cout << "\t|              CMSC 28 Programming Exercise 07             |" << endl;
    cout << "\t|            by Jann Dave Rhodore Gotas Casquejo           |" << endl;
    cout << "\t============================================================" << endl;
    cout << "\t| This programming exercise will focus on implementing an  |" << endl;
    cout << "\t| object-oriented approach for storing inventory items.    |" << endl;
    cout << "\t| Inheritance and Polymorphism will be emphasized by       |" << endl;
    cout << "\t| having one parent class and two child classes. The       |" << endl;
    cout << "\t| child classes will inherit most of their attributes from |" << endl;
    cout << "\t| their parent class while having a few unique attributes. |" << endl;
    cout << "\t============================================================" << endl;
}

// The productDetails() function will ask the user to input the attributes for the respective class.
// After receiving the inputs, the category input will be used to check which unique attributes for the specific classes
// will be added in the program. This function will also assign and print the item details afterwards.
void productDetails(char category){
    // Holds the temporary values of the attributes to be assigned to the class instance.
    string name, brand, description, color, firstUniqueAttrib, secondUniqueAttrib;
    float tempPrice, roundedPrice, warranty;
    int quantity;
    
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                   ENTER ITEM DETAILS                     |" << endl;
    cout << "\t------------------------------------------------------------" << endl;
   
   // Input Item Details
    // The inputs are separated from this function due to the extensive error handling
    // employed in this program — provided that each user input is enclosed in a do-while loop.
    inputItemName(name);
    inputItemBrand(brand);
    inputItemPrice(tempPrice, roundedPrice);
    inputItemQuantity(quantity);
    inputItemDescription(description);
    inputItemColor(color);    
    inputWarrantyDuration(warranty);

    // This two conditional statements will then be performed to check for the set item category
    // and prompt the user to enter their unique attributes. The item details will also be stored 
    // and printed under the conditionals right after asking for the inputs.
    if(category == 'C' || category == 'c'){
        // For Clothing unique attributes
        askSpecificClothingDetails(firstUniqueAttrib, secondUniqueAttrib);
        Clothing cloth;
        setClothingAttributeValues(cloth, name, brand, roundedPrice, quantity, description, color, category, warranty, firstUniqueAttrib, secondUniqueAttrib);
        printItemDetails(cloth);
    }

    else if(category == 'E' || category == 'e'){
        // For Electronics unique attributes
        askSpecificElectronicsDetails(firstUniqueAttrib, secondUniqueAttrib);
        Electronics electronics;
        setElectronicsAttributeValues(electronics, name, brand, roundedPrice, quantity, description, color, category, warranty, firstUniqueAttrib, secondUniqueAttrib);
        printItemDetails(electronics);
    }
}

// The inputItemName() function asks the user for the value of the Name attribute.
// Error handling has been employed for no-input values.
void inputItemName(string &name){
    do{
        cout << "\t\tItem Name: ";
        getline(cin, name); 

        if(name.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(name.empty());
}

// The inputItemBrand() function asks the user for the value of the Brand attribute.
// Error handling has been employed for no-input values.
void inputItemBrand(string &brand){
    do{
        cout << "\t\tItem Brand: ";
        getline(cin, brand);

        if(brand.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(brand.empty());
}

// The inputItemPrice() function asks the user for the value of the Price attribute.
// Error handling has been employed for no-input values and non-positive floating point values.
void inputItemPrice(float &tempPrice, float &roundedPrice){
	size_t idxCtr;
	char c;
	string tempPriceInput;
	
    do {
        cout << "\t\tItem Price: ";
        getline(cin, tempPriceInput);
        
        // Trims leading and trailing whitespaces
		size_t start = tempPriceInput.find_first_not_of(" \t");
		size_t end = tempPriceInput.find_last_not_of(" \t");
		tempPriceInput = tempPriceInput.substr(start, end - start + 1);
		
		// Attempt to convert the input to a float
        stringstream ss(tempPriceInput);
        
        // Attempts to convert the string into a floating point value.
        if (ss >> tempPrice) {
            // Stores the remaining characters in the input stream
            char leftover;
            
            // Checks if there are excess characters after the converted float
            // No excess character means a valid input.
			if (!(ss >> leftover)) {
                if (tempPrice > 0) {
                    roundedPrice = round(tempPrice * 100.0) / 100.0;
                    cout << endl;
                    break;
                } 
				
				else {
                    cout << "\t\t\tYou entered a non-positive value. Please enter a positive floating point value. " << endl;
                }
            }
            
            else{
            	cout << "\t\t\tYou did not enter a valid floating point value. Please try again. " << endl;
			}
            
        } 
		
		else {
            cout << "\t\t\tYou did not enter a valid floating point value. Please try again. " << endl;
        }

        // Clear any remaining characters in the input stream
        cin.clear();     
    }while(true);
}

// The inputItemQuantity() function asks the user for the value of the Quantity attribute.
// Error handling has been employed for no-input values and non-positive integer values.
void inputItemQuantity(int &quantity){
	string quantityInput;
	
    do {
        cout << "\t\tHow many items are available? ";
        getline(cin, quantityInput);
        
        // Trims leading and trailing whitespaces
        size_t start = quantityInput.find_first_not_of(" \t");
		size_t end = quantityInput.find_last_not_of(" \t");
		quantityInput = quantityInput.substr(start, end - start + 1);
        
        // Attempt to convert the input to an integer
        stringstream ss(quantityInput);
        
        if (ss >> quantity) {
            // Check if there are any remaining characters in the input stream
            char leftover;
            if (!(ss >> leftover)) {
                if (quantity > 0) {
                    cout << endl;
                    break;
                } 
				
				else {
                    cout << "\t\t\tYou entered a non-positive value. Please enter a positive integer value. " << endl;
                }
            } 
			
			else {
                cout << "\t\t\tYou entered a non-integer value. Please enter a positive integer value. " << endl;
            }
        } 		
        
		else {
            cout << "\t\t\tYou did not enter a valid integer value. Please try again. " << endl;
        }

        // Clear any remaining characters in the input stream
        cin.clear();
    } while (true);
}

// The inputItemDescription() function asks the user for the value of the Description attribute.
// Error handling has been employed for no-input values.
void inputItemDescription(string &description){
    do{
        cout << "\t\tItem Description: ";
        getline(cin, description);

        if(description.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(description.empty());
}

// The inputItemColor() function asks the user for the value of the Color attribute.
// Error handling has been employed for no-input values.
void inputItemColor(string &color){
    do{
        cout << "\t\tItem Color: ";
        getline(cin, color);

        if(color.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(color.empty());
}

// The inputItemPrice() function asks the user for the value of the Warranty attribute.
// Error handling has been employed for no-input values and non-positive floating point values.
void inputWarrantyDuration(float &warranty){
    size_t idxCtr;
	char c;
	string tempWarrantyInput;
	
    do {
        cout << "\t\tWarranty Duration (in Years): ";
        getline(cin, tempWarrantyInput);
        
        // Trims leading and trailing whitespaces
        size_t start = tempWarrantyInput.find_first_not_of(" \t");
		size_t end = tempWarrantyInput.find_last_not_of(" \t");
		tempWarrantyInput = tempWarrantyInput.substr(start, end - start + 1);
		
		// Attempt to convert the input to a float
        stringstream ss(tempWarrantyInput);
        
        // Attempts to convert the string into a floating point value.
        if (ss >> warranty) {
            // Stores the remaining characters in the input stream
            char leftover;
            
            // Checks if there are excess characters after the converted float
            // No excess character means a valid input.
			if (!(ss >> leftover)) {
                if (warranty > 0) {
                    cout << endl;
                    break;
                } 
				
				else {
                    cout << "\t\t\tYou entered a non-positive value. Please enter a positive floating point value. " << endl;
                }
            }
            
            else{
            	cout << "\t\t\tYou did not enter a valid floating point value. Please try again. " << endl;
			}            
        } 
		
		else {
            cout << "\t\t\tYou did not enter a valid floating point value. Please try again. " << endl;
        }

        // Clear any remaining characters in the input stream
        cin.clear();     
    }while(true);
}

// The askSpecificClothingDetails() function asks the user for the attribute value specific to this item category.
void askSpecificClothingDetails(string &firstAttrib, string &secondAttrib){
    int tempSize;
    string tempSizeInput, tempMaterial;
    
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|            ENTER SPECIFIC CLOTHING DETAILS               |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    cout << "\t\tClothing Size Options" << endl;
    cout << "\t\t\t[1] 4XS     [5] S     [9]  2XL " << endl;
    cout << "\t\t\t[2] 3XS     [6] M     [10] 3XL " << endl;
    cout << "\t\t\t[3] 2XS     [7] L     [11] 4XL " << endl;
    cout << "\t\t\t[4] XS      [8] XL" << endl << endl;

    // This do-while loop asks for the Clothing Size attribute and 
    // executes the error handling for non-valid inputs.
    do{
        cout << "\t\tSelect Index of Shirt Size: ";
        getline(cin, tempSizeInput);
        
        // Trims leading and trailing whitespaces
        size_t start = tempSizeInput.find_first_not_of(" \t");
		size_t end = tempSizeInput.find_last_not_of(" \t");
		tempSizeInput = tempSizeInput.substr(start, end - start + 1);
        
        // Attempt to convert the input to an integer
        stringstream ss(tempSizeInput);
        
        if (ss >> tempSize) {
            // Check if there are any remaining characters in the input stream
            char leftover;
            if (!(ss >> leftover)) {
                if (tempSize > 0 && tempSize < 12) {
                    firstAttrib = ss.str();
					cout << endl;
                    break;
                } 
				
				else {
                    cout << "\t\t\tYou entered an invalid size code. Please enter a number from 1 to 11value. " << endl;
                }
            } 
			
			else {
                cout << "\t\t\tYou did not enter a valid size code. Please try again. " << endl;
            }
        } 		
        
		else {
            cout << "\t\t\tYou did not enter a valid size code. Please try again. " << endl;
        }

        // Clear any remaining characters in the input stream
        cin.clear();
    }while(true);

    // Parses the tempSize variable to string and stores it as the firstAttrib value.
    

    // This do-while loop asks for the Clothing Mateiral attribute and 
    // executes the error handling for no-input values.
    do{
        cout << "\t\tClothing Material: ";
        getline(cin, tempMaterial);

        if(tempMaterial.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(tempMaterial.empty());

    // Stores the tempMaterial variable as the secondAttrib value.
    secondAttrib = tempMaterial;
}

// The askSpecificClothingDetails() function asks the user for the attribute value specific to this item category.
void askSpecificElectronicsDetails(string &firstAttrib, string &secondAttrib){
    string tempModel, tempTechSpecs;

    // This do-while loop asks for the Electronics Model attribute and 
    // executes the error handling for no-input values.
    do{
        cout << "\t\tElectronics Model: ";
        getline(cin, tempModel);

        if(tempModel.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(tempModel.empty());

    // Stores the tempModel variable as the firstAttrib value.
    firstAttrib = tempModel;

    // This do-while loop asks for the Electronics Technical Specifications
    // attribute and executes the error handling for no-input values.
    do{
        cout << "\t\tElectronics Technical Specifications: " << endl << "\t\t\t";
        getline(cin, tempTechSpecs);

        if(tempTechSpecs.empty())
            cout << "\t\t\tYou entered nothing. Please try again. " << endl << endl;        
    }while(tempTechSpecs.empty());

    // Stores the tempTechSpecs variable as the secondAttrib value.
    secondAttrib = tempTechSpecs;
}

// The setClothingAttributeValues() function sets all the attribute values (both shared and unique) to its specific instance.
void setClothingAttributeValues(Clothing &cloth, string name, string brand, float price, int quantity, string description, 
    string color, char category, float warranty, string size, string material){
        cloth.setName(name);
        cloth.setBrand(brand);
        cloth.setPrice(price);
        cloth.setQuantity(quantity);
        cloth.setDescription(description);
        cloth.setColor(color);
        cloth.setCategory(category);
        cloth.setWarranty(warranty);
        cloth.setSize(size);
        cloth.setMaterial(material);
}

// The setElectronicsAttributeValues() function sets all the attribute values (both shared and unique) to its specific instance.
void setElectronicsAttributeValues(Electronics &electronics, string name, string brand, float price, int quantity, string description, 
    string color, char category, float warranty, string model, string technicalSpecifications){
        electronics.setName(name);
        electronics.setBrand(brand);
        electronics.setPrice(price);
        electronics.setQuantity(quantity);
        electronics.setDescription(description);
        electronics.setColor(color);
        electronics.setCategory(category);
        electronics.setWarranty(warranty);
        electronics.setModel(model);
        electronics.setTechnicalSpecifications(technicalSpecifications);
}

// The printItemDetails() function prints the information collected from the user
// and is formatted by the programmer accordingly. This is a version if the category is Clothing.
void printItemDetails(Clothing clothing){
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                    PRINT ITEM DETAILS                    |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    cout << "\t\tA new item has been saved. Here are its details: " << endl << endl;
    cout << "\t\t\tItem Category: " << clothing.getCategory() << endl << endl;
    
    cout << "\t\t\tClothing Name: " << clothing.getName() << endl;
    cout << "\t\t\tClothing Brand: " << clothing.getBrand() << endl;
    cout << "\t\t\tClothing Price: " << clothing.getPrice() << endl;
    cout << "\t\t\tClothing Available Quantity: " << clothing.getQuantity() << endl;
    cout << "\t\t\tClothing Description: " << clothing.getDescription() << endl;
    cout << "\t\t\tClothing Color: " << clothing.getColor() << endl;
    cout << "\t\t\tClothing Warranty (in Years): " << clothing.getWarranty() << endl << endl;

    cout << "\t\t\tClothing Size: " << clothing.getSize() << endl;;
    cout << "\t\t\tClothing Material: " << clothing.getMaterial() << endl;
}

// The printItemDetails() function prints the information collected from the user
// and is formatted by the programmer accordingly. This is a version if the category is Electronics.
void printItemDetails(Electronics electronics){
    cout << endl;
    cout << "\t------------------------------------------------------------" << endl;
    cout << "\t|                    PRINT ITEM DETAILS                    |" << endl;
    cout << "\t------------------------------------------------------------" << endl;

    cout << "\t\tA new item has been saved. Here are its details: " << endl << endl;
    cout << "\t\t\tItem Category: " << electronics.getCategory() << endl << endl;
    
    cout << "\t\t\tElectronics Name: " << electronics.getName() << endl;
    cout << "\t\t\tElectronics Brand: " << electronics.getBrand() << endl;
    cout << "\t\t\tElectronics Price: " << electronics.getPrice() << endl;
    cout << "\t\t\tElectronics Available Quantity: " << electronics.getQuantity() << endl;
    cout << "\t\t\tElectronics Description: " << electronics.getDescription() << endl;
    cout << "\t\t\tElectronics Color: " << electronics.getColor() << endl;
    cout << "\t\t\tElectronics Warranty (in Years): " << electronics.getWarranty() << endl << endl;

    cout << "\t\t\tElectronics Model: " << electronics.getModel() << endl;;
    cout << "\t\t\tElectronics Technical Specifications: " << electronics.getTechnicalSpecifications() << endl;
}
