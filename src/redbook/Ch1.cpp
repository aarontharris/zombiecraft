/*
 * Ch1.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: aarontharris
 */

#include "Ch1.h"

#include <gl.h>
#include <glu.h>
#include <glext.h>
#include <glut.h>

#include <stdlib.h>
#include <stdio.h>

Ch1::Ch1() {
}

Ch1::~Ch1() {
}

GLfloat spin = 0.0;

void init() {
	printf("init\n");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel( GL_FLAT);
}

void display() {
	printf("display\n");
	glClear( GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	{
		glRotatef(spin, 0.0, 0.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		glRectf(-25.0, -25.0, 25.0, 25.0);
	}
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay() {
	printf("spinDisplay\n");
	spin = spin + 2.0;
	if (spin > 360.0) {
		spin = spin - 360.0;
	}
	glutPostRedisplay();
}

void noOp() {
}

void reshape(int w, int h) {
	printf("reshape\n");
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode( GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0 ); // , 1.0, 1.0);
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	printf("keyboard %c, %d, %d\n", key, x, y);
	fflush(stdout); // show in log right away

	switch (key) {
	case 27: // escape
		exit(0);
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y) {
	printf("mouse\n");
	switch (button) {
	case GLUT_LEFT_BUTTON:
		printf("mouse: LEFT BUTTON\n");
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;

	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(noOp);
		break;

	case 27: // ESCAPE
		exit(0);
		break;
	default:
		break;
	}
}

void Ch1::run() {
	printf("run\n");
	int argc = 0;
	char* argv = "asdf";
	glutInit(&argc, &argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Our GLUT Window");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
