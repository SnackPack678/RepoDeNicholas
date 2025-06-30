
/*
 
 Instructions:
 
 Create a class Item with:
 • string name ✅
 • int quantity ✅
 • A method saveToFile() to write item data in the format: name,quantity ✅
 • (Optional) A method loadFromFile() to read and display data from the file 🍎
 
 In your main() function:
 • Create an instance of Item ✅
 • Assign values to its members ✅
 • Call saveToFile() to write the data to a file called items.txt ✅
  
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// -------------------------------------------------------------------

class item {
public:
    string name;
    int quantity;
    
    void saveToFile(){
        ofstream out("items.txt");
        if (out.is_open()){
            cout << name << ", " << quantity << endl;
            out.close();
            cout << "item successfully saved to file!\n" << endl;
        } else {
            cout << "Error! File failed to open!\n" << endl;
        }
    }
};

// -------------------------------------------------------------------

void loadFromFile(){
    ifstream in("items.txt");
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
                       cout << "File content: " << line << endl;
                   }
                   in.close();
               } else {
                   cout << "Unable to open file for reading.\n" << endl;
               }
};

// -------------------------------------------------------------------

int main() {
   item tool;
   tool.name = "Screwdriver";
   tool.quantity = 10;
    tool.saveToFile();

    
    item tool2;
    tool2.name = "Hammer";
    tool2.quantity = 5;
   tool2.saveToFile();
    
    item tool3;
    tool3.name = "Wrecking ball";
    tool3.quantity = 11;
   tool3.saveToFile();
    
    item tool4;
    tool4.name = "Saw";
    tool4.quantity = 8;
   tool4.saveToFile();
 
   return 0;
}

