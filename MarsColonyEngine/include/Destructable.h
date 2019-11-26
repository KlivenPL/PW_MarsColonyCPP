#pragma once
class Destructable {
private:
	float hp;
	Destructable();

protected:
	void virtual onDestroy() const = 0;
public:
	Destructable(float startHp = 100.0f) { hp = startHp; }
	float getHp() const { return hp; }
	void doDamage(float damage) {
		hp -= damage;
		if (hp <= 0) {
			hp = 0;
			onDestroy();
		}
	}
};