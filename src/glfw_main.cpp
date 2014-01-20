//#include <glu.h>
//#include <glut.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//#include "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers/gl.h"
//
//typedef struct {
//	float x, y, z;
//} Vector3f;
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
///* Global Member Variables */
//GLFWwindow* window;
//Vector3f camPos; // camera position
//Vector3f camRot; // camera normal
//Vector3f tcamPos; // camera target position
//Vector3f ncamPos; // camera normal
//Vector3f potPos; // pot position
//Vector3f potRot; // pot rotation
//bool firstRender = true;
//
///* Global Member Functions */
//void init();
//void update(float frameTime);
//void render(float frameTime);
//
//void drawTeapot();
//void drawCubes();
//
//int main(void) {
//	glfwSetErrorCallback(error_callback);
//	if (!glfwInit()) {
//		exit(EXIT_FAILURE);
//	}
//
//	window = glfwCreateWindow(1440, 900, "Simple example", NULL, NULL);
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
//void init() {
//	camPos.x = 0;
//	camPos.y = 0;
//	camPos.z = 15; // -z extends into the monitor, +z towards the player
//
//	camRot.x = 0;
//	camRot.y = 0;
//	camRot.z = 45;
//
//	tcamPos.x = 0;
//	tcamPos.y = 0;
//	tcamPos.z = 0;
//
//	ncamPos.x = 0;
//	ncamPos.y = 1;
//	ncamPos.z = 0;
//
//	potPos.x = 0;
//	potPos.y = -5;
//	potPos.z = 0;
//
//	potRot.x = 0;
//	potRot.y = 0;
//	potRot.z = 0;
//}
//
//void update(float frameTime) {
//	potPos.y += frameTime;
//	potRot.z += frameTime * 30; // 30 degrees per second
//	camRot.z += frameTime * 30;
//
//	tcamPos.x = potPos.x;
//	tcamPos.y = potPos.y;
//	tcamPos.z = potPos.z;
//}
//
//void render(float frameTime) {
//	float ratio;
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	ratio = width / (float) height;
//
//	float fps = 1 / frameTime;
//
//	fprintf( stdout, "FPS: %f, FrameTime: %f\n", fps, frameTime);
//
//	// Setup our camera
//	{
//		glViewport(0, 0, width, height);
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluPerspective(50.0f, ratio, 0.1f, 100.0f);
//		glMatrixMode(GL_MODELVIEW);
//		glClear(GL_COLOR_BUFFER_BIT);
//	}
//
//	// the camera's matrix
//	glPushMatrix();
//	{
//		// Rotate space for camera
//		glRotatef(camRot.x, 1, 0, 0);
//		glRotatef(camRot.y, 0, 1, 0);
//		glRotatef(camRot.z, 0, 0, 1);
//
//		// Look after rotation
//		gluLookAt( //
//				camPos.x, camPos.y, camPos.z, // camera position
//				tcamPos.x, tcamPos.y, tcamPos.z, // target position
//				ncamPos.x, ncamPos.y, ncamPos.z // camera up
//				);
//
//		// Draw the world in the same root matrix to adopt camera rotation, etc
//		{
//			// push cube data to server only once
//			// FIXME: i should implement a validation system and only push when invalidated
//			if (firstRender) {
////				firstRender = false;
//				drawCubes();
//			}
//
//			drawTeapot();
//		}
//	}
//	glPopMatrix();
//}
//
//void drawTeapot() {
//	glPushMatrix();
//
//	glTranslatef(potPos.x, potPos.y, potPos.z);
//	glRotatef(potRot.x, 1, 0, 0);
//	glRotatef(potRot.y, 0, 1, 0);
//	glRotatef(potRot.z, 0, 0, 1);
//	glutWireTeapot(0.5);
//
//	glPopMatrix();
//}
//
//int wCubes = 10;
//int hCubes = 10;
//int dCubes = 10;
//int cubeSize = .5;
//
//void drawCubes() {
//	fprintf( stdout, "drawCubes\n");
//	glPushMatrix();
//
////	float size = 9;
//
////	for ( int x = 0; x < 3000; x++ ) {
//	glutWireCube(10);
////	}
////	glutWireCube(10);
//
////	float xOrg = -1 * wCubes * cubeSize;
////
////	Vector3f origin;
////	origin.x = 0;
////	origin.y = 0;
////	origin.z = 0;
////
////
////	for ( int xIdx = 0; xIdx < wCubes; xIdx++ ) {
////		glPushMatrix();
////		float xPos = origin.x + xIdx * cubeSize;
////		glTranslatef(xPos, origin.y, origin.z);
////		glutWireCube(cubeSize);
////		glPopMatrix();
////	}
//
//	glPopMatrix();
//}
