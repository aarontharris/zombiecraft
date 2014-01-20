/*
 * SDLGameApp.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef SDLGAMEAPP_H_
#define SDLGAMEAPP_H_

#include "GameApp.h"

class SDLGameApp : public GameApp {

public:
	SDLGameApp();
	virtual void run( int width, int height );
	virtual float getTime();

};


#endif /* SDLGAMEAPP_H_ */
