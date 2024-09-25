#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added successfully." << endl;
}

void viewTasks() {
    cout << "Your tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " (completed)";
        }
        cout << endl;
    }
}

void markAsCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Mark task as completed\n";
        cout << "4. Remove task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task index: ";
                int index;
                cin >> index;
                markAsCompleted(index - 1);
                break;
            case 4:
                cout << "Enter task index: ";
                cin >> index;
                removeTask(index - 1);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}