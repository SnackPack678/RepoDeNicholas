//
//  menu.h
//  TaskManager-Midterm
//
//  Created by Nicholas Rubio on 7/11/25.
//

#ifndef MENU_H // prevents multiple inclusions
#define MENU_H

#include <iostream>
using namespace std;

inline void menu(){
    cout << "\t\t- Menu -\n\n"
    << "1. Welcome Message\n\n"
    << "2. Create Task\n"
    << "3. Rename Task\n"
    << "4. Reset Task Description\n"
    << "5. Reset Task Priority Level\n\n"
    
    << "6. Delete Task\n\n"
    << "7. Display All Tasks (Generally)\n"
    << "8. Display All Tasks (Priority-based)\n"
    << "9. Search for a Task by Name\n\n"
    << "10. Save session\n\n"
    << "11. Quit\n\n";
}
#endif
