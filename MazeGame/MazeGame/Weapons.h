#pragma once
#include "Items.h"
#include "Enemy.h"
class Weapons : public Items
{
public:
	Weapons();
	virtual void EquipItem() override;
	virtual void AddToInventory(Explorer* e) override;
	virtual int GetWeaponDamage() { return weaponDamage; }
	virtual void SetWeaponDamage(int dmg) { weaponDamage = dmg; }
	virtual void Attack(Enemy* target) {}
protected:
private:
	int weaponDamage;
};