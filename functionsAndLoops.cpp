
/*
 
 Topics: Functions, header files, loops
 Instructions: Refactor menu using functions.
 
 Example:
 
 void showMenu() {
 
 cout << "1. Add\n2. View\n3. Exit\n";
 }
 int main() {
     int option;
     do {
         showMenu();
         cin >> option;
     } while (option != 3);
     return 0;
 }

 */


 #include <iostream>
 #include <string>
 using namespace std;

 void addItem() {
     string itemName;
     cout << "\n\t\t\t\t\t===\t===\t===\t===\t===" << endl;
     cout << "\n\t\t\t\t\t- Add Item Menu -" << endl;
     cout << "\n\t\t\t\t\tEnter Item Name: ";
     cin >> itemName;
     cout << "\n\t\t\t\t\t" << itemName << " - has been added!" << endl;
     cout << "\n\t\t\t\t\t===\t===\t===\t===\t===" << endl;
 }

 void displayItems(){
     cout << "\n\t\t\t\t\t===\t===\t===\t===\t===" << endl;
     cout << "\n\t\t\t\t\t- Display Item Menu -" << endl;
     cout << "\n\t\t\t\t\tItem 1.) abc\n";
     cout << "\t\t\t\t\tItem 2.) def\n";
     cout << "\t\t\t\t\tItem 3.) ghi\n";
     cout << "\n\t\t\t\t\t===\t===\t===\t===\t===" << endl;

 }

 int main() {

     short checkpoint = 0;
     short temp = 0;

     while (checkpoint == 0) {

         int choice;
         cout << "***\t***\t***\t***\t***" << endl;
         cout << "1. Add Item\n2. View Items\n3. Exit\n";
         cout << "***\t***\t***\t***\t***" << endl;

         cout << "Choose an option: ";
         cin >> choice;

         if (choice == 1) {
             addItem();
             cout << "\t\t\t\t\tExit program?(1,0): ";
             cin >> temp;
             cout << endl;
             if (temp == 1) {
                 checkpoint = 1;
             }
         }

         else if (choice == 2) {
             displayItems();
             cout << "\t\t\t\t\tExit program?(1,0): ";
             cin >> temp;
             cout << endl;
             if (temp == 1) {
                 checkpoint = 1;
             }
         }

         else if (choice == 3) {
             checkpoint = 1;
         }
         
         else {
             cout << "\n\t\t\t\t\t!!! Invalid input !!!\n" << endl;
         }

     } // end of while loop
     return 0;
 } // end of main

