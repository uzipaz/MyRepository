#ifndef APP_MAIN
#define APP_MAIN

#include <iostream>

#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>

#include <SDL.h>

#include "SpaceShip.h"

const int FRAMES_PER_SEC = 60;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const char WINDOW_NAME[] = "My Window";

class app
{
public:
	app();
	~app();
	bool onExecute();

private:
	bool init();
	void render();
	void handleEvent(SDL_Event* Event);
	void cleanUp();

	void drawAxes(float length);

	SDL_Window* MainWindow;
	SDL_GLContext context;
	SDL_Event* MainEvent;

	bool MainLoop;
	int WinParameterFlags;

	SpaceShip* e;

	float FrameDelay;
	int TotalTicks;
};

#endif