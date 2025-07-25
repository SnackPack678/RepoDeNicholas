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
    cout << "\t▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n";
    cout << "\t▶\t\t\t\t  ▶ MENU ◀     \t\t\t   ◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n"
    << "\t▶\t1. Welcome Message\t\t\t\t\t   ◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n"
    << "\t▶\t2. Create Task\t\t\t\t\t\t   ◀\n"
    << "\t▶\t3. Rename Task\t\t\t\t\t\t   ◀\n"
    << "\t▶\t4. Reset Task Description\t\t\t   ◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n"
    << "\t▶\t5. Reset Task Priority Level\t\t   ◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n"
    
    << "\t▶\t6. Delete Task\t\t\t\t\t\t   ◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n"
    << "\t▶\t7. Display All Task Names\t\t\t   ◀\n"
    << "\t▶\t8. Search Name (Get all info)(BinSrch) ◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n"
    << "\t▶\t9. Save session\t\t\t\t\t\t   ◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n"
    << "\t▶\t10. Quit\t\t\t\t\t\t\t   ◀\n\t▶\t\t\t\t\t\t\t\t\t\t   ◀\n";
}
#endif

