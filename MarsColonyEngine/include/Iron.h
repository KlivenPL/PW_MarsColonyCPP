#pragma once
#include "WorldComponent.h"
class Iron : public WorldComponent {
public:
	 std::string getName() const override { return "Iron ore"; }
	 Iron(Vector2 position) : WorldComponent(position) {};
};

