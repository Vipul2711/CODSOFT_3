#include <bits/stdc++.h>

using namespace std;

struct Task
{
    string name;
    bool completed;
};

vector<Task> Task_list;

void addTask()
{
    string task_name;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, task_name);
    Task_list.push_back({task_name, false});
    cout << "Task is added: " << task_name << endl;
}

void viewTask_manager()
{
    if (Task_list.empty())
    {
        cout << "No Task_list in the list." << endl;
    }
    else
    {
        cout << "To-Do List:" << endl;
        for (int i = 0; i < Task_list.size(); i++)
        {
            cout << i + 1 << ". " << Task_list[i].name << " - " << (Task_list[i].completed ? "Completed" : "Pending") << endl;
        }
    }
}

void markTaskCompleted()
{
    int task_Id;
    cout << "Enter task number to mark as completed: ";
    cin >> task_Id;
    if (task_Id > 0 && task_Id <= Task_list.size())
    {
        Task_list[task_Id - 1].completed = true;
        cout << "Task " << task_Id << " marked as completed." << endl;
    }
    else
    {
        cout << "Invalid task number." << endl;
    }
}

void removeTask()
{
    int task_Id;
    cout << "Enter task number to remove: ";
    cin >> task_Id;
    if (task_Id > 0 && task_Id <= Task_list.size())
    {
        cout << "Removed task: " << Task_list[task_Id - 1].name << endl;
        Task_list.erase(Task_list.begin() + task_Id - 1);
    }
    else
    {
        cout << "Enter valid task number." << endl;
    }
}

int main()
{
    while (true)
    {
        cout << "\n--- To-Do List Menu ---" << endl;
        cout << "1. Add a Task" << endl;
        cout << "2. View Task_list" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Choose an option from (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTask_manager();
            break;
        case 3:
            markTaskCompleted();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            cout << "Exit..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    return 0;
}
