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

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}
	else
	{

		window = SDL_CreateWindow("CubeWorld", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		}
		else
		{

			Cube = SDL_CreateRenderer(window, -1, 0);

		}

		
		while (1) {
			SDL_Event e;
			if (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) {
					break;
				}
			}

			rect.x = 0;
			rect.y = 0;


			while (rect.x <= 600 && rect.y <= 440 && rect.x >= 0 && rect.y >= 0) {

				rect.y++;

				if (rect.y == 440) {

					while (rect.y > 0)
						rect.y--;
				}
				rect.x++;
				if (rect.x == 600) {
					while (rect.x > 0)
						rect.x--;
				}

				


				

				SDL_SetRenderDrawColor(Cube, 0x00, 0x00, 0xFF, 0x00);

				SDL_RenderClear(Cube);

				SDL_SetRenderDrawColor(Cube, 0xFF, 0x00, 0x00, 0x00);

				SDL_RenderFillRect(Cube, &rect);

				SDL_RenderPresent(Cube);

				SDL_Delay(5);
			}

			
		}
		
	}



	return 0;
}
/*
void Plus(int* rec) {
	*rec++;
}
void Minus(int* rec) {
	*rec--;
}*/