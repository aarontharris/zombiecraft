/*
 * ZGame.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef CH2_H_
#define CH2_H_

/* Define which abstraction layer to use here */
#define GAME_APP_ABSTRACTION_LAYER SDLGameApp // The name of the GameApp derived class to use
//#define GAME_APP_ABSTRACTION_LAYER GLFWGameApp // The name of the GameApp derived class to use

#if USE_SDL == SDLGameApp
#include "../SDLGameApp.h"
#endif
#if USE_GLFW == GLFWGameApp
#include "../GLFWGameApp.h"
#endif

#include "../Vector3f.h"

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

	int wCubes = 10;
	int hCubes = 10;
	int dCubes = 10;
	int cubeSize = .5;
	Vector3f cubeOrigin = { 0, 0, 0 };

#define cubeVertBufferIdx 0
#define cubeIndicesBufferIdx 1
#define bufferCount 2 // cubeVertBuffer and cubeIndicesBuffer
	GLuint buffers[bufferCount];

	float r = 1.0f;
	GLfloat cubeVerts[72] = {
			-r, -r, -r,
			 r, -r, -r,
			 r,  r, -r,
			-r,  r, -r,

			-2*r, -r, -r,
			 2*r, -r, -r,
			 2*r,  r, -r,
			-2*r,  r, -r,

			-3*r, -r, -r,
			 3*r, -r, -r,
			 3*r,  r, -r,
			-3*r,  r, -r,

			-4*r, -r, -r,
			 4*r, -r, -r,
			 4*r,  r, -r,
			-4*r,  r, -r,

			-5*r, -r, -r,
			 5*r, -r, -r,
			 5*r,  r, -r,
			-5*r,  r, -r,

			-6*r, -r, -r,
			 6*r, -r, -r,
			 6*r,  r, -r,
			-6*r,  r, -r,
	};

	GLuint cubeIndices[24] = {
			 0, 1, 2, 3,
			 4, 5, 6, 7,
			 8, 9,10,11,
			12,13,14,15,
			16,17,18,19,
			20,21,22,23
	};
//
//#define cubeVert2BufferIdx 0
//#define cubeIndices2BufferIdx 1
//#define buffer2Count 2 // cubeVertBuffer and cubeIndicesBuffer
//	GLuint buffers2[buffer2Count];
//	GLfloat *cubeVerts2;
//	GLuint *cubeIndices2;
//	int numDatas;
//
};

#endif /* CH2_H_ */
