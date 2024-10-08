#pragma once
#include <SDL.h>
#define INITIALISE_WINDOW
//Initialising and rendering the window
int init_SDL_window() {
    //Error handling
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialize the SDL2 Library\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }
    SDL_Window* window = SDL_CreateWindow("SDL2 Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        680, 480,
        0);
    //Error handling
    if (!window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }

    SDL_Surface* window_surface = SDL_GetWindowSurface(window);
    //Error handling
    if (!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }
    //Updating events and quit button
    bool keep_window_open = true;
    while (keep_window_open)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) > 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                keep_window_open = false;
                break;
            }

            SDL_UpdateWindowSurface(window);
        }
    }
    return 1;
}
