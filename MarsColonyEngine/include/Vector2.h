#pragma once
class Vector2
{
private:
	int x, y;
public :
	int X() const { return x; }
	int Y() const { return y; }

	Vector2(int x, int y) : x(x), y(y) {}
};

