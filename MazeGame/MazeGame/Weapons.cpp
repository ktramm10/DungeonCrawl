#include "Weapons.h"
#include "RNG.h"
#include <chrono>
#include "Enemy.h"

Weapons::Weapons()
{
	SetItemID(EItemTypes::EI_Weapon);
	rng = new RNG();
}

void Weapons::EquipItem(Explorer* e)
{
	e->SetEquippedWeapon(this);
}

void Weapons::AddToInventory(Explorer* e)
{
	e->AddToInventory(this);
}

void Weapons::Damage(Enemy* target)
{
	std::cout << "You swing your " << GetItemName() << " at the " << target->GetEnemyName() << " dealing " << GetWeaponDamage() << " damage." << std::endl;
	int currentHealth = target->GetHealth();
	target->SetHealth(currentHealth -= GetWeaponDamage());
}
