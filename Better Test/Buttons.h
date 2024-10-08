#pragma once
#include "visual.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////ADD TASK BUTTON////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ADD_TASK_BUTTON
//Creating the surface for the add task button
class AddTaskButton_rect {
public:
public:
    AddTaskButton_rect(
        int x, int y, int w, int h,
        SDL_Color Color = { 0, 0, 0, 255 })
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
    SDL_Color Color{ 0, 0, 0, 0 };
};

//Add Task Button - mouse motion
class AddTaskButton : public AddTaskButton_rect{
public:
    AddTaskButton(int x, int y, int w, int h) : AddTaskButton_rect 
    { x, y, w, h, {0, 255, 0} } {}

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
    virtual void HandleRightClick() {}

private:
    void HandleMouseMotion(
        const SDL_MouseMotionEvent& Event) {
        if (IsWithinBounds(Event.x, Event.y)) {
            SetColor({ 255, 0, 0 });
        }
        else {
            SetColor({ 0, 255, 0 });
        }
    }
    void HandleMouseButton(
        const SDL_MouseButtonEvent& Event) {
        if (IsWithinBounds(Event.x, Event.y)) {
            const Uint8 Button{ Event.button };
            if (Button == SDL_BUTTON_LEFT) {
                HandleLeftClick();
            }
            else if (Button == SDL_BUTTON_RIGHT) {
                HandleRightClick();
            }
        }
    }
};

        
        //Creating UI for the button
class AddTaskButtonUI {
public:
    void Render(SDL_Surface* Surface) {
        MyButton.Render(Surface);
    }

    void HandleEvent(const SDL_Event& E) {
        MyButton.HandleEvent(E);
    }

    // x = 50, y = 50, w = 50, h = 50
    AddTaskButton MyButton{ 50, 50, 50, 50 };
};

class DerivedAddTaskButton : public AddTaskButton {
public:
    DerivedAddTaskButton(int x, int y, int w, int h)
        : AddTaskButton{ x, y, w, h } {}

protected:
    void HandleLeftClick() override {
        std::cout << "I have been left-clicked\n";
    }

    void HandleRightClick() override {
        std::cout << "I have been right-clicked\n";
    }
};

