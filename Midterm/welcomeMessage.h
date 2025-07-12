//
//  welcomeMessage.h
//  TaskManager-Midterm
//

#ifndef WELCOMEMESSAGE_H // prevents multiple inclusions
#define WELCOMEMESSAGE_H

#include <iostream>
using namespace std;

inline void welcomeMessage(){
    cout << "\n\t\t\t\t\t\t\tWelcome to TaskManager™!\n\n"
            << "In this console-based to-do-list, you can store and manage up to FIVE tasks at a time!\n\n"
            << "As a user, your privileges include:\n\n"
            << "• Creating a task\n"
            << "• Deleting a task\n"
            << "• Renaming a task\n"
            << "• Redescribing a task\n"
            << "• Resetting a task's priorty level\n\n"
            << "Features include:\n\n"
            << "• Display all tasks\n"
            << "• Filter tasks by name (Binary Search)\n"
            << "• Save TaskManager™ sessions\n\n"
            << "*** Be advised: Every session with TaskManager™ will be saved to a text document for your convenience!"
            << "\n\n******************************************************************\n\n";
}
#endif
