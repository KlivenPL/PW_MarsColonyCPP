#include <iostream>

#include "World.h"
#include "pch.h"
#include "Vector2.h"
#include "scenarios/Scenario1.cpp"

using namespace std;
int main() {
	Scenario1* scenario1 = new Scenario1();
	scenario1->execute();
}
