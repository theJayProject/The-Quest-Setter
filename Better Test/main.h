#pragma once
#include <map>
#include <iostream>

#define TASKS
std::map<std::string, bool> tasks;
std::string taskName_ph;

//Listing Tasks
#define TASK_LIST
auto taskList(std::map<std::string, bool>::iterator it = tasks.begin()) {
    std::cout << "\n";
//Complete or Incomplete Status
    while (it != tasks.end()) {
        std::string status;
        if (it->second == true) {
            status = "Complete";
        }
        else if (it->second == false) {
            status = "Incomplete";
        }
        std::cout << "Task: " << it->first << ", Status: " << status << std::endl;
        ++it;
        std::cout << std::endl;
    }
}
//Adding Tasks
#define ADD_TASK
auto addTask() {

    std::cout << "What is the task name?\n";
    std::cin >> taskName_ph;
    tasks.insert(std::make_pair(taskName_ph, false));
    std::cout << "Added " << taskName_ph << " as incomplete.\n";
}
//Deleting Tasks
#define DELETE_TASK
auto deleteTask() {
    std::cout << "Which task would you like to delete?\n";
    std::cin >> taskName_ph;
    if (tasks.find(taskName_ph) != tasks.end()) {
        tasks.erase(tasks.find(taskName_ph));
        std::cout << taskName_ph << " has been deleted successfully\nTasks remaining:\n";
        taskList();
    }
    else {
        std::cout << "Task not found. Please try again.\n";
    }
}
//Completing Tasks
#define COMPLETE_TASK
auto completeTask() {
    bool complete = true;
    std::cout << "Which task would you like to complete?\n";
    std::cin >> taskName_ph;
    if (tasks.find(taskName_ph) != tasks.end()) {
        tasks.erase(tasks.find(taskName_ph));
        tasks.insert(std::make_pair(taskName_ph, complete));
        std::cout << taskName_ph << " is now complete.\n";
    }
    else {
        std::cout << "Task not found. Please try again.\n";
    }
}