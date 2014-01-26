/*
 * GameApp.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef GAMEAPP_H_
#define GAMEAPP_H_

/* Abstract -- see SDLGameApp or GLFWGameApp */
class GameApp {
private:
	int screenWidth;
	int screenHeight;
	const char* windowTitle;

public:
	GameApp( const char* windowTitle, int screenWidth, int screenHeight );
	virtual ~GameApp();

	virtual void run();

protected:
	virtual float getTime();
	virtual void init();
	virtual void update( float frameTime );
	virtual void render( float frameTime );

	const char* getWindowTitle();
	int getScreenWidth();
	int getScreenHeight();

};


#endif /* GAMEAPP_H_ */
