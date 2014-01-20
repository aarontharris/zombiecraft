/*
 * ZGame.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef ZGAME_H_
#define ZGAME_H_

#include "SDLGameApp.h"

class ZGame : public SDLGameApp {

	virtual char* getWindowTitle();
	virtual void init();
	virtual void update( float frameTime );
	virtual void render( float frameTime );

};

#endif /* ZGAME_H_ */
