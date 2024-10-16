#pragma once
#include <SDL.h>
#include "Buttons.h"
#define VISUAL_TASKS




class VisualTasks_rect {
public:
    VisualTasks_rect(
        int x, int y, int w, int h,
        SDL_Color Color = { 0, 0, 0 })
        : Rect{ x, y, w, h }, Color{ Color } {}

    virtual void Render(SDL_Surface* Surface) {
        SDL_FillRect(
            Surface, &Rect, SDL_MapRGB(
                Surface->format,
                Color.r, Color.g, Color.b
            )
        );
    }

    //Creating a hover reaction
    void SetColor(SDL_Color C) { Color = C; }

    bool IsWithinBounds(int x, int y) const {
        if (x < Rect.x) return false;
        if (x > Rect.x + Rect.w) return false;
        if (y < Rect.y) return false;
        if (y > Rect.y + Rect.h) return false;
        return true;
    }

private:
    SDL_Rect Rect{ 0, 0, 0, 0 };
    SDL_Color Color{ 0, 0, 0 };
};

//Add Task Button - mouse motion
class VisualTasks_button : public VisualTasks_rect {
public:
    VisualTasks_button(int x, int y, int w, int h) : VisualTasks_rect
    { x, y, w, h, {50, 30, 100} } {}

    void HandleEvent(const SDL_Event& Event) {
        if (Event.type == SDL_MOUSEMOTION) {
            HandleMouseMotion(Event.motion);
        }
        else if (Event.type == SDL_MOUSEBUTTONDOWN) {
            HandleMouseButton(Event.button);
        }
    }


protected:
    virtual void HandleLeftClick() {}
private:
    void HandleMouseMotion(
        const SDL_MouseMotionEvent& Event) {


        //On Hover
        if (IsWithinBounds(Event.x, Event.y)) {
            SetColor({ 50, 50, 100 });
        }
        //Off Hover
        else {
            SetColor({ 50, 30, 100 });
        }

    }
    void HandleMouseButton(
        const SDL_MouseButtonEvent& Event) {
        if (IsWithinBounds(Event.x, Event.y)) {
            const Uint8 Button{ Event.button };
            if (Button == SDL_BUTTON_LEFT) {
                HandleLeftClick();
                //INPUT PERMAMENT COLOUR CHANGE FOR VISUAL TASK ON CLICK HERE
                std::cout << "VisualTasks has been left-clicked\n";
            }
        }
    }
};
    //Creating UI for the button
//EDIT THIS CLASS TO CHANGE SIZE
class VisualTasks_buttonUI {
public:
    void Render(SDL_Surface* Surface) {
        MyButton.Render(Surface);
    }

    void HandleEvent(const SDL_Event& E) {
        MyButton.HandleEvent(E);
    }
    int x = 150;
    int y = 150;
    int w = 400;
    int h = 50;
    // Standard Size:
    // x = 150, y = 150, w = 400, h = 50
    VisualTasks_button MyButton{ x, y, w, h };
};

class DerivedVisualTasks_button : public VisualTasks_button {
public:
    DerivedVisualTasks_button(int x, int y, int w, int h)
        : VisualTasks_button{ x, y, w, h } {}

protected:
    void HandleLeftClick() override {
        std::cout << "I have been left-clicked\n";
    }
};
