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
			wComponents[i][j] = KRandom::rBool(30) ? new Iron(Vector2(i ,j)) : nullptr;
		}
	}
}

WorldComponent* World::getWComponent(const Vector2& position) const {
	return getWComponent(position.X(), position.Y());
}

WorldComponent* World::getWComponent(int x, int y) const {
	if (wComponents && x < WORLD_SIZE && y < WORLD_SIZE && x >= 0 && y >= 0)
		return wComponents[x][y];
	return nullptr;
}

World::World(std::string name) {
	Generate();
}

World::~World() {
	if (wComponents) {
		for (int i = 0; i < WORLD_SIZE; ++i) {
			for (int j = 0; j < WORLD_SIZE; ++j) {
				delete wComponents[i][j];
			}
			delete[] wComponents[i];
		}
		delete[] wComponents;
	}
}
