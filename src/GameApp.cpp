#include "GameApp.h"

#include <stdio.h>

GameApp::GameApp() {
}

GameApp::~GameApp() {
}

void GameApp::run(int width, int height) {
	float time = getTime();
	printf( "GameApp: %s @ %.2f\n", getWindowTitle(), time );
}

char* GameApp::getWindowTitle() {
	return "Game Title";
}

float GameApp::getTime() {
	return -1.0f;
}

void GameApp::init() {
}

void GameApp::update(float frameTime) {
}

void GameApp::render(float frameTime) {
}
