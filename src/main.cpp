/*
 * main.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

//#include "ZGame.h"
//#include "redbook/Ch2.h"
#include "redbook/Ch4.h"


int main( int argc, char *argv[] ) {

//	GameApp *game = new ZGame( "Blah", 1440, 900 );
//	Ch1 *game = new Ch1();
//	Ch2 *game = new Ch2( "Ch2", 1440, 900 );
	Ch4 *game = new Ch4( "Ch4", 1440, 900 );

	game->run();

}



