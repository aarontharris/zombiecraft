/*
 * GameApp.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef GAMEAPP_H_
#define GAMEAPP_H_

class GameApp {
private:
	int screenWidth;
	int screenHeight;

public:
	GameApp();
	virtual ~GameApp();

	virtual void run( int width, int height );

protected:
	virtual char* getWindowTitle();
	virtual float getTime();
	virtual void init();
	virtual void update( float frameTime );
	virtual void render( float frameTime );

	int getScreenWidth();
	int getScreenHeight();

};


#endif /* GAMEAPP_H_ */
