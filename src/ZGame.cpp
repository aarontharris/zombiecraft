/*
 * ZGame.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#include "ZGame.h"

char* ZGame::getWindowTitle() {
	return "Zombie Game";
}

void ZGame::init() {
}

void ZGame::update( float frameTime ) {
}

void ZGame::render( float frameTime ) {
	glClear( GL_COLOR_BUFFER_BIT );
	printf("ZGame::render %.2f\n", frameTime);
}

