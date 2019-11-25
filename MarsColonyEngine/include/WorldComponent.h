#pragma once
#include "pch.h"
#include "Vector2.h"
class WorldComponent {
private:
	Vector2 position;
protected:
	WorldComponent(Vector2 position) : position(position){}
public:
	virtual std::string getName() const = 0;
	Vector2 getPosition() const { return position; }
};