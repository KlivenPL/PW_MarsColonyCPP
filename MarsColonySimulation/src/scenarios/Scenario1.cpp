#include <World.h>
class Scenario1 {
private:
	World *world;

	void createNewWorld() {
		world = new World("Scenario 1 World");
	}
public:
	void execute() {
		KRandom::Init(2019);
		createNewWorld();
	}
};