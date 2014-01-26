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

	glShadeModel( GL_FLAT );
	glMaterialfv( GL_FRONT, GL_SPECULAR, CH4::mat_specular );
	glMaterialfv( GL_FRONT, GL_SHININESS, CH4::mat_shininess );
	glLightfv( GL_LIGHT0, GL_POSITION, CH4::white_light );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, CH4::white_light );
	glLightfv( GL_LIGHT0, GL_SPECULAR, CH4::light_position );
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, CH4::lmodel_ambient );

	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );

	camPos.x = 10;
	camPos.y = 10;
	camPos.z = 15; // -z extends into the monitor, +z towards the player

	camRot.x = 0;
	camRot.y = 0;
	camRot.z = 0;

	tcamPos.x = -10;
	tcamPos.y = -10;
	tcamPos.z = -15;

	ncamPos.x = 0;
	ncamPos.y = 1;
	ncamPos.z = 0;

	potPos.x = 0;
	potPos.y = 0;
	potPos.z = 0;

	potRot.x = 0;
	potRot.y = 0;
	potRot.z = 0;
}

void Ch4::update(float frameTime) {
//	potPos.y += frameTime;
//	potRot.z += frameTime * 30; // 30 degrees per second
//	potRot.x += frameTime * 30; // 30 degrees per second
	potRot.y -= frameTime * 30; // 30 degrees per second
//	camRot.z += frameTime * 30;

	potPos.x += frameTime * -0.2;

//	tcamPos.x = potPos.x;
//	tcamPos.y = potPos.y;
//	tcamPos.z = potPos.z;
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

	glLightfv( GL_LIGHT0, GL_POSITION, CH4::light_position );

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
		drawScene( frameTime );
	}
	glPopMatrix();
}

void Ch4::drawScene( float frameTime ) {
	drawRef();
	drawCubes();
	//			glutSolidSphere( 1, 32, 32 );
	//			glutSolidCube( 2 );
}

void Ch4::drawRef() {
	bool wasEnabled = glIsEnabled( GL_LIGHTING );
	if ( wasEnabled ) {
		glDisable( GL_LIGHTING );
	}

	glLineWidth( 5.0f );
	glBegin( GL_LINES );

		// X
		glColor3f( 1,0,0 );
		glVertex3f( 0, 0, 0 );
		glVertex3f( 1, 0, 0 );

		// Y
		glColor3f( 0,1,0 );
		glVertex3f( 0, 0, 0 );
		glVertex3f( 0, 1, 0 );

		// z
		glColor3f( 0,0,1 );
		glVertex3f( 0, 0, 0 );
		glVertex3f( 0, 0, 1 );

	glEnd();
	glLineWidth( 1.0f );

	if ( wasEnabled ) {
		glEnable( GL_LIGHTING );
	}
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

		GLUtl::solidCube( 2* r);
	}
	glPopMatrix();

	glDisable( GL_LIGHTING );
	glPushMatrix();
		glTranslatef( potPos.x, potPos.y, potPos.z );
		glRotatef( potRot.x, 1, 0, 0 );
		glRotatef( potRot.y, 0, 1, 0 );
		glRotatef( potRot.z, 0, 0, 1 );
		glutWireCube( 1 );
	glPopMatrix();
	glEnable( GL_LIGHTING );
}
