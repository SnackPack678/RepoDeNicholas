/*
 
 Instructions:
 
 • Create an abstract class called Item with a pure virtual function display().
 
 • Create two classes that inherit from Item:
    º Perishable – override display() to print "Perishable
    º NonPerishable – override display() to print "Non-Perishable Item"
 
 • In main(), use a pointer to the base class Item to call display() on both derived objects.

 */


#include <iostream>
using namespace std;

// -------------------------------------------------------------------

// Base class
class Item {
public:
    string name;
    int quantity;

    Item(string n, int q) {
        name = n;
        quantity = q;
    }
    
    virtual ~Item() {}  // <-- Need this line to delete virtual items


    virtual void display() = 0; // Pure virtual function
};

// -------------------------------------------------------------------

// Perishable item
class Perishable : public Item {
public:
    Perishable(string n, int q) : Item(n, q) {}

    void display() override {
        cout << name << " (Perishable), Qty: " << quantity << endl;
    }
};

// -------------------------------------------------------------------

// Non-Perishable item
class NonPerishable : public Item {
public:
    NonPerishable(string n, int q) : Item(n, q) {}

    void display() override {
        cout << name << " (Non-Perishable), Qty: " << quantity << endl;
    }
};

// -------------------------------------------------------------------

int main() {
    // Create inventory using base class pointers
    Item* item1 = new Perishable("Milk", 10);
    Item* item2 = new NonPerishable("Cereal", 20);

    item1->display();
    item2->display();

    // Clean up
    delete item1;
    delete item2;

    return 0;
}
