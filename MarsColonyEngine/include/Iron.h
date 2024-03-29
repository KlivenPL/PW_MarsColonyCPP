#pragma once
#include "WorldComponent.h"
class Iron : public WorldComponent {
protected:
	void onDestroy() const override {
		std::cout << getName() << " was destroyed." << std::endl;
	};
public:
	 std::string getName() const override { return "Iron ore"; }
	 Iron(Vector2 position) : WorldComponent(position) {};
};