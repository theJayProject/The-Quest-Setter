#include "main.h"

int main() {
    //Adding, reading, editing tasks introduced     
    for (std::string Answer_ph; Answer_ph != "end";) {
        std::cout << "Would you like to add, read, complete or delete a task?\n";
        std::cin >> Answer_ph;
        std::string taskName_ph;
        if (Answer_ph == "add") {
            std::cout << "What is the task name?\n";
            std::cin >> taskName_ph;
            tasks.insert(std::make_pair(taskName_ph, false));
            std::cout << "Added " << taskName_ph << " as incomplete.\n";
            taskList();
        }
        else if (Answer_ph == "read") {
            taskList();
        }
        else if (Answer_ph == "complete") {
            bool complete = true;
            std::cout << "Which task would you like to complete?\n";
            std::cin >> taskName_ph;
            tasks.erase(tasks.find(taskName_ph));
            tasks.insert(std::make_pair(taskName_ph, true));
            std::cout << taskName_ph << " is now complete.\n";
            taskList();
        }
        else if (Answer_ph == "delete") {
            std::string taskDelete_ph;
            std::cout << "Which task would you like to delete?\n";
            std::cin >> taskDelete_ph;
            tasks.erase(tasks.find(taskDelete_ph));
            std::cout << taskDelete_ph << " has been deleted successfully\n";
            taskList();
        }
        else {
            std::cout << "Error: command misunderstood.\n";
            return 0;
        }
    }

        return 0;
}

