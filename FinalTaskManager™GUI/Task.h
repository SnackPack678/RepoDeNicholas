#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
using namespace std;


class Task {
public:
    string taskName = "No title";
    string description = "No description";
    short priorityLevel = 0;
    
    Task(){};
    
    Task(string tn, string d, short pl){
        taskName = tn;
        description = d;
        priorityLevel = pl;
        cout << "\n▶▶▶▶ Task(string, string, short) created successfully ◀◀◀◀" << endl;
    }
    
    // The createTask method creates a new Task by collecting valid input from the user.
    // It ensures that the title, description, and priority level meet specific constraints.
    void createTask(){
        
        string name, desc;
        short pri = 0;
        
        cout << "\n\t\t\t\t\t▶ NEW TASK ◀ \n" << endl;
        cout << "\t   ▶▶▶ Please enter the following data ◀◀◀\n" << endl;
        
        while (name.length() > 20 || name.empty()) {
            cout << "\nEnter Title (20 Characters or Less): ";
            getline(cin, name);
            
            if (name.length() > 20) {
                cout << "\n\t\t  ▶▶▶ ERROR: TITLE MUST BE 20 CHARACTERS OR LESS ◀◀◀\n\n";
            } else if (name.empty()) {
                cout << "\n\t\t  ▶▶▶ ERROR: TITLE CANNOT BE EMPTY ◀◀◀\n\n";
            }
        }
        
        while (desc.length() > 75 || desc.empty()) {
            cout << "\nEnter Description (75 Characters or Less): ";
            getline(cin, desc);
            
            if (desc.length() > 75) {
                cout << "\n\t\t  ▶▶▶ ERROR: DESCRIPTION MUST BE 75 CHARACTERS OR LESS ◀◀◀\n\n";
            } else if (desc.empty()) {
                cout << "\n\t\t  ▶▶▶ ERROR: DESCRIPTION CANNOT BE EMPTY ◀◀◀\n\n";
            }
        }
        
        while (pri >= 11 || pri <= 0){
            cout << "\nPriorty level (1-10): ";
            cin >> pri;
            cin.ignore();
            
            if (pri >= 11 || pri <= 0){
                cout << "\n▶▶▶ ERROR: PRIORITY LEVEL MUST BE WITHIN RANGE (1-10) ◀◀◀\n\n";
            }
        }
        // Once all input is valid, set the member variables of the Task.
        taskName = name;
        description = desc;
        priorityLevel = pri;
        
        // Confirm successful creation of the task.
        cout << "\n\n\t\t   ▶▶▶ TASK SUCCESSFULLY CREATED ◀◀◀\n\n"
        << "██████████████████████████████████████████████████████████████████\n" << endl;
    }
    
    string getTaskName()const{return taskName;}    // getter for Task Name
    string getTaskDesc()const{return description;} // getter for Task Description
    short getTaskPri()const{return priorityLevel;} // getter for Task Priority Level
    
    
    
    // The renameTask method renames a preexisting Task name by collecting valid input from the user.
    // It ensures that the new name meets specific constraints before overwriting.
    void renameTask(){
        string newName;
        string oldName = getTaskName();
        while (true) {
            cout << "\n\tEnter new name: ";
            getline(cin, newName);
            if (newName.length() > 20) {
                cout << "\n\t\t  ▶▶▶ ERROR: TITLE MUST BE 20 CHARACTERS OR LESS ◀◀◀\n\n";            // length check + null/empty check
            } else if (newName.empty()) {
                cout << "\n\t\t  ▶▶▶ ERROR: TITLE CANNOT BE EMPTY ◀◀◀\n\n";
            } else {
                break;
            }
        }
        // Set and confirm for user
        taskName = newName;
        cout << "\n\t\t  ▶▶▶ TASK NAME SUCCESSFULLY CHANGED ◀◀◀\n\n"
        << "\t\t\t• New = " << taskName << "\t█\t• Previous = " << oldName
        << "\n\n██████████████████████████████████████████████████████████████████\n" << endl;
    }
    
    // The renameDesc method overwrites a preexisting Task description by collecting valid input from the user.
    // It ensures that the new description meets specific constraints before overwriting.
    void renameDesc(){
        string newDesc;
        string oldDesc = getTaskDesc();
        while (true) {
            cout << "\n\tEnter new Description: ";
            getline(cin, newDesc);
            if (newDesc.length() > 75) {
                cout << "\n\t\t  ▶▶▶ ERROR: DESCRIPTION MUST BE 75 CHARACTERS OR LESS ◀◀◀\n\n";  // length check + null/empty check
            } else if (newDesc.empty()) {
                cout << "\n\t\t  ▶▶▶ ERROR: DESCRIPTION CANNOT BE EMPTY ◀◀◀\n\n";
            } else {
                break;
            }
        }
        // Set and confirm for the user
        description = newDesc;
        cout << "\n\n\t\t  ▶▶▶ TASK DESCRIPTION SUCCESSFULLY CHANGED ◀◀◀\n\n"
        << "\t New = " << newDesc << "\n\n\t Previous = " << oldDesc
        << "\n\n██████████████████████████████████████████████████████████████████\n" << endl;
        
    }
    
    // The resetPriLvl method resets a preexisting Task Priority Level by collecting valid input from the user.
    // It ensures that the new priority meets specific constraints before overwriting.
    void resetPriLvl(){
        short newPriLvl = 0;
        short oldPriLvl = getTaskPri();
        
        while (newPriLvl < 1 || newPriLvl > 10) {
            cout << "\n\tEnter new Priority level (1-10): ";
            cin >> newPriLvl;
            cin.ignore();
            
            if (newPriLvl < 1 || newPriLvl > 10) {
                cout << "\n\t ▶▶▶ PRIORITY LEVEL MUST BE WITHIN RANGE (1-10) ◀◀◀\n";
            }
        }
        // Set and confirm for the user
        priorityLevel = newPriLvl;
        cout << "\n\t\t  ▶▶▶ PRIORITY LEVEL SUCCESSFULLY CHANGED ◀◀◀\n\n"
        << "\t\t\t     New = " << newPriLvl << "\t█  Previous = " << oldPriLvl
        << "\n\n██████████████████████████████████████████████████████████████████\n" << endl;
    }
};

#endif
