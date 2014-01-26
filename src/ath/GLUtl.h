/*
 * Utl.h
 *
 *  Created on: Jan 25, 2014
 *      Author: aarontharris
 */

#ifndef GLUTL_H_
#define GLUTL_H_

#include <SDL.h>
#include <glut.h>
#include <gl3ext.h>
#include "Vector3f.h"

/* Define which abstraction layer to use here */
#define GAME_APP_ABSTRACTION_LAYER SDLGameApp // The name of the GameApp derived class to use
//#define GAME_APP_ABSTRACTION_LAYER GLFWGameApp // The name of the GameApp derived class to use

#if USE_SDL == SDLGameApp
#include "SDLGameApp.h"
#endif
#if USE_GLFW == GLFWGameApp
#include "GLFWGameApp.h"
#endif

class GLUtl {
public:
	GLUtl();

	static void solidCube( float diameter );
};

#endif /* GLUTL_H_ */
