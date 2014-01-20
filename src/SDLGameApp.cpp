/*
 * SDLGameApp.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#include "SDLGameApp.h"

#include <stdio.h>

SDLGameApp::SDLGameApp() : GameApp() {
}

void SDLGameApp::run( int width, int height ) {
	GameApp::run( width, height );
	printf( "Hello from SDLGameApp %s\n", getWindowTitle() );
}

float SDLGameApp::getTime() {
	return 5.0f; //(float) SDL_GetTicks() / 1000.0f;
}


