#include "GameApp.h"

#include <stdio.h>

GameApp::GameApp( const char* windowTitle, int screenWidth, int screenHeight ) {
	this->windowTitle = windowTitle;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

GameApp::~GameApp() {
}

void GameApp::run() {
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

const char* GameApp::getWindowTitle() {
	return this->windowTitle;
}

int GameApp::getScreenWidth() {
	return this->screenWidth;
}

int GameApp::getScreenHeight() {
	return this->screenHeight;
}
