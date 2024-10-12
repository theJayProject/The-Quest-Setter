#pragma once
#include "VisualTasks.h"
#include <SDL_ttf.h>

class TaskInput{
	SDL_Surface* text;
	SDL_Color color = { 0, 0, 0 };
	SDL_Texture* text_texture;
	SDL_Rect dest = {};
};
//https://thenumb.at/cpp-course/sdl2/07/07.html
//VisualTasks_button MyButton{ x, y, w, h };