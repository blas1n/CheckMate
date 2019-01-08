#pragma once

#include "Object.h"
#include "Sprite.h"
#include "Renderer.h"

class Player : public Object {
protected:
	virtual void InitComponents(ComponentList*& componentList) override {
		componentList = new ComponentList{ new Renderer() };
	}
};

