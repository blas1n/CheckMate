#pragma once

#include "Scene.h"
#include "Object.h"

class TitleScene : public Scene {
private:
	virtual void InitObjects(ObjectList& objectList) override {
		objectList = { new Object() };
	}
};