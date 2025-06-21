/*
 
 Topics: Data sizes, file types, character escape sequences, cost, "Hello World" program
 
 Instructions: Write a simple C++ program named hello_inventory.cpp that:
 
 • Prints "Hello Inventory System!"
 • Demonstrates use of escape characters (\n, \t)
 • Outputs sizes of int, float, and char
 
 */

#include <iostream>
using namespace std;

int main(){
    cout << "\t - Hello Inventory System! - " << endl; // • Prints "Hello Inventory System!" + \t escape character
    cout << "Size of an int: " << sizeof(int) << " bytes";            // • sizeof(int)
    cout << "\nSize of a float: " << sizeof(float) << " bytes";       // • sizeof(float) + \n escape character
    cout << "\nSize of a char: " << sizeof(char) << " bytes" << endl; // • sizeof(char) + \n escape character
}
