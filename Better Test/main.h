#pragma once
#include <map>
#include <iostream>

#define Tasks
std::map<std::string, bool> tasks;
std::string taskName_ph;

//Listing Tasks
#define TaskList    
auto taskList(std::map<std::string, bool>::iterator it = tasks.begin()) {
    std::cout << "\n";
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
#define ADDTASK
auto addTask() {

    std::cout << "What is the task name?\n";
    std::cin >> taskName_ph;
    tasks.insert(std::make_pair(taskName_ph, false));
    std::cout << "Added " << taskName_ph << " as incomplete.\n";
}
//Deleting Tasks
#define DELETETASK
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
#define COMPLETETASK
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