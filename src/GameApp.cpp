#include "GameApp.h"

#include <SDL.h>
#include <glut.h>
#include <gl3ext.h>

GameApp::GameApp() {
}

GameApp::~GameApp() {
}

void GameApp::run(int width, int height) {
	float time = getTime();
	printf( "Window: %s @ %.2f\n", getWindowTitle(), time );
}

char* GameApp::getWindowTitle() {
	return "Game Title";
}

float GameApp::getTime() {
	return (float) SDL_GetTicks() / 1000.0f;
}

void GameApp::init() {
}

void GameApp::update(float frameTime) {
}

void GameApp::render(float frameTime) {
}
