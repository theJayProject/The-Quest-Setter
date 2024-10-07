#pragma once
#include <map>
#include <iostream>

#define Tasks
std::map<std::string, bool> tasks;
#define TaskList    
auto taskList(std::map<std::string, bool>::iterator it = tasks.begin()) {
    std::cout << "\n";
    while (it != tasks.end()) {
        std::cout << "Task: " << it->first << ", Status: " << it->second << std::endl;
        ++it;
        std::cout << std::endl;
    }
}
