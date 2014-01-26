/*
 * ZGame.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef ZGAME_H_
#define ZGAME_H_

#include "ath/GLUtl.h"

class ZGame : public GAME_APP_ABSTRACTION_LAYER {

public:
	ZGame( const char* windowTitle, int screenWidth, int screenHeight );

private:
	virtual void init();
	virtual void update( float frameTime );
	virtual void render( float frameTime );

};

#endif /* ZGAME_H_ */
