/*
 * main.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#include "SDLGameApp.h"

int main( int argc, char *argv[] ) {

	GameApp *game = new SDLGameApp();
	game->run( 800, 600 );

}



