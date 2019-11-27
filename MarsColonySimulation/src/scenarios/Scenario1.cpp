//#include "pch.h"
#include <World.h>
#include <vector>
#include <functional>
#include <Action.h>
using namespace std;
class Scenario1 {
private:
	World *world;

public:
	void execute() {
		KRandom::Init(2019);

		world = new World("xd");
		std::string outStr;
		Action::execute(ActionType::GenerateWorld, *world, outStr);
		auto world2 = new World("xd2");
		Action::execute(ActionType::GenerateWorld, *world2, outStr);
	}
};