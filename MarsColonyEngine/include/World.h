#pragma once
#include "WorldComponent.h"
#include "Vector2.h"
#include "IActionHandler.h"
class World : public IActionHandler {
private:
	std::string name;
	// 2D dynamic array of world components
	WorldComponent*** wComponents = nullptr;
	void Generate();
	void registerActions() override;
public:
	std::string getActionHandlerName() const override { return "World"; };
	const int WORLD_SIZE = 50;
	WorldComponent* getWComponent(const Vector2& position) const;
	WorldComponent* getWComponent(int x, int y) const;
	std::string getName() const { return name; }
	World(std::string name);
	~World();
};