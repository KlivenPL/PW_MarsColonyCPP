#pragma once
#include "WorldComponent.h"
#include "Vector2.h"
class World {
private:
	std::string name;
	// 2D dynamic array of world components
	WorldComponent*** wComponents = nullptr;
	void Generate();
public:
	const int WORLD_SIZE = 50;
	WorldComponent* getWComponent(const Vector2& position) const;
	WorldComponent* getWComponent(int x, int y) const;
	std::string getName() const { return name; }
	World(std::string name);
	~World();
};