/* ▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀
 
 TODO: My Program Description - Explain Logic and File Structure
 
 • The program has a "dataReader" class which handles file input logic.
 • "Main" starts off by creating a dataReader object, called "test"
 • "test" then calls it's method readFile(); test.readFile() flows as such:
 
 1.) Loads the input file "world_air_quality_with_locations.csv" using an absoutle file path (local machine)
 2.) if input file is unsuccessful in opening: print error message (rest of code doesn't execute)
 
    3.) else: print success message, legend message
    4.) The program loops through the input file, skips the first field (which is the row number or ID)
    5.) Prints up to 5 fields per row for 10 rows max.
    6.) After reading the specified rows and fields, the input file is closed
    7.) Print "file closed" message
 
▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀ */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class dataReader{
public:
    
    dataReader(){}
    
    void readFile(){
        ifstream inFile("/Users/nicholasrubio/Downloads/world_air_quality_with_locations.csv");
        
        if (!inFile.is_open()) { cout
            << "\n▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀\n"
            << "          *** ERROR: File not open! ***"
            << "\n▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀\n";
        } else { cout
            << "\n▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀\n"
            << "          *** SUCCESS: File opened! ***"
            << "\n▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀\n";
            
            
            string line;
            
            if (getline(inFile, line)) {
                cout << "\n\t\t\t\t*** HEADERS ***\n"
                << "\t\t\tCountry Code = FIELD 1\n"
                << "\t\t\tCity         = FIELD 2\n"
                << "\t\t\tLocation     = FIELD 3\n"
                << "\t\t\tLatitude     = FIELD 4\n"
                << "\t\t\tLongitude    = FIELD 5\n"
                << "\n*** Disclaimer: Information missing? Data unprovided.\n";
            }
            
            int rowCount = 0;
            
            while (getline(inFile, line) && rowCount < 10) {
                istringstream iss(line);
                
                string field;
                getline(iss, field, ',');
                
                cout << "\n\t=== ROW " << (rowCount + 1) << " ===" << endl;
                
                int fieldCount = 0;
                
                while (getline(iss, field, ',') && fieldCount < 5) {
                    cout << "\tFIELD " << (fieldCount + 1) << ": " << field << endl;
                    ++fieldCount;
                    
                } // INNER while loop
                ++rowCount;
            } // OUTTER while loop
            
            inFile.close();
            { cout
                << "\n▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀\n"
                << "              *** File closed ***"
                << "\n▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀\n";
            }
        } // END OF ELSE
    }
};

int main(){
    dataReader test;
    test.readFile();
    cout << endl;
    return 0;
}
