#pragma once
#include "WorldComponent.h"

class World {
private:
	std::string name;
	// 2D dynamic array of world components
	WorldComponent*** wComponents = nullptr;
	void Generate();
public:
	const int WORLD_SIZE = 50;
	WorldComponent* getWComponent(Vector2<int> position) const;
	WorldComponent* getWComponent(int x, int y) const;
	World(std::string name);
};