/*
 * main.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#include "ZGame.h"

int main( int argc, char *argv[] ) {

	GameApp *game = new ZGame( "Blah", 1440, 900 );
	game->run();

}



