/*
 * GLFWGameApp.h
 *
 *  Created on: Jan 20, 2014
 *      Author: aarontharris
 */

#ifndef GLFWGAMEAPP_H_
#define GLFWGAMEAPP_H_

#include "GameApp.h"

#include <glu.h>
#include <glut.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

class GLFWGameApp: public GameApp {

public:
	GLFWGameApp();
	virtual ~GLFWGameApp();

};

#endif /* GLFWGAMEAPP_H_ */
