/*
 
 Instructions:
 
 • Define a struct named Item with two members: name (string) and id (int). ✅
 • Use new to dynamically allocate an array of items. ✅
 • Populate the array with sorted sample data (sorted by id). ✅
 • Implement a binary search function to find an item by id. ✅
 • Ask the user for an ID to search for, and display the result. ✅
 • Free the memory using delete[].✅

 */

#include <iostream>
#include <string>
using namespace std;

struct Item{
    int id;
    string name;
};

int binarySearch(Item items[], int size, int targetID) {  // finds a specific value within a sorted list or array | divides
    
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculating midpoint
        
        if (items[mid].id == targetID) {
            return mid; // Target found, return its index
        } else if (items[mid].id < targetID) {
            low = mid + 1; // Target is in the right half
        } else {
            high = mid - 1; // Target is in the left half
        }
    }
    return -1; // -1 if not found
}

int main(){
    int check = 1;
    while (check == 1){
        
        Item* items = new Item[3];
        items[0] = {1, "Nicholas"};
        items[1] = {2, "Carol"};
        items[2] = {3, "David"};
        
        int size = 3;
        int id;
        
        cout << "\nEnter an ID (1-3): ";
        cin >> id;
        
        int index = binarySearch(items, size, id);
        
        if (index != -1) {
            cout << "\n\t- ID " << id << " -\n• Name: " << items[index].name << " \n• Index: " << index << endl << endl;
        } else {
            cout << "\n*** ERROR! That ID does not exist in list! ***\n" << endl;
        }
        
        delete[] items; // Free the dynamically allocated memory
        
        cout << "Check another ID?\n1 = yes | 0 = no ... ";
        cin >> check;
        while (check != 1 && check != 0){
            cout << "\n*** ERROR! Please enter 1 or 0 ... ";
            cin >> check;
        }
        cout << "\n******************************************" << endl;
    }
    
    cout << endl;
    return 0;
}
