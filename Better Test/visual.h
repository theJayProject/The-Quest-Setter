#pragma once
#include <iostream>
#include <SDL.h>
#include "Buttons.h"

//Creating a window on which the application will take place
#define INITIALISE_WINDOW
class Window {
public:
    Window() {
        SDLWindow = SDL_CreateWindow(
            "Quest Setter", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
    }

    void Render() {
        SDL_FillRect(GetSurface(), nullptr,
            SDL_MapRGB(
                GetSurface()->format, 50, 50, 50
            )
        );
    }

    void Update() {
        SDL_UpdateWindowSurface(SDLWindow);
    }

    SDL_Surface* GetSurface() {
        return SDL_GetWindowSurface(SDLWindow);
    }

    ~Window() {
        SDL_DestroyWindow(SDLWindow);
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

private:
    SDL_Window* SDLWindow;
};

    AddTaskButtonUI AppUI;
