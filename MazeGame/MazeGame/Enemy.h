#pragma once
#include "Explorer.h"
#include "Coin.h"
#include <string>

class Enemy {
public:
	Enemy();
	int GetHealth() { return health; }
	void SetHealth(int i) { health = i; }
	virtual void Attack(Explorer* e) = 0;
	virtual void Die() = 0;
	bool GetIsAlive() { return isAlive; }
	void SetIsAlive(bool b) { isAlive = b; }
	int GetArmorClass() { return armorClass; }
	void SetArmorClass(int i) { armorClass = i; }
	std::string GetEnemyName() { return EnemyName; }
	void SetEnemyName(std::string str) { EnemyName = str; }
private:
	int health;
	Coin* loot;
	bool isAlive;
	int armorClass;
	std::string EnemyName;
};