/*
 * ZGame.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#include "ZGame.h"
#include "Vector3f.h"

void drawTeapot();
void drawCubes();

Vector3f camPos; // camera position
Vector3f camRot; // camera normal
Vector3f tcamPos; // camera target position
Vector3f ncamPos; // camera normal
Vector3f potPos; // pot position
Vector3f potRot; // pot rotation

// GAME_APP is a #define that points to the impl for SDL,GLFW, etc
ZGame::ZGame(const char* windowTitle, int screenWidth, int screenHeight) :
		GAME_APP_ABSTRACTION_LAYER(windowTitle, screenWidth, screenHeight) {
}

void ZGame::init() {
	camPos.x = 0;
	camPos.y = 0;
	camPos.z = 15; // -z extends into the monitor, +z towards the player

	camRot.x = 0;
	camRot.y = 0;
	camRot.z = 45;

	tcamPos.x = 0;
	tcamPos.y = 0;
	tcamPos.z = 0;

	ncamPos.x = 0;
	ncamPos.y = 1;
	ncamPos.z = 0;

	potPos.x = 0;
	potPos.y = -5;
	potPos.z = 0;

	potRot.x = 0;
	potRot.y = 0;
	potRot.z = 0;
}

void ZGame::update(float frameTime) {
	potPos.y += frameTime;
	potRot.z += frameTime * 30; // 30 degrees per second
	camRot.z += frameTime * 30;

	tcamPos.x = potPos.x;
	tcamPos.y = potPos.y;
	tcamPos.z = potPos.z;
}

void ZGame::render(float frameTime) {
	int width = getScreenWidth();
	int height = getScreenHeight();
	glClear( GL_COLOR_BUFFER_BIT);
	printf("ZGame::render %.3f\n", frameTime);

	float ratio;
	ratio = width / (float) height;

	// Setup our camera
	{
		printf("ZGame::render %d x %d\n", width, height);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(50.0f, ratio, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	// the camera's matrix
	glPushMatrix();
	{
		// Rotate space for camera
		glRotatef(camRot.x, 1, 0, 0);
		glRotatef(camRot.y, 0, 1, 0);
		glRotatef(camRot.z, 0, 0, 1);

		// Look after rotation
		gluLookAt( //
				camPos.x, camPos.y, camPos.z, // camera position
				tcamPos.x, tcamPos.y, tcamPos.z, // target position
				ncamPos.x, ncamPos.y, ncamPos.z // camera up
				);

		// Draw the world in the same root matrix to adopt camera rotation, etc
		{
			// push cube data to server only once
			// FIXME: i should implement a validation system and only push when invalidated
			//			if (firstRender) {
			//				firstRender = false;
			drawCubes();
			//			}

			drawTeapot();
		}
	}
	glPopMatrix();
}

void drawTeapot() {
	glPushMatrix();

	/* position */
	glTranslatef(potPos.x, potPos.y, potPos.z);

	/* rotate */
	glRotatef(potRot.x, 1, 0, 0);
	glRotatef(potRot.y, 0, 1, 0);
	glRotatef(potRot.z, 0, 0, 1);

	/* draw */
	glutWireTeapot(0.5);

	glPopMatrix();
}

int wCubes = 10;
int hCubes = 10;
int dCubes = 10;
int cubeSize = .5;
Vector3f cubeOrigin = { 0,0,0 };

void drawCubes() {
	glPushMatrix();

	glTranslatef( cubeOrigin.x, cubeOrigin.y, cubeOrigin.z );
	glutWireCube(10);

	glPopMatrix();
}
