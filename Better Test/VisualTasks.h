#pragma once
#include <SDL.h>
#define VISUAL_TASKS

class VisualTasks_rect {
public:
public:
    VisualTasks_rect(
        int x, int y, int w, int h,
        SDL_Color Color = { 50, 50, 50, 50 })
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
    SDL_Color Color{ 50, 50, 50, 50 };
};

//Add Task Button - mouse motion
class VisualTasks_button : public VisualTasks_rect {
public:
    VisualTasks_button(int x, int y, int w, int h) : VisualTasks_rect
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
            SetColor({ 255, 0, 255 });
        }
        else {
            SetColor({ 0, 255, 255 });
        }
    }
    void HandleMouseButton(
        const SDL_MouseButtonEvent& Event) {
        if (IsWithinBounds(Event.x, Event.y)) {
            const Uint8 Button{ Event.button };
        }
    }
     
};
    //Creating UI for the button
class VisualTasks_buttonUI {
public:
    void Render(SDL_Surface* Surface) {
        MyButton.Render(Surface);
    }

    void HandleEvent(const SDL_Event& E) {
        MyButton.HandleEvent(E);
    }
    int y = 150;
    // x = 100, y = 100, w = 50, h = 50
    VisualTasks_button MyButton{ 150, y, 400, 50 };
};

class DerivedVisualTasks_Button : public VisualTasks_button {
public:
    DerivedVisualTasks_Button(int x, int y, int w, int h)
        : VisualTasks_button{ x, y, w, h } {}
};