/*
 * main.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#include "ZGame.h"

int main( int argc, char *argv[] ) {

	GameApp *game = new ZGame();
	game->run( 800, 600 );

}



