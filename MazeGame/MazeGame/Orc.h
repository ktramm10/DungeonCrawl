#pragma once
#include "Enemy.h"

class RNG;

class Orc : public Enemy
{
public:
	Orc();
	virtual void Attack(Explorer* e) override;
	virtual void Die() override;
protected:
private:
	const int attackDamage = 10;
	const int orcMaxHealth = 100;
	const int armorClass = 10;
	RNG* rng;
};