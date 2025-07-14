//
//  item.h
//  organizingCodeWithHeaderFiles
//
//  Created by Nicholas Rubio on 7/13/25.
//


#pragma once

#include <string>
using namespace std;

class Item {
private:
    string name;
    int quantity;

public:
    Item();
    Item(string itemName, int itemQty);
    void display();
};



