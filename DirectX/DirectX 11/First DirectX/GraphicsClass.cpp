#include "GraphicsClass.h"

GraphicsClass::GraphicsClass() {}

GraphicsClass::GraphicsClass(const GraphicsClass& other) {}

GraphicsClass::~GraphicsClass() {}

bool GraphicsClass::Init(int screenWidth, int screenHeight, HWND hWNd) {
	return true;
}

void GraphicsClass::ShutDown() {}


bool GraphicsClass::Frame() {
	return true;
}

bool GraphicsClass::Render() {
	return true;
}
