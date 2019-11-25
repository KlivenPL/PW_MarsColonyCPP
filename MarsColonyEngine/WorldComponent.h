#pragma once
#include "pch.h"

class WorldComponent {
private:
	Vector2<int> position;
public:
	virtual std::string getName() const = 0;
	Vector2<int> getPosition() const { return position; }
};