// Task Proponents: CASQUEJO, Jann Dave Rhodore G.
// Submitted on: 22 May 2024

// This '.h' file contains all of the class definitions of Product and its child classes Clothing and Electronics.
#include <iostream>

using namespace std;

/* PRODUCT CLASS DEFINITION */
class Product{
    public: // Class Attributes for Product
        string Name;
        string Brand;
        float Price;
        int Quantity;
        string Description;
        string Color;
        string Category;
        float Warranty; 

        // Default Constructor with No Parameters
        Product(){}

        // Constructor with Parameters
        Product(string name, string brand, float price, int quantity, 
        string description, string color, string category, float warranty){
            Name = name;
            Brand = brand;
            Price = price;
            Quantity = quantity;
            Description = description;
            Color = color;
            Category = category;
            Warranty = warranty;
        }

        // Setter Member Methods
        // Sets the value of a specific class attribute
        void setName(string name){ Name = name; }
        void setBrand(string brand){ Brand = brand; }
        void setPrice(float price){ Price = price; }
        void setQuantity(int quantity){ Quantity = quantity; }
        void setDescription(string description){ Description = description; }
        void setColor(string color){ Color = color; }
        void setCategory(char category){
            switch(category){
                case 'C': case 'c': Category = "Clothing"; break;
                case 'E': case 'e': Category = "Electronics"; break;
                default: Category = "Invalid Category"; break;
            }
        }
        void setWarranty(float warranty){ Warranty = warranty; }
        
                
        // Getter Member Methods
        // Gets the value of a specific attribute in a specific class instance
        string getName(){ return Name; }
        string getBrand(){ return Brand; }
        float getPrice(){ return Price; }
        int getQuantity(){ return Quantity; }
        string getDescription(){ return Description; }
        string getColor(){ return Color; }
        string getCategory(){ return Category; }
        float getWarranty(){ return Warranty; }
};
/* END PRODUCT CLASS DEFINITION */



/* CLOTHING CLASS DEFINITION */
class Clothing: public Product{
    private: // Specific Class Attributes for Clothing
        string Size;
        string Material;    
    public:
        // Default Constructor with No Parameters
        // Calls the Product class initializer with no parameters and 
        // appends the initialization of Size and Material attributes.
        Clothing(): Product(){}

        // Constructor with Parameters
        // Calls the Product class initializer with parameters and
        // appends the initialization of Size and Material attributes.
        Clothing(string name, string brand, float price, int quantity, string description, 
        string color, string category, float warranty, string size, string material):            
            Product(name, brand, price, quantity, description, color, category, warranty){ 
                Size = size; 
                Material = material;
        }    

        // Unique Setter Member Methods for Clothing class
        void setSize(string size){
            if (size == "1") Size = "4XS";
            else if (size == "2") Size = "3XS";
            else if (size == "3") Size = "2XS";
            else if (size == "4") Size = "XS";
            else if (size == "5") Size = "S";
            else if (size == "6") Size = "M";
            else if (size == "7") Size = "L";
            else if (size == "8") Size = "XL";
            else if (size == "9") Size = "2XL";
            else if (size == "10") Size = "3XL";
            else if (size == "11") Size = "4XL";
            else Size = "Invalid Size";               
        }
        void setMaterial(string material){ Material = material; }
        

        // Unique Getter Member Methods for Clothing class
        string getSize(){ return Size; }
        string getMaterial(){ return Material; }
};
/* END CLOTHING CLASS DEFINITION */



/* ELECTRONIC CLASS DEFINITION */
class Electronics: public Product{
    private: // Specific Class Attributes for Electronics
        string Model;
        string TechnicalSpecifications;
    public:
        // Default Constructor with No Parameters
        // Calls the Product class initializer with no parameters and 
        // appends the initialization of Model and TechnicalSpecifications attributes.
        Electronics(){}

        // Constructor with Parameters
        // Calls the Product class initializer with parameters and
        // appends the initialization of Model and TechnicalSpecification attributes.
        Electronics(string name, string brand, float price, int quantity, string description, 
        string color, string category, float warranty, string model, string techSpecs):
            Product(name, brand, price, quantity, description, color, category, warranty){
                Model = model;
                TechnicalSpecifications = techSpecs;
        }

        // Unique Setter Member Methods for Electronics class
        void setModel(string model){ Model = model; }
        void setTechnicalSpecifications(string techSpecs){ TechnicalSpecifications = techSpecs; }
        

        // Unique Setter Member Methods for Electronics class
        string getModel(){ return Model; }
        string getTechnicalSpecifications(){ return TechnicalSpecifications; }
};
/* END OF ELECTRONIC CLASS DEFINITION */



