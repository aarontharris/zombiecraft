/*
 * GLUtl.cpp
 *
 *  Created on: Jan 25, 2014
 *      Author: aarontharris
 */

#include "GLUtl.h"

GLUtl::GLUtl() {
}

void GLUtl::solidCube( float diameter ) {
	float r = diameter / 2;

	glBegin( GL_QUADS);

	glNormal3f(  0,  0, -1 ); // facing backward -- backward is -Z (into monitor)
	glVertex3f( -r, -r, -r );
	glVertex3f( -r,  r, -r );
	glVertex3f(  r,  r, -r );
	glVertex3f(  r, -r, -r );

	glNormal3f(  0,  0,  1 ); // facing forward -- forward is +Z (towards eye)
	glVertex3f( -r, -r,  r );
	glVertex3f(  r, -r,  r );
	glVertex3f(  r,  r,  r );
	glVertex3f( -r,  r,  r );

	glNormal3f(  1,  0,  0 ); // facing right -- the object's right
	glVertex3f(  r, -r,  r );
	glVertex3f(  r, -r, -r );
	glVertex3f(  r,  r, -r );
	glVertex3f(  r,  r,  r );

	glNormal3f( -1,  0,  0 ); // facing left -- the object's left
	glVertex3f( -r, -r,  r );
	glVertex3f( -r,  r,  r );
	glVertex3f( -r,  r, -r );
	glVertex3f( -r, -r, -r );

	glNormal3f(  0,  1,  0 ); // facing up -- the object's up
	glVertex3f( -r,  r,  r );
	glVertex3f(  r,  r,  r );
	glVertex3f(  r,  r, -r );
	glVertex3f( -r,  r, -r );

	glNormal3f(  0, -1,  0 ); // facing down -- the object's down
	glVertex3f( -r, -r,  r );
	glVertex3f( -r, -r, -r );
	glVertex3f(  r, -r, -r );
	glVertex3f(  r, -r,  r );

	glEnd();
}
