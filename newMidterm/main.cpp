/* ▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀
 
 TODO: My Project Description:
 
console-based to-do list where a user can:
 
 • Load a previous session

 • Open a Welcome message that describes what the user can do
 • Create Tasks (title, description, priority) ✅
 • Rename Tasks
 • Reset Task Description .
 • Reset Task Priority Level
 • Delete Tasks
 • Display All Tasks (Generally)
 • Search for a Task by Name
 • Save session
 • Quit session
  
 TODO: Key concepts covered:

  • Classes: ✅ Uses a single main class (Task) to model tasks.
  • Header Files: ✅ Uses separate header files for the menu and welcome message.
  • Dynamic Task Array: ✅ Uses a fixed-size array to store up to 5 tasks dynamically at runtime.
  • Binary Search: ✅ Can search for a task by name using a binary search after sorting.
  • File I/O: ✅ Saves tasks to a custom .txt file and loads them back in at startup.
  
  BONUS:
  • Input Validation: ✅ Validates user input for task creation, edits, deletes.
  • Sorting: ✅ Sorts tasks by name to fulfill binary search requirements.
  • Basic Console UI: ✅ Provides a simple menu system for user interaction.
  • Optional File Path Output: ✅ User is given the direct file path to .txt file (Option 9)
 
 ▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀ */

#include <iostream>
#include <string>
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
            cin.ignore();
            
            if (pri >= 11 || pri <= 0){
                cout << "--- ERROR: Priority level must be within range (1-10)" << endl;
            }
        }
        
        taskName = name;
        description = desc;
        priorityLevel = pri;
        
        cout << "\n\t\t\t\t - Task Breakdown - \n" << endl;
        cout << "Task: " << name << " | Priorty Level: " << pri << endl;
        cout << "\nDescription: " << desc << endl;
        cout << "\n******************************************************************" << endl;
    }
    
    
    string getTaskName()const{return taskName;}
    string getTaskDesc()const{return description;}
    short getTaskPri()const{return priorityLevel;}
    
    
    void renameTask(){
        string newName;
        string oldName = getTaskName();
        cout << "\n\tEnter new name: ";
        getline(cin, newName);
        taskName = newName;
        cout << "\t*** Successfully changed Task Name!\n\n"
        << "\t• New = " << taskName << "\n\n\t• Previous = " << oldName
        << "\n\n******************************************************************\n" << endl;
    }
    
    void renameDesc(){
        string newDesc;
        string oldDesc = getTaskDesc();
        cout << "\n\tEnter new Description: ";
        getline(cin, newDesc);
        description = newDesc;
        cout << "\t*** Successfully changed Task Description!\n\n"
        << "\t• New = " << description << "\n\n\t• Previous = " << oldDesc
        << "\n\n******************************************************************" << endl;
        
    }
    
    void resetPriLvl(){
        
        short newPriLvl = 0;
        short oldPriLvl = getTaskPri();
        
        while (newPriLvl < 1 || newPriLvl > 10) {
            cout << "\n\tEnter new Priority level (1-10): ";
            cin >> newPriLvl;
            cin.ignore();
            
            if (newPriLvl < 1 || newPriLvl > 10) {
                cout << "--- ERROR: Priority level must be within range (1-10)" << endl;
            }
        }
        priorityLevel = newPriLvl;
        cout << "\t*** Successfully changed Task Priority Level!\n\n"
        << "\t• New = " << priorityLevel << "\n\n\t• Previous = " << oldPriLvl
        << "\n\n******************************************************************" << endl;
    }
    
};

// ----------------------------------------------------------------------------------------

int binarySearch(Task arr[], int size, string target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].getTaskName() == target) {
            return mid;
        } else if (arr[mid].getTaskName() < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void sortTasksByName(Task arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].getTaskName() > arr[j + 1].getTaskName()) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ----------------------------------------------------------------------------------------

#include <fstream>
#include "menu.h"
#include "welcomeMessage.h"

