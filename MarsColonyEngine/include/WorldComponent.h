#pragma once
#include "pch.h"
class WorldComponent : public Destructable {
private:
	Vector2 position;
protected:
	WorldComponent(Vector2 position, float hp = 100.0f) : position(position), Destructable(hp) {}
public:
	virtual std::string getName() const = 0;
	Vector2 getPosition() const { return position; }
};