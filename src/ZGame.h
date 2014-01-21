/*
 * ZGame.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef ZGAME_H_
#define ZGAME_H_

/* Define which abstraction layer to use here */
#define GAME_APP_ABSTRACTION_LAYER SDLGameApp // The name of the GameApp derived class to use
//#define GAME_APP_ABSTRACTION_LAYER GLFWGameApp // The name of the GameApp derived class to use

#if USE_SDL == SDLGameApp
#include "SDLGameApp.h"
#endif
#if USE_GLFW == GLFWGameApp
#include "GLFWGameApp.h"
#endif

class ZGame : public GAME_APP_ABSTRACTION_LAYER {

public:
	ZGame( const char* windowTitle, int screenWidth, int screenHeight );

private:
	virtual void init();
	virtual void update( float frameTime );
	virtual void render( float frameTime );

};

#endif /* ZGAME_H_ */
