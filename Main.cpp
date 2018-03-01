#include"SDL\include\SDL.h"
#include <iostream>
using namespace std;
#pragma comment(lib, "SDL/Libraries/SDL2.lib")
#pragma comment(lib, "SDL/Libraries/SDL2main.lib")

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*void Plus(int* rec);

void Minus(int* rec);*/

int main(int argc, char* argv[]) {

	SDL_Window* window = NULL;

	SDL_Renderer* Cube = NULL;


	// superficie en la que actua el render

	SDL_Rect rect;
	{
	rect.h = 40;
	rect.w = 40;
	}

	int xdir = 1;
	int ydir = 1;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
	
	}
	else
	{

		window = SDL_CreateWindow("CubeWorld", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
		
		}
		else
		{

			Cube = SDL_CreateRenderer(window, -1, 0);

		}

		
		while (1) {


			rect.x = 1;
			rect.y = 1;


			while (rect.x <= 600 && rect.y <= 440 && rect.x >= 0 && rect.y >= 0) {

				rect.y += ydir;

				if (rect.y == 440 || rect.y == 0) {
					ydir *= -1;
				}

				rect.x += xdir;

				if (rect.x == 600 || rect.x == 0) {
					xdir *= -1;
				}

				
				SDL_SetRenderDrawColor(Cube, 0, 0, 255, 0x00);

				SDL_RenderClear(Cube);

				SDL_SetRenderDrawColor(Cube, 255, 0, 0, 0);

				SDL_RenderFillRect(Cube, &rect);

				SDL_RenderPresent(Cube);

				SDL_Delay(1);
			}

			
		}
		
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
