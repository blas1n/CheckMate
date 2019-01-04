#pragma once

#include "Scene.h"
#include "Player.h"

class TitleScene : public Scene {
private:
	virtual void InitObjects(ObjectList*& objectList) override {
		objectList = new ObjectList{ new Player() };
	}
};