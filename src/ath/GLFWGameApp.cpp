///*
// * GLFWGameApp.cpp
// *
// *  Created on: Jan 20, 2014
// *      Author: aarontharris
// */
//
//#include "GLFWGameApp.h"
//
//// error
//static void error_callback(int error, const char* description) {
//	fputs(description, stderr);
//}
//
//// input
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}
//
//GLFWwindow* window;
//
//GLFWGameApp::GLFWGameApp(const char* windowTitle, int screenWidth, int screenHeight) :
//		GameApp(windowTitle, screenWidth, screenHeight) {
//	printf("GLFWGameApp::constructor %d x %d\n", getScreenWidth(), getScreenHeight());
//}
//
//void GLFWGameApp::run() {
//	glfwSetErrorCallback(error_callback);
//	if (!glfwInit()) {
//		exit(EXIT_FAILURE);
//	}
//
//	// FIXME: GLFW weird screensize hack
//	// for some reason the viewport was only 1/2 of the window for GLFW
//	// I think it may have something to do with the retina screen automagic scaling?
//	// We set the getScreenWidth and getScreenHeight methods to return 2x for the later viewport
//	// and we 1/2 it here for the window.
//	int width = getScreenWidth() / 2;
//	int height = getScreenHeight() / 2;
//
//	printf("GLFWGameApp::run %d x %d\n", width, height );
//	window = glfwCreateWindow(width, height, getWindowTitle(), NULL, NULL);
//	if (!window) {
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	// Attach the window
//	glfwMakeContextCurrent(window);
//
//	// Set Callback for input actions
//	glfwSetKeyCallback(window, key_callback);
//
//	init();
//
//	float lastFrameStart = glfwGetTime();
//	while (!glfwWindowShouldClose(window)) {
//		float thisFrameStart = glfwGetTime();
//		float frameTime = thisFrameStart - lastFrameStart;
//
//		update(frameTime);
////		glfwGetFramebufferSize(window, &width, &height);
//		render(frameTime);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//		lastFrameStart = thisFrameStart;
//	}
//
//	glfwDestroyWindow(window);
//	glfwTerminate();
//	exit(EXIT_SUCCESS);
//}
//
//float GLFWGameApp::getTime() {
//	return glfwGetTime();
//}
//
//int GLFWGameApp::getScreenWidth() {
//	return 2 * GameApp::getScreenWidth();
//}
//
//int GLFWGameApp::getScreenHeight() {
//	return 2 * GameApp::getScreenHeight();
//}
