#include "pch.h"
#include "World.h"
#include "Iron.h"
#include <Action.h>


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

void World::registerActions() {
	Action* createWorldAction = new Action(ActionType::GenerateWorld, "Genrate world",
		new ActionProcedure(
			[](auto &handler, auto outStr) -> bool {
				if (typeid(handler) != typeid(World)) {
					outStr = "Generate World action can be called on World instance only.";
					return false;
				}
				return true;
			},

			[](auto &handler, auto outStr, auto args) -> bool {
				World& world = dynamic_cast<World&>(handler);
				world.Generate();
				outStr = "World generated successfully";
				return true;
			}));
	Action::registerAction(createWorldAction);
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
	this->name = name;
	registerActions(); // TODO to zablokowac + enkapsulacja LIB
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
