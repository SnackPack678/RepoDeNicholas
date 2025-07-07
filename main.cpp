
/*
 Instructions:
 
 TODO: Create a class called Item with:
 
 • string name
 • int quantity
 
 TODO: In main():
 
 • Create an array of Item objects (e.g., size 5)
 • Ask the user to enter the name and quantity for each item
 • Display all items in the inventory using a loop
 
 TODO: Add a function to:
 • Search for an item by name
 • Display its quantity if found
 
 */

#include <iostream>
using namespace std;

class Item{
public:
    string name;
    int quantity;
    
    void getNameAndQuantity(){
        cout << this->name << " - "<< this->quantity << endl;
    }
};

void searchItemByName(Item items[], int length, string targetName) {
    bool found = false;
    for (int i = 0; i < length; i++) {
        if (items[i].name == targetName) {
            cout << "Item found: ";
            items[i].getNameAndQuantity();
            found = true;
        }
    }
    if (!found)
        cout << "\nItem: " << targetName << " ... not found!" << endl;
}

int main(){
    
    Item items[5];
    float j = 1;
    
    cout << "\n\t- Enter the NAME & QUANTITY for 5 items -" << endl;
    for (Item& i : items){
        cout << "\nItem #" << j << ": ";
        cin >> i.name;
        cout << "Quantity: ";
        cin >> i.quantity;
        j++;
    }
    
    cout << endl;
    
    
    
    int length = sizeof(items) / sizeof(items[0]);
    cout << "******************************" << endl;
    cout << " ***** Item information *****  \n" << endl;
    for (int i = 0; i < length; i++)
        items[i].getNameAndQuantity();
    cout << "\n******************************" << endl;
    
    
    bool check = true;
        string searchName;
        cout << "\n*****************************" << endl;
        cout << " ******* Item Search *******  \n" << endl;
    while (check){
        cout << "\nEnter the name of an item to search: ";
        cin >> searchName;
        searchItemByName(items, length, searchName);
        cout << " --- Search for another item? Enter 0/1: ";
        cin >> check;
    }
    cout << "\n******************************" << endl;
    
    cout << endl;
    return 0;
}
