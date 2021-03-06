/*
 * ZGame.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef CH4_H_
#define CH4_H_

/* Define which abstraction layer to use here */
#define GAME_APP_ABSTRACTION_LAYER SDLGameApp // The name of the GameApp derived class to use

#include "../ath/GLUtl.h"

namespace CH4 {
	const GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	const GLfloat mat_shininess[] = { 50.0 };
	const GLfloat light_position[] = {  10.0,  0.0, 15.0, 0.0 };
	const GLfloat white_light[] = { 1.0, 1.0, 1.0, 0.0 };
	const GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 0.0 };
}

class Ch4: public GAME_APP_ABSTRACTION_LAYER {

public:
	Ch4(const char* windowTitle, int screenWidth, int screenHeight);

private:
	virtual void init();
	virtual void update(float frameTime);
	virtual void render(float frameTime);
	virtual void drawScene(float frameTime);

	void drawCubes();
	void drawRef();

	Vector3f camPos; // camera position
	Vector3f camRot; // camera normal
	Vector3f tcamPos; // camera target position
	Vector3f ncamPos; // camera normal
	Vector3f potPos; // pot position
	Vector3f potRot; // pot rotation

};

#endif /* CH4_H_ */
