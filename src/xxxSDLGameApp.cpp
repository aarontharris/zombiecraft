//#include "SDLGameApp.h"
//
//#include <SDL_timer.h>
//
///* A simple function that prints a message, the error code returned by SDL,
// * and quits the application */
//void sdldie(const char *msg) {
//	printf("%s: %s\n", msg, SDL_GetError());
//	SDL_Quit();
//	exit(1);
//}
//
//void checkSDLError(int line = -1) {
//#ifndef NDEBUG
//	const char *error = SDL_GetError();
//	if (*error != '\0') {
//		printf("SDL Error: %s\n", error);
//		if (line != -1)
//			printf(" + line: %i\n", line);
//		SDL_ClearError();
//	}
//#endif
//}
//
//SDLGameApp::SDLGameApp( int width, int height ) : GameApp::GameApp( width, height ) {
//}
//
//SDLGameApp::~SDLGameApp() {
//	GameApp::~GameApp();
//}
//
//void start( int width, int height ) {
//	SDL_Window *mainwindow; /* Our window handle */
//	SDL_GLContext maincontext; /* Our opengl context handle */
//
//	if (SDL_Init(SDL_INIT_VIDEO) < 0) /* Initialize SDL's Video subsystem */
//		sdldie("Unable to initialize SDL"); /* Or die on error */
//
//	/* Request opengl 3.2 context.
//	 * SDL doesn't have the ability to choose which profile at this time of writing,
//	 * but it should default to the core profile */
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
//
//	/* Turn on double buffering with a 24bit Z buffer.
//	 * You may need to change this to 16 or 32 for your system */
//	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
//
//	/* Create our window centered at 512x512 resolution */
//	mainwindow = SDL_CreateWindow("ASDF", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
//			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
//	if (!mainwindow) /* Die if creation failed */
//		sdldie("Unable to create window");
//
//	checkSDLError(__LINE__);
//
//	/* Create our opengl context and attach it to our window */
//	maincontext = SDL_GL_CreateContext(mainwindow);
//	checkSDLError(__LINE__);
//
//	/* This makes our buffer swap syncronized with the monitor's vertical refresh */
//	SDL_GL_SetSwapInterval(1);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(50.0f, 1.0f, 0.0f, 100.0f);
//	glMatrixMode(GL_MODELVIEW);
//	glClear( GL_COLOR_BUFFER_BIT);
//
//	bool running = true;
//	SDL_Event event;
//
////	init();
////	this->init();
//
//	float lastFrameStart = 0.0f; // getTime();
//	while (running) {
//		float thisFrameStart = 0.0f; // getTime();
//		float frameTime = thisFrameStart - lastFrameStart;
//
//		while (SDL_PollEvent(&event) != 0) {
//			switch (event.type) {
//			case SDL_KEYDOWN:
//				if (event.key.keysym.sym == SDLK_ESCAPE)
//					running = false;
//				break;
//			}
//		}
//
////		float frametime = (float)frameTicks / 1000.0f;
////		frameTime = 0.025;
//
//		float fps = 1 / frameTime;
//		fprintf( stdout, "FPS: %f, FrameTime: %f\n", fps, frameTime);
//
////		update(frameTime);
////		render(frameTime);
//
//		/* Swap our back buffer to the front */
//		SDL_GL_SwapWindow(mainwindow);
//
////		if (SDL_GetTicks() - frameTicks < minframetime)
////			SDL_Delay(minframetime - (SDL_GetTicks() - frameTicks));
//		lastFrameStart = thisFrameStart;
//	}
//
//	/* Delete our opengl context, destroy our window, and shutdown SDL */
//	SDL_GL_DeleteContext(maincontext);
//	SDL_DestroyWindow(mainwindow);
//	SDL_Quit();
//}
//
//float SDLGameApp::getTime() {
//	return (float) SDL_GetTicks() / 1000.0f;
//}
//
//void SDLGameApp::init() {
//}
//
//void SDLGameApp::update(float frameTime) {
//}
//
//void SDLGameApp::render(float frameTime) {
//}
