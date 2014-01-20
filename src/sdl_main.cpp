///*
// * main.cpp
// *
// *  Created on: Jan 15, 2014
// *      Author: aarontharris
// */
//
//#include <iostream>
//#include <vector>
//#include <SDL.h>
//#include <glut.h>
//#include <gl3ext.h>
//
////#define GL3_PROTOTYPES 1
//#define PROGRAM_NAME "Tutorial1"
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
//const Uint32 fps = 40;
//const Uint32 minframetime = 1000 / fps;
//const int width = 800, height = 600;
//
///* Global Member Functions */
//void init();
//void update(float frameTime);
//void render(float frameTime);
//
//void drawTeapot();
//void drawCubes();
//
//float getTime() {
//	return (float)SDL_GetTicks() / 1000.0f;
//}
//
///* Our program's entry point */
//int main(int argc, char *argv[]) {
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
//	mainwindow = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED,
//	SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
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
//	init();
//
//	float lastFrameStart = getTime();
//	while (running) {
//		float thisFrameStart = getTime();
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
//		update(frameTime);
//		render(frameTime);
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
//	return 0;
//}
//
//typedef struct {
//	float x, y, z;
//} Vector3f;
//
//Vector3f camPos; // camera position
//Vector3f camRot; // camera normal
//Vector3f tcamPos; // camera target position
//Vector3f ncamPos; // camera normal
//Vector3f potPos; // pot position
//Vector3f potRot; // pot rotation
//
//void init() {
//	camPos.x = 0;
//	camPos.y = 0;
//	camPos.z = 15; // -z extends into the monitor, +z towards the player
//
//	camRot.x = 0;
//	camRot.y = 0;
//	camRot.z = 45;
//
//	tcamPos.x = 0;
//	tcamPos.y = 0;
//	tcamPos.z = 0;
//
//	ncamPos.x = 0;
//	ncamPos.y = 1;
//	ncamPos.z = 0;
//
//	potPos.x = 0;
//	potPos.y = -5;
//	potPos.z = 0;
//
//	potRot.x = 0;
//	potRot.y = 0;
//	potRot.z = 0;
//}
//
//void update(float frameTime) {
//	potPos.y += frameTime;
//	potRot.z += frameTime * 30; // 30 degrees per second
//	camRot.z += frameTime * 30;
//
//	tcamPos.x = potPos.x;
//	tcamPos.y = potPos.y;
//	tcamPos.z = potPos.z;
//}
//
//void render(float frameTime) {
//	float ratio;
//	ratio = width / (float) height;
//
//	// Setup our camera
//	{
//		glViewport(0, 0, width, height);
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluPerspective(50.0f, ratio, 0.1f, 100.0f);
//		glMatrixMode(GL_MODELVIEW);
//		glClear(GL_COLOR_BUFFER_BIT);
//	}
//
//	// the camera's matrix
//	glPushMatrix();
//	{
//		// Rotate space for camera
//		glRotatef(camRot.x, 1, 0, 0);
//		glRotatef(camRot.y, 0, 1, 0);
//		glRotatef(camRot.z, 0, 0, 1);
//
//		// Look after rotation
//		gluLookAt( //
//				camPos.x, camPos.y, camPos.z, // camera position
//				tcamPos.x, tcamPos.y, tcamPos.z, // target position
//				ncamPos.x, ncamPos.y, ncamPos.z // camera up
//				);
//
//		// Draw the world in the same root matrix to adopt camera rotation, etc
//		{
//			// push cube data to server only once
//			// FIXME: i should implement a validation system and only push when invalidated
////			if (firstRender) {
////				firstRender = false;
//			drawCubes();
////			}
//
//			drawTeapot();
//		}
//	}
//	glPopMatrix();
//}
//
//void drawTeapot() {
//	glPushMatrix();
//
//	/* position */
//	glTranslatef(potPos.x, potPos.y, potPos.z);
//
//	/* rotate */
//	glRotatef(potRot.x, 1, 0, 0);
//	glRotatef(potRot.y, 0, 1, 0);
//	glRotatef(potRot.z, 0, 0, 1);
//
//	/* draw */
//	glutWireTeapot(0.5);
//
//	glPopMatrix();
//}
//
//int wCubes = 10;
//int hCubes = 10;
//int dCubes = 10;
//int cubeSize = .5;
//
//void drawCubes() {
////	fprintf( stdout, "drawCubes\n");
//	glPushMatrix();
//
////	float size = 9;
//
////	for ( int x = 0; x < 3000; x++ ) {
//	glutWireCube(10);
////	}
////	glutWireCube(10);
//
////	float xOrg = -1 * wCubes * cubeSize;
////
////	Vector3f origin;
////	origin.x = 0;
////	origin.y = 0;
////	origin.z = 0;
////
////
////	for ( int xIdx = 0; xIdx < wCubes; xIdx++ ) {
////		glPushMatrix();
////		float xPos = origin.x + xIdx * cubeSize;
////		glTranslatef(xPos, origin.y, origin.z);
////		glutWireCube(cubeSize);
////		glPopMatrix();
////	}
//
//	glPopMatrix();
//}
