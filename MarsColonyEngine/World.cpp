#include "pch.h"
#include "World.h"
#include "Iron.h"


void World::Generate() {
	wComponents = (WorldComponent***) new WorldComponent**[50];
	for (int i = 0; i < WORLD_SIZE; ++i) {
		wComponents[i] = (WorldComponent**) new WorldComponent*[50];
	}

	for (int i = 0; i < WORLD_SIZE; ++i) {
		for (int j = 0; j < WORLD_SIZE; ++j) {
			wComponents[i][j] = KRandom::rBool(30) ? new Iron() : nullptr;
		}
	}
}

WorldComponent* World::getWComponent(Vector2<int> position) const {
	return getWComponent(position.x, position.y);
}

WorldComponent* World::getWComponent(int x, int y) const {
	if (wComponents && x < WORLD_SIZE && y < WORLD_SIZE && x >= 0 && y >= 0)
		return wComponents[x][y];
	return nullptr;
}

World::World(std::string name) {
	Generate();
}
