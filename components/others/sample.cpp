#include <iostream>
#include <vector>
#include <string>

 

struct Task {
    std::string description;
    bool completed;
};

 

std::vector<Task> tasks;

 

void displayMenu() {
    std::cout << "\nTo-Do List Application\n"
<< "1. Add Task\n"
<< "2. View Tasks\n"
<< "3. Mark Task as Completed\n"
<< "4. Quit\n"
<< "Enter your choice: ";
}

 

void addTask() {
    std::string description;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    tasks.push_back({description, false});
    std::cout << "Task added successfully!\n";
}

 

void viewTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
    } else {
        std::cout << "\nTask List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << '\n';
        }
    }
}

 

void markTaskCompleted() {
    viewTasks();
    if (!tasks.empty()) {
        std::cout << "Enter the task number to mark as completed: ";
        int taskNumber;
        std::cin >> taskNumber;

 

        if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task marked as completed!\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }
}

 

int main() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

 

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

 

    return 0;
}