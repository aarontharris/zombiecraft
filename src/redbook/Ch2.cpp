/*
 * Ch2.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#include "Ch2.h"

#define blitArray(size,src,dst) for(int i=0; i<size;i++){dst[i]=src[i];}

// GAME_APP is a #define that points to the impl for SDL,GLFW, etc
Ch2::Ch2(const char* windowTitle, int screenWidth, int screenHeight) :
		GAME_APP_ABSTRACTION_LAYER(windowTitle, screenWidth, screenHeight) {
	wCubes = 10;
	hCubes = 10;
	dCubes = 10;
	cubeSize = .5;
	cubeOrigin.x = 0;
	cubeOrigin.y = 0;
	cubeOrigin.z = 0;

	r = 1.0f;

	GLfloat _cubeVerts[72] = {
			-r, -r, -r,
			 r, -r, -r,
			 r,  r, -r,
			-r,  r, -r,

			-2*r, -r, -r,
			 2*r, -r, -r,
			 2*r,  r, -r,
			-2*r,  r, -r,

			-3*r, -r, -r,
			 3*r, -r, -r,
			 3*r,  r, -r,
			-3*r,  r, -r,

			-4*r, -r, -r,
			 4*r, -r, -r,
			 4*r,  r, -r,
			-4*r,  r, -r,

			-5*r, -r, -r,
			 5*r, -r, -r,
			 5*r,  r, -r,
			-5*r,  r, -r,

			-6*r, -r, -r,
			 6*r, -r, -r,
			 6*r,  r, -r,
			-6*r,  r, -r,
	};
	blitArray( 72, _cubeVerts, cubeVerts );

	GLuint _cubeIndices[24] = {
			 0, 1, 2, 3,
			 4, 5, 6, 7,
			 8, 9,10,11,
			12,13,14,15,
			16,17,18,19,
			20,21,22,23
	};
	blitArray( 24, _cubeIndices, cubeIndices );

}

void Ch2::init() {
	glEnable( GL_CULL_FACE );
	glFrontFace( GL_CCW );
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

	glGenBuffers( CH2_bufferCount, buffers);
	glBindBuffer( GL_ARRAY_BUFFER, buffers[CH2_cubeVertBufferIdx]);
	glBufferData( GL_ARRAY_BUFFER, sizeof(cubeVerts), cubeVerts, GL_STATIC_DRAW); // TODO consider GL_DYNAMIC_DRAW for editability?
	glVertexPointer(3, GL_FLOAT, 0, (void *) (0));
	glEnableClientState( GL_VERTEX_ARRAY);
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffers[CH2_cubeIndicesBufferIdx]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);
}

void Ch2::update(float frameTime) {
	potPos.y += frameTime;
	potRot.z += frameTime * 30; // 30 degrees per second
	camRot.z += frameTime * 30;

	tcamPos.x = potPos.x;
	tcamPos.y = potPos.y;
	tcamPos.z = potPos.z;
}

void Ch2::render(float frameTime) {
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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
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
			drawCubes();
//			drawCubesBetter();
//			drawTeapot();
		}
	}
	glPopMatrix();
}

void Ch2::drawTeapot() {
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

void Ch2::drawCubes() {
	glPushMatrix();

	glTranslatef(cubeOrigin.x, cubeOrigin.y, cubeOrigin.z);

	for (int i = 0; i < 10000; i++) {

		glBegin( GL_QUADS);
		for (int x = 0; x <= 1; x++) {
			for (int y = 0; y <= 1; y++) {
				glVertex3f(-x * r, -y * r, -r);
				glVertex3f(x * r, -y * r, -r);
				glVertex3f(x * r, y * r, -r);
				glVertex3f(-x * r, y * r, -r);
			}
		}
		glEnd();

	}

	glPopMatrix();
}

void Ch2::drawCubesBetter() {
//	glBindBuffer( GL_ARRAY_BUFFER, buffers[cubeVertBufferIdx]);
//	glBufferData( GL_ARRAY_BUFFER, sizeof(cubeVerts), cubeVerts, GL_STATIC_DRAW); // TODO consider GL_DYNAMIC_DRAW for editability?
//	glVertexPointer(3, GL_FLOAT, 0, (void *) (0));
//	glEnableClientState( GL_VERTEX_ARRAY);
//	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffers[cubeIndicesBufferIdx]);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);

//	glPushMatrix();
//	glTranslatef( 0, 0, -50 );
//	glutSolidCube(50);
//	glPopMatrix();
//	glDrawArraysInstancedARB( GL_QUADS, 0, 72, 1 );
	glDrawArrays( GL_QUADS, 0, 72);
//	glDrawElements( GL_QUADS, 24, GL_UNSIGNED_BYTE, (void*) (0));  // better
//	glDrawElementsInstanced( GL_QUADS, 12, GL_UNSIGNED_BYTE, (void*) (0));  // better
//	glDrawElementsInstancedARB()
//	glDrawElementsInstancedARB( GL_QUADS, 12, GL_UNSIGNED_BYTE, )

}
