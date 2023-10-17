#pragma once
#include "Weapons.h"

class Sword : public Weapons
{
public:
	Sword();
	virtual void Attack(Enemy* target) override;
protected:

private:
	int SwordDamage = 10;
};