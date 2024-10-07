#include<iostream>
#include <map>


int main() {
    //Creating a map database for all given tasks, going by task number, task name, and status.
    std::map<std::string, bool> tasks;
    int taskNumber_ph = 0;
    tasks.insert(std::make_pair("zero", false));
//Adding, reading, editing tasks introduced     
    
    for (std::string Answer_ph; Answer_ph != "end";) {
        std::cout << "Would you like to add, read, complete or edit a task?\n";
        std::cin >> Answer_ph;
        if (Answer_ph == "add") {
            taskNumber_ph++;
            std::cout << "What is the task name?\n";
            std::string taskName;
            std::cin >> taskName;
            tasks.insert(std::make_pair(taskName, taskNumber_ph));
            std::cout << "Added " << taskName << " as incomplete.\n";

        }
        else if (Answer_ph == "read") {

        }

        else if (Answer_ph == "complete") {

        }
        else if (Answer_ph == "edit") {

        }
        else {
            std::cout << "Error: command misunderstood.";
            return 0;
        }
    }

        return 0;
}

