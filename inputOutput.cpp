/*
 Topics: cin, software variables, naming conventions
 
 Instructions: Create a program that:
 
 • Accepts user input for item name, quantity, and cost
 • Calculates and displays the total cost

 */

#include <iostream>
#include <string>
using namespace std;

void calculate(string itemName, int quantity, float cost){
    cout << "\n***\t***\t***\t***\t***\t***\t***\t***\t***\t***";
    cout << "\n\t- Calculated Cost | Breakdown - \n" << endl;
    cout << "Item name: " << itemName << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "-------------------" << endl;
    cout << "Cost: $" << quantity * cost << endl;
    cout << "***\t***\t***\t***\t***\t***\t***\t***\t***\t***";

}

int main(){
    string itemName;
    int quantity;
    float cost;
    
    cout << "Enter name/number when prompted: " << endl;
    
    cout << "\nItem name: ";
    cin >> itemName;
    
    cout << "Quantity: ";
    cin >> quantity;
    
    cout << "Cost: ";
    cin >> cost;
    
    calculate(itemName, quantity, cost);
    cout << endl;
    return 0;
}
