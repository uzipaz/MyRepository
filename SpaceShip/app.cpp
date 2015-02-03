#include "app.h"

app::app()
{
	MainWindow = NULL;
	MainEvent = NULL;
	MainLoop = true;

	e = NULL;

	FrameDelay = 0.0;
}

app::~app()
{
}

bool app::onExecute()
{
	if ( !init() )
		return false;

	MainEvent = new SDL_Event();
	int DeltaTime, CurrentTicks;

	TotalTicks = SDL_GetTicks();
	while (MainLoop)
	{
		while (SDL_PollEvent(MainEvent))
			handleEvent(MainEvent);

		CurrentTicks = SDL_GetTicks();
		DeltaTime = CurrentTicks - TotalTicks;
		if ( DeltaTime > FrameDelay )
		{
			e->NextFrameCalc(DeltaTime);
			render();

			TotalTicks = CurrentTicks;
		}
	}

	cleanUp();

	return true;
}

bool app::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	WinParameterFlags = SDL_WINDOW_OPENGL;
	MainWindow = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, WinParameterFlags);
	context = SDL_GL_CreateContext(MainWindow);

	if (MainWindow == NULL)
		return false;

	SDL_ShowCursor(0);

	e = new SpaceShip(point3D(0.0, 0.0, 0.0), 1.0, 180.0, 3.0, 1);
	e->init();
	FrameDelay = 1000 / (float) FRAMES_PER_SEC;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, SCREEN_WIDTH / (float) SCREEN_HEIGHT, 1.0, 100.0);

	return true;
}

void app::handleEvent(SDL_Event* Event)
{
	switch (Event->type)
	{
	case SDL_KEYDOWN:
		switch(Event->key.keysym.sym)
		{
		case SDLK_UP:
			e->setThrust(true);
			break;

		case SDLK_LEFT:
			e->SetIncrementHeadingFlag(true);
			break;

		case SDLK_RIGHT:
			e->SetDecrementHeadingFlag(true);
			break;

		case SDLK_r:
			e->resetPosition();
			break;

		default:
			break;
		}	
		break;

	case SDL_KEYUP:
		switch (Event->key.keysym.sym)
		{
		case SDLK_ESCAPE:
			MainLoop = false;
			break;

		case SDLK_UP:
			e->setThrust(false);
			break;

		case SDLK_LEFT:
			e->SetIncrementHeadingFlag(false);
			break;

		case SDLK_RIGHT:
			e->SetDecrementHeadingFlag(false);
			break;

		default:
			break;
		}
		break;

	case SDL_QUIT:
		MainLoop = false;
		break;
	
	default:
		break;
	}
}

void app::render()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	
	glTranslatef(0.0, 0.0, -50.0);

	//drawAxes(5.0);

	glColor3f(1.0, 1.0, 1.0);
	e->render();

	SDL_GL_SwapWindow(MainWindow);
}

void app::cleanUp()
{
	delete e;
	SDL_DestroyWindow(MainWindow);
	SDL_Quit();

	delete MainEvent;
}

void app::drawAxes(float length)
{
	glBegin(GL_LINES);
		glColor3f(1.0, 0, 0); glVertex3f(0.0, 0.0, 0.0); glVertex3f(length, 0.0, 0.0);
		glColor3f(0, 1.0, 0); glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.0, length, 0.0);
		glColor3f(0, 0, 1.0); glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, length);
	glEnd();
}