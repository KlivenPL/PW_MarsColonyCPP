#pragma once
#include "WorldComponent.h"

class Ore : public WorldComponent {
private:
	std::string name;
protected:
	void onDestroy() const override {
		std::cout << getName() << " was destroyed." << std::endl;
	};
public:
	std::string getName() const override { return name + " ore"; }
};