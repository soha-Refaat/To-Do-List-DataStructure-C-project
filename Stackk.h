#pragma once
#include <iostream>
#include <string>
using namespace std;
class Task {
private:
    string description;
    bool completed;
public:
    Task() {}
    Task(const string& desc) {
        description = desc;
        completed = false;
    }

    void complete() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    const string& getDescription() const {
        return description;
    }


};

class TaskArray {
private:
    Task* tasks;
    int capacity;
    int size;

    void resize(int new_capacity) {
        Task* new_tasks = new Task[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_tasks[i] = tasks[i];
        }
        delete[] tasks;
        tasks = new_tasks;
        capacity = new_capacity;
    }
    

public:
    TaskArray() {
        tasks = nullptr;
        capacity = 0;
        size = 0;
    }

    ~TaskArray() {
        delete[] tasks;
    }

    void push(const Task& task) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : 2 * capacity);
        }
        tasks[size++] = task;
    }

    string  remove(int num) {
        if (num - 1 >= size) {
            return "Task not valid";
        }
        for (int i = num - 1; i < size - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        size--;
        return "Task removed";
    }

    Task& operator[](int index) {
        return tasks[index];
    }

    const Task& operator[](int index) const {
        return tasks[index];
    }

    int getSize() const {
        return size;
    }
};
class ToDoList {
private:
    TaskArray tasks;

public:
    void addTask(const std::string& description) {
        tasks.push(Task(description));
    }

    void completeTask(int index) {
        if (index >= 0 && index < tasks.getSize()) {
            tasks[index].complete();
        }
        else {
            cout << "Invalid task index.\n";
        }
    }

    void removeTask(int index) {
        cout << tasks.remove(index) << endl;
    }

    void displayTasks() const {
        for (int i = 0; i < tasks.getSize(); ++i) {
            if (tasks[i].isCompleted()) {
                cout << "[x] ";
            }
            else {
                cout << "[ ] ";
            }
            cout << i + 1 << ". " << tasks[i].getDescription() << "\n";
        }
    }

    int contTasks() {
        return tasks.getSize();
    }
    
   
};
