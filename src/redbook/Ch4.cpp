/*
 * Ch4.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#include "Ch4.h"

// GAME_APP is a #define that points to the impl for SDL,GLFW, etc
Ch4::Ch4(const char* windowTitle, int screenWidth, int screenHeight) :
		GAME_APP_ABSTRACTION_LAYER(windowTitle, screenWidth, screenHeight) {
}

void Ch4::init() {
	glEnable( GL_CULL_FACE );
	glFrontFace( GL_CCW ); // Default but being explicit
	glEnable( GL_DEPTH_TEST );

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

void Ch4::update(float frameTime) {
	potPos.y += frameTime;
	potRot.z += frameTime * 30; // 30 degrees per second
	potRot.x += frameTime * 90; // 30 degrees per second
	camRot.z += frameTime * 30;

	tcamPos.x = potPos.x;
	tcamPos.y = potPos.y;
	tcamPos.z = potPos.z;
}

void Ch4::render(float frameTime) {
	int width = getScreenWidth();
	int height = getScreenHeight();

	float ratio;
	ratio = width / (float) height;

	// Setup our camera
	{
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(50.0f, ratio, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
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
			for ( int i = 0; i < 10000; i++ ) {
				drawCubes();
			}
		}
	}
	glPopMatrix();
}

void Ch4::drawCubes() {
	glColor3f(1, 1, 1);
	glutWireCube(10);

	glPushMatrix();
	{
		glTranslatef( potPos.x, potPos.y, potPos.z );
		glRotatef( potRot.x, 1, 0, 0 );
		glRotatef( potRot.y, 0, 1, 0 );
		glRotatef( potRot.z, 0, 0, 1 );
		float r = 0.5f;
		glBegin( GL_QUADS);

		// x
		glColor3f(1, 0, 0);
		glVertex3f(-r, -r, -r); // 1
		glVertex3f(-r,  r, -r); // 4
		glVertex3f( r,  r, -r); // 3
		glVertex3f( r, -r, -r); // 2

		// x - flipped z
		glColor3f(0, 0, 1);
		glVertex3f(-r, -r,  r); // 1 !z
		glVertex3f( r, -r,  r); // 2 !z
		glVertex3f( r,  r,  r); // 3 !z
		glVertex3f(-r,  r,  r); // 4 !z

		// z (x coords shifted left)
		glColor3f( 0, 1, 0 );
		glVertex3f(-r, -r, -r); // 1
		glVertex3f( r, -r, -r); // 4
		glVertex3f( r, -r,  r); // 3
		glVertex3f(-r, -r,  r); // 2

		// z - flipped y
		glColor3f( 1, 1, 0 );
		glVertex3f(-r,  r, -r); // 1
		glVertex3f(-r,  r,  r); // 2
		glVertex3f( r,  r,  r); // 3
		glVertex3f( r,  r, -r); // 4

		// y (z coords shifted left)
		glColor3f( 0, 1, 1 );
		glVertex3f(-r, -r, -r); // 1
		glVertex3f(-r, -r,  r); // 4
		glVertex3f(-r,  r,  r); // 3
		glVertex3f(-r,  r, -r); // 2

		// y - flipped x
		glColor3f( 1, 0, 1 );
		glVertex3f( r, -r, -r); // 1
		glVertex3f( r,  r, -r); // 2
		glVertex3f( r,  r,  r); // 3
		glVertex3f( r, -r,  r); // 4

		glEnd();
	}
	glPopMatrix();
}
