#ifndef __GRAPHICSCLASS_H__
#define __GRAPHICSCLASS_H__

#include <Windows.h>

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass {
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Init(int, int, HWND);
	void ShutDown();
	bool Frame();
private:
	bool Render();
};

#endif