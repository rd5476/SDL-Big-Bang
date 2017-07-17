#include "Screen.h"
#include<iostream>
using namespace std;

Screen::Screen() :window(NULL), renderer(NULL), texture(NULL), buffer(NULL),buffer2(NULL){	
	
}

bool Screen::Init(){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		cout << "Could not initialize" << SDL_GetError();
	}

	 window = SDL_CreateWindow("First", 100, 100, 500, 500, SDL_WINDOW_SHOWN);

	if (window == NULL){
		cout << "window created";
		SDL_Quit();
		return false;

	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		cout << "Renderer failed\n";
		return false;
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 400, 400);
	if (texture == NULL){
		cout << "Texture Failed\n";
		return false;
	}

	buffer = new Uint32[400 * 400];
	if (buffer == NULL){
		return false;
	}
	buffer2 = new Uint32[400 * 400];
	if (buffer == NULL){
		return false;
	}
	memset(buffer, 0, 400 * 400 * sizeof(Uint32));
	for (int i = 0; i < 400 * 400; i++){
		buffer[i] = 0x00000000;
	}

	

	return true;
}

bool Screen::processEvents(){
	SDL_Event event;
	while (SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT){
			return false;
		}

	}
	return true; 
}
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
	if (x >= 400 || y >= 400 || x<0 || y <0) return;
	Uint32 color = 0;
	color += red;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += green;
	color <<= 8;
	color += 0xFF;
	buffer[(y*SCREEN_WIDTH)+x] = color;

}
void Screen::update(){
	SDL_UpdateTexture(texture, NULL, buffer, 400 * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
void Screen::clear(){
	memset(buffer, 0, 400 * 400 * sizeof(Uint32));
	memset(buffer2, 0, 400 * 400 * sizeof(Uint32));
}
void Screen::close(){
	delete []buffer;
	delete[]buffer2; 
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit;
}

void Screen::blur(){
	Uint32 *temp = buffer;
	buffer = buffer2;
	buffer2 = temp;

	for (int i = 0; i < 400; i++){
		for (int j = 0; j < 400; j++){
			
			int redTot = 0;
			int greenTot = 0;
			int blueTot = 0;

			for (int row = -1; row <= 1; row++){
				for (int col = -1; col <= 1; col++){
					int currX = i + row;
					int currY = j + col;
				
					if (currX < SCREEN_WIDTH && currX >= 0 && currY >= 0 && currY < SCREEN_HEIGHT){
						Uint32 color = buffer2[currY * SCREEN_WIDTH + currX];
						
						redTot += color >> 24;
						greenTot += color >> 16;
						blueTot += color >> 8;
						
					}
				}
			}
			Uint8 red = redTot / 9;
			Uint8 green = greenTot / 9;
			Uint8 blue = blueTot / 9;
			setPixel(i, j, red, green, blue);
		}

	}
	
}
	

Screen::~Screen()
{
}
