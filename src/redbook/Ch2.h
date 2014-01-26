/*
 * ZGame.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef CH2_H_
#define CH2_H_

#include "../ath/GLUtl.h"

#define CH2_cubeVertBufferIdx 0
#define CH2_cubeIndicesBufferIdx 1
#define CH2_bufferCount 2 // cubeVertBuffer and cubeIndicesBuffer

class Ch2: public GAME_APP_ABSTRACTION_LAYER {

public:
	Ch2(const char* windowTitle, int screenWidth, int screenHeight);

private:
	virtual void init();
	virtual void update(float frameTime);
	virtual void render(float frameTime);

	void drawTeapot();
	void drawCubes();
	void drawCubesBetter();

	Vector3f camPos; // camera position
	Vector3f camRot; // camera normal
	Vector3f tcamPos; // camera target position
	Vector3f ncamPos; // camera normal
	Vector3f potPos; // pot position
	Vector3f potRot; // pot rotation

	int wCubes;
	int hCubes;
	int dCubes;
	int cubeSize;
	Vector3f cubeOrigin;

	GLuint buffers[CH2_bufferCount];

	float r;

	GLfloat cubeVerts[72];
	GLuint cubeIndices[24];

};

#endif /* CH2_H_ */