int main(){
    
    const short MAX = 5;
    Task taskList[MAX];
    
    short taskCount = 0;
    short num = 0;
    short ask = 0;
    
    
    cout << "\nLoad a previous file? (0/1): ";
    cin >> ask;
    cin.ignore();
    
    if(ask == 1){
        string filename = "";
        cout << "\n\t*** Enter the name of the file: ";
        getline(cin, filename);
        
        ifstream inFile(filename);
        
        if(!inFile){
            cout << "\n\t--- ERROR: Could not open file! ---\n";
        } else {
            string name, desc, line;
            short pri;
            while (getline(inFile, line)) {
                if (line.find("Name: ") == 0) {
                    name = line.substr(6);
                } else if (line.find("Description: ") == 0) {
                    desc = line.substr(13);
                } else if (line.find("Priority: ") == 0) {
                    pri = stoi(line.substr(10));
                    taskList[taskCount] = Task(name, desc, pri);
                    taskCount++;
                }
            }
            inFile.close();
            cout << "\n\t*** Successfully loaded (" << taskCount << ") tasks from " << filename << " ***\n";
        }
    }
    
    cout << "\n▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀▶◀\n" << endl;
    
    while (true){
        menu();
        
        cout << "\t|\t*** Enter a number: ";
        cin >> num;
        cin.ignore();
        cout << "\t 一一一一一一一一一一一一一一一一一一一一一一一一一一一" << endl;
        while (num <= 0 || num >= 12){
            cout << "\t\t--- ERROR: Entry must be 1-11!" << endl;
            cout << "\n\t\t*** Enter a number: ";
            cin >> num;
            cin.ignore();
            cout << "\t 一一一一一一一一一一一一一一一一一一一一一一一一一一一" << endl;
        }
        cout << "\n******************************************************************" << endl;
        
        
        switch (num){
                
            case 1:
                welcomeMessage();
                break;
                
            case 2:
                if (taskCount < MAX) {
                    taskList[taskCount].createTask();
                    taskCount++;
                } else {
                    cout << "\n\t--- ERROR: Task list is full!"
                    << "\n\n\t--- MUST delete a task BEFORE another can be added!"
                    << "\n\n******************************************************************\n" << endl;
                }
                break;
                
            case 3:
                if (taskCount == 0) {
                    cout << "\n\t--- ERROR: No tasks to rename!"
                    << "\n\n******************************************************************\n" << endl;
                } else {
                    cout << "\n\t*** Current Tasks ***\n\n";
                    for (int i = 0; i < taskCount; ++i) {
                        cout << "\t" << (i + 1) << ". "
                        << taskList[i].getTaskName() << endl;
                    }
                    
                    int renameIndex;
                    cout << "\n\tEnter the number of the task to rename: ";
                    cin >> renameIndex;
                    cin.ignore();
                    
                    if (renameIndex < 1 || renameIndex > taskCount) {
                        cout << "\n\t--- ERROR: Invalid task number! ---\n"
                        << "\n******************************************************************\n" << endl;
                    } else {
                        taskList[renameIndex - 1].renameTask();
                    }
                }
                break;
                
            case 4:
                if (taskCount == 0) {
                    cout << "\n\t--- ERROR: No tasks to update description!"
                    << "\n\n******************************************************************\n" << endl;
                } else {
                    cout << "\n\t*** Current Tasks ***\n\n";
                    for (int i = 0; i < taskCount; ++i) {
                        cout << "\t" << (i + 1) << ". "
                        << taskList[i].getTaskName() << endl;
                    }
                    
                    int descIndex;
                    cout << "\n\tEnter the number of the task to rename description: ";
                    cin >> descIndex;
                    cin.ignore();
                    
                    if (descIndex < 1 || descIndex > taskCount) {
                        cout << "\n\t--- ERROR: Invalid task number! ---\n"
                        << "\n******************************************************************\n" << endl;
                    } else {
                        taskList[descIndex - 1].renameDesc();
                    }
                }
                break;
                
            case 5:
                if (taskCount == 0) {
                    cout << "\n\t--- ERROR: No tasks to update Priorty Level!"
                    << "\n\n******************************************************************\n" << endl;
                } else {
                    cout << "\n\t*** Current Tasks ***\n\n";
                    for (int i = 0; i < taskCount; ++i) {
                        cout << "\t" << (i + 1) << ". "
                        << taskList[i].getTaskName() << endl;
                    }
                    
                    int priIndex;
                    cout << "\n\tEnter the number of the task to update Priority Level: ";
                    cin >> priIndex;
                    cin.ignore();
                    
                    if (priIndex < 1 || priIndex > taskCount) {
                        cout << "\n\t--- ERROR: Invalid task number! ---\n"
                        << "\n******************************************************************\n" << endl;
                    } else {
                        taskList[priIndex - 1].resetPriLvl();
                    }
                }
                break;
                
            case 6:
                if (taskCount == 0) {
                    cout << "\n\t--- ERROR: Task list is empty!"
                    << "\n\n******************************************************************\n" << endl;
                } else {
                    cout << "\n\t*** Current Tasks ***\n\n";
                    for (int i = 0; i < taskCount; ++i) {
                        cout << "\t" << (i + 1) << ". "
                        << taskList[i].getTaskName() << endl;
                    }
                    
                    int delIndex;
                    cout << "\n\tEnter the number of the task to delete: ";
                    cin >> delIndex;
                    cin.ignore();
                    
                    if (delIndex < 1 || delIndex > taskCount) {
                        cout << "\n\t--- ERROR: Invalid task number! ---\n"
                        << "\n******************************************************************\n" << endl;
                    } else {
                        for (int i = delIndex - 1; i < taskCount - 1; ++i) {
                            taskList[i] = taskList[i + 1];
                        }
                        taskList[taskCount - 1] = Task();
                        taskCount--;
                        
                        cout << "\n\t*** Task deleted successfully! ***\n"
                        << "\n******************************************************************" << endl;
                    }
                }
                break;
                
            case 7:
                if (taskCount == 0) {
                    cout << "\n\t--- ERROR: Task list is empty!"
                    << "\n\n******************************************************************\n" << endl;
                } else {
                    cout << "\n\t*** Current Tasks ***\n\n";
                    for (int i = 0; i < taskCount; ++i) {
                        cout << "\t" << (i + 1) << ". "
                        << taskList[i].getTaskName() << "\n";
                    }
                    cout << "\n\n******************************************************************" << endl;
                }
                break;
                
            case 8:
                if (taskCount == 0) {
                    cout << "\n\t--- ERROR: Task list is empty!"
                    << "\n\n******************************************************************\n" << endl;
                } else {
                    string target;
                    cout << "\n\tEnter the task name to search for: ";
                    getline(cin, target);
                    
                    sortTasksByName(taskList, taskCount); // Ensuring that name is sorted 1st and foremeost
                    
                    int result = binarySearch(taskList, taskCount, target);
                    if (result != -1) {
                        cout << "\n\t*** Task Found! ***\n\n"
                        << "\t• Task: " << taskList[result].getTaskName()
                        << "\n\t• Description: " << taskList[result].getTaskDesc()
                        << "\n\t• Priority Level: " << taskList[result].getTaskPri()
                        << "\n\n******************************************************************" << endl;
                    } else {
                        cout << "\n\t--- Task NOT found! ---\n"
                        << "\n******************************************************************" << endl;
                    }
                }
                break;
                
            case 9:
                if (taskCount == 0) {
                    cout << "\n\t--- ERROR: No tasks to save!"
                    << "\n\n******************************************************************\n" << endl;
                } else {
                    string filename;
                    cout << "\n\tEnter filename to save to (Ex: tasks.txt): ";
                    getline(cin, filename);
                    
                    ofstream fout(filename);
                    
                    if (!fout) {
                        cout << "\n\t--- ERROR: Could not create file! ---\n"
                        << "\n******************************************************************\n" << endl;
                    } else {
                        for (int i = 0; i < taskCount; ++i) {
                            fout << "Task " << (i + 1) << ":\n";
                            fout << "Name: " << taskList[i].getTaskName() << "\n";
                            fout << "Description: " << taskList[i].getTaskDesc() << "\n";
                            fout << "Priority: " << taskList[i].getTaskPri() << "\n";
                            fout << "---------------------------\n";
                        }
                        fout.close();
                        
                        short choice = 0;
                        cout << "\t*** Show file path? (1/0): ";
                        cin >> choice;
                        cin.ignore();
                        
                        if (choice == 1){
                            filesystem::path currentPath = filesystem::current_path();
                            string pathString = currentPath.string();
                            cout << "\n\t*** " << pathString << endl;
                        }
                        
                        cout << "\n\t*** Tasks saved to " << filename << " ***\n"
                        << "\n******************************************************************" << endl;
                    }
                }
                break;
                
            case 10:
                cout << "\n\t*** Successfully ended TaskManager™\n\n";
                return 0;
            default:
                cout << "\n--- ERROR: Invalid option\n";
        }
    }
}
