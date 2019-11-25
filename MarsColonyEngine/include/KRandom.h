#pragma once
#include "pch.h"
#include <time.h>
#include <cstdlib>

class KRandom {
public:
	//Init(0) for random seed
	static void Init(int seed) {
		if (seed != 0) {
			srand(seed);
			return;
		}
		for (int i = 0; i < 50; i++){
			srand(time(NULL));
		}
	}
	static int rInt(int min, int max){ int randNum = rand() % (max - min + 1) + min; }
	static float rFloat(float a, float b) {
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = b - a;
		float r = random * diff;
		return a + r;
	}
	static float rFloat01() {
		return ((float)rand()) / (float)RAND_MAX;
	}
	static bool rBool(int chancesPercent = 50) {
		return rFloat01() <= chancesPercent / 100.0f;
	}
};