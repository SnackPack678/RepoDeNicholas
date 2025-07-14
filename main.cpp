//
//  main.cpp
//  organizingCodeWithHeaderFiles
//
//  Created by Nicholas Rubio on 7/13/25.
//

#include <iostream>
#include "Item.h"

Item::Item() {
    name = "Unknown";
    quantity = 0;
}

Item::Item(string itemName, int itemQty) {
    name = itemName;
    quantity = itemQty;
}

void Item::display() {
    cout << "Item: " << name << ", Quantity: " << quantity << endl;
}

using namespace std;

int main() {
    Item item1("Notebook", 10);
    Item item2("Pencil", 50);

    item1.display();
    item2.display();

    return 0;
}



