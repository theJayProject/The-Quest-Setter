#include "main.h"
#include "VisualTasks.h"

int main(int argc, char** argv) {
    //Initiating and opening the window with SDL
    SDL_Init(SDL_INIT_VIDEO);

    Window window;
    ButtonUI AppUI;
    VisualTasks_buttonUI VisualTask;
    SDL_Event Event;
    bool shouldQuit{ false };
    
    while (!shouldQuit) {
        //VisualTask.y change based on task amount
        while (SDL_PollEvent(&Event)) {
            VisualTask.HandleEvent(Event);
            AppUI.HandleEvent(Event);
            if (Event.type == SDL_QUIT) {
                shouldQuit = true;
            }
        }
        window.Render();
        AppUI.Render(window.GetSurface());
        VisualTask.Render(window.GetSurface());
        window.Update();
    }
    SDL_Quit();
    //Adding, reading, editing tasks introduced     
    //for (std::string Answer_ph; Answer_ph != "end";) {
    //    std::cout << "Would you like to add, read, complete or delete a task?\n";
    //    std::cin >> Answer_ph;
    //    if (Answer_ph == "add") {
    //        addTask();
    //    }
    //    else if (Answer_ph == "read") {
    //        taskList();
    //    }
    //    else if (Answer_ph == "complete") {
    //        completeTask();
    //    }
    //    else if (Answer_ph == "delete") {
    //        deleteTask();
    //    }
    //    else {
    //        std::cout << "Error: command misunderstood.\n";
    //    }
    //}

    return 0;
}