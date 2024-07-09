#include <iostream>
#include <string>
#include "Stackk.h"
using namespace std;
int main() {
    ToDoList toDoList;
    int choice;
    string description;
    int taskNumber;

    while (true) {
        cout << "1. Add Task\n2. Complete Task\n3. Remove Task\n4. Display Tasks\n5. Count Tasks\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
        case 1:
            cout << "Enter task description: ";
            getline(cin, description);
            toDoList.addTask(description);
            break;
        case 2:
            cout << "Enter task number to complete: ";
            cin >> taskNumber;
            toDoList.completeTask(taskNumber - 1);
            break;
        case 3:
            cout << "Enter task number to Remove: ";
            cin >> taskNumber;


            toDoList.removeTask(taskNumber);
            
            break;
        case 4:
            toDoList.displayTasks();
            break;
       
        case 5:
           cout<< toDoList.contTasks() <<endl;
            break;
      
        case 6:
            return 0;

        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    return 0;
}
