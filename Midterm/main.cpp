/*
 
 TODO: OBJECTIVE:
 
 Design and build a C++ program of your choice that demonstrates your understanding of core programming concepts covered so far. You'll apply a variety of tools and techniques including:
 
 • Pointers
 • Dynamic memory
 • Binary search
 • File I/O
 • Classes
 
 This project gives you the freedom to choose your program idea, as long as it meaningfully applies the required concepts.
 
 -----------------------------------------------------------------------------------------------------------------------------------
 
 TODO: Your Midterm Must Include:
 
 • Data types and data sizes
 • File types (e.g., .txt for data I/O)
 • Use of pointers
 • arrays
 • A binary search algorithm (on any other search)
 • Use of strings
 • File I/O (read from or write to a file)
 • At least two classes (with meaningful interaction)
 
 -----------------------------------------------------------------------------------------------------------------------------------

 TODO: output.pdf Must Contain:
 
 • A brief explanation of your program (what it does, how it works)
 • A list of concepts used (from the list above)
 • Screenshots of your program running (showing all program screens, such as input prompts, output results, etc.)
 • Mention any challenges you faced and how you solved them
 
 -----------------------------------------------------------------------------------------------------------------------------------
 
 TODO: My Project Description:
 
console-based to-do list where a user can:

 • Add tasks (title, description, priority) ✅
 • Sort tasks by priority.
 • Search tasks by title using binary search (sorted alphabetically).
 • Save/load tasks to/from a file.
 • Store tasks dynamically.
 
Key concepts covered:
 
 • Classes: Task ✅ and ToDoList.
 • Dynamic memory: Add tasks dynamically.
 • Pointers: Manage tasks with pointers or use a pointer-based linked list.
 • Binary search: Find tasks by title or ID.
 • File I/O: Save tasks so they persist.
 
 
 * Classes: Task and ToDoList.
 
 * Header Files ✅

 * Dynamic memory: Add tasks dynamically.

 * Pointers: Manage tasks with pointers or use a pointer-based linked list.

 * Binary search: Find tasks by title or ID.

 * File I/O: Save tasks so they persist.

 */

#include <iostream>
#include <string>
using namespace std;

class Task {
public:
    string taskName = "No title";
    string description = "No description";
    short priortyLevel = 0;
    
    Task(){
        //cout << "\n**** Task() created successfully ****" << endl;
    };
    
    Task(string tn, string d, short pl){
        taskName = tn;
        description = d;
        priortyLevel = pl;
        cout << "\n**** Task(string, string short) created successfully ****" << endl;
    }
    
    void createTask(){
        
        string name, desc;
        short pri = 0;
        
        cout << "\n\t\t\t\t\t- New Task - \n" << endl;
        cout << "\t   *** Please enter the following data ***\n" << endl;
        
        while (name.length() > 20 || name.empty()) {
            cout << "\nEnter Title (20 Characters or Less): ";
            getline(cin, name);

            if (name.length() > 20) {
                cout << "--- ERROR: Title must be 20 characters or less." << endl;
            } else if (name.empty()) {
                cout << "--- ERROR: Title cannot be empty." << endl;
            }
        }
        
        while (desc.length() > 75 || desc.empty()) {
            cout << "\nEnter Description (75 Characters or Less): ";
            getline(cin, desc);

            if (desc.length() > 75) {
                cout << "--- ERROR: Description must be 75 characters or less." << endl;
            } else if (desc.empty()) {
                cout << "--- ERROR: Description cannot be empty." << endl;
            }
        }

        while (pri >= 11 || pri <= 0){
            cout << "\nPriorty level (1-10): ";
            cin >> pri;
            
            if (pri >= 11 || pri <= 0){
                cout << "--- ERROR: Priority level must be within range (1-10)" << endl;
            }
        }
            
        cout << "\n\t\t\t\t - Task Breakdown - \n" << endl;
        cout << "Task: " << name << " | Priorty Level: " << pri << endl;
        cout << "\nDescription: " << desc << endl;
        cout << "\n******************************************************************" << endl;
    }
    
    void renameTask(){
        string newName;
        string oldName = taskName;
        cout << "\nEnter new name: ";
        getline(cin, newName);
        cout << endl;
        taskName = newName;
        cout << "\nSuccessfully changed Task Name!\n"
        << "New = " << taskName << " | Previous = " << oldName << endl;
    }
        
};



#include <fstream>
#include "menu.h"
#include "welcomeMessage.h"

int main(){
        
    const short MAX = 5;
    Task taskList[MAX];
    
    menu();
    
    short num = 1;
    cout << "*** Enter a number: ";
    cin >> num;
    
    while (num <= 0 || num >= 11){
        cout << "--- ERROR: Entry must be 1-10!" << endl;
        cout << "\n*** Enter a number: ";
        cin >> num;
    }
    
    cout << "\n******************************************************************" << endl;

    
    switch (num){
        case 1:
            welcomeMessage();
            break;
        case 2:
            taskList[0].createTask();
            break;
        case 3:
            taskList[0].renameTask();
            break;
        case 4:
            //4
            break;
        case 5:
            //5
            break;
        case 6:
            //6
            break;
        case 7:
            //7
            break;
        case 8:
            //8
            break;
        case 9:
            //9
            break;
        case 10:
            //10
            break;
        case 11:
            //11
            break;
    }
    cout << endl;
}

