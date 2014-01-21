/*
 * ZGame.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef ZGAME_H_
#define ZGAME_H_

#define USE_SDL true
#define USE_GLFW false

#if USE_SDL == true
#include "SDLGameApp.h"
#endif
#if USE_GLFW == true
#include "GLFWGameApp.h"
#endif

#if USE_SDL == true
class ZGame : public SDLGameApp {
#endif

#if USE_GLFW == true
class ZGame : public GLFWGameApp {
#endif

	virtual char* getWindowTitle();
	virtual void init();
	virtual void update( float frameTime );
	virtual void render( float frameTime );

};

#endif /* ZGAME_H_ */
