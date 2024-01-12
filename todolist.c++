#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Task {
    string explanation;
    bool complete;

    Task(const string& desc) : explanation(desc), complete(false) {}
};
void addTask(vector<Task>& taskList, const string& explanation) {
    taskList.push_back(Task(explanation));
    cout << "Task added: " << explanation << endl;
}

void viewTasks(const vector<Task>& taskList) {
    cout << "Task List:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". " << taskList[i].explanation << " - ";
        cout << (taskList[i].complete ? "Complete" : "Pending") << endl;
    }
}
void markTaskComplete(vector<Task>& taskList, size_t index) {
    if (index > 0 && index <= taskList.size()) {
        taskList[index - 1].complete = true;
        cout << "Task marked as complete: " << taskList[index - 1].explanation << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}
void removeTask(vector<Task>& taskList, size_t index) {
    if (index > 0 && index <= taskList.size()) {
        cout << "Task removed: " << taskList[index - 1].explanation << endl;
        taskList.erase(taskList.begin() + index - 1);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "\nTask Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. End\n";
        cout << "Enter whatever choice you want: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task explanation: ";
                string explanation;
                cin.ignore();
                getline(cin, explanation);
                addTask(taskList, explanation);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                cout << "Enter the index of task to mark as completed: ";
                size_t index;
                cin >> index;
                markTaskComplete(taskList, index);
                break;
            }
            case 4: {
                cout << "Enter the index of task to remove: ";
                size_t index;
                cin >> index;
                removeTask(taskList, index);
                break;
            }
            case 5:
                cout << "Ending of program. Goodbye!\n";
                return 0;
            default:
                cout << "Not valid choice. Please attempt again.\n";
        }
    }

    return 0;
}
