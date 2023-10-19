#pragma once
#include "Items.h"

class Enemy;
class RNG;

class Weapons : public Items
{
public:
	Weapons();
	virtual void EquipItem(Explorer* e) override;
	virtual void AddToInventory(Explorer* e) override;
	virtual int GetWeaponDamage() { return weaponDamage; }
	virtual void SetWeaponDamage(int dmg) { weaponDamage = dmg; }
	virtual void Damage(Enemy* target);
	RNG* GetRNG() { return rng; }
protected:
private:
	int weaponDamage;
	RNG* rng;
};