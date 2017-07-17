#pragma once
#include<SDL.h>
class Screen
{
public:
	const static int SCREEN_WIDTH = 400;
	const static int SCREEN_HEIGHT = 400;
private:
	SDL_Window *window;
	SDL_Renderer * renderer;
	SDL_Texture * texture;
	Uint32 * buffer;
	Uint32 * buffer2;
public:
	Screen();
	~Screen();
	bool Init();
	bool processEvents();
	void close();
	void setPixel(int, int, Uint8,Uint8,Uint8);
	void update();
	void clear();
	void blur();
};

