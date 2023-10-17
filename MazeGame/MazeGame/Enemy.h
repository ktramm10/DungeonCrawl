#pragma once

class Enemy {
public:
	int GetHealth() { return health; }
	void SetHealth(int i) { health = i; }
	virtual void Attack(Explorer* e) = 0;
protected:
private:
	int health;
};