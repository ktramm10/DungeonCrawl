#include "Explorer.h"
#include "Room.h"
#include "Maze.h"
#include "MazeTypes.h"
#include "Door.h"
#include "GameState.h"
#include "Interactables.h"
#include "Sword.h"
#include "Chest.h"
#include "Key.h"
#include "Coin.h"
#include "RNG.h"
#include "Enemy.h"
Explorer::Explorer(Maze* maze)
{
	GameMaze = maze;
	CurrentRoomLocation = maze->RoomNo(1);
	health = maxHealth;
	magicPoints = maxMagicPoints;
	CoinsCollected = 0;
	keys = 0;
	equippedWeapon = new Sword();
	inventory.push_back(equippedWeapon);
	rng = new RNG();
}
void Explorer::SayLocation()
{
	if (CurrentRoomLocation)
	{
		std::cout << "You are in room: " << CurrentRoomLocation->GetRoomNumber() << std::endl;
	}
	else {
		throw std::invalid_argument("CHARACTERS LOCATION WAS NULL");
	}
}

void Explorer::Move(EDirection direction)
{
	if (direction != EDirection::ED_NULL)
	{
		system("cls");
		CurrentRoomLocation->GetSide(direction)->Enter(this);
		SayLocation();

	}
}

void Explorer::Unlock(EDirection direction)
{
	if (Door* door = static_cast<Door*>(CurrentRoomLocation->GetSide(direction)))
	{
		std::cout << "Door is unlocked!" << std::endl;
		door->SetIsOpen(true);
	}

}

void Explorer::AddToLootList(Interactables* interactable)
{
}

void Explorer::CheckForLoot()
{
	if (CurrentRoomLocation->GetRoomLoot())
	{
		CurrentRoomLocation->GetRoomLoot()->Interact(this);
	}
}

void Explorer::Attack()
{
	if (CurrentRoomLocation->GetEnemy())
	{
		int hitResult = rng->GetNumInRange(1, 20);
		if (hitResult + attackModifier >= CurrentRoomLocation->GetEnemy()->GetArmorClass())
		{
			std::cout << "You swing your " << equippedWeapon->GetItemName() << " at the target dealing " << equippedWeapon->GetWeaponDamage() << " damage!" << std::endl;
			if (CurrentRoomLocation->GetEnemy()->GetHealth() > 0)
			{
				CurrentRoomLocation->GetEnemy()->SetHealth(CurrentRoomLocation->GetEnemy()->GetHealth() - equippedWeapon->GetWeaponDamage());
				if (CurrentRoomLocation->GetEnemy()->GetHealth() <= 0)
				{
					CurrentRoomLocation->GetEnemy()->SetIsAlive(false);
					CurrentRoomLocation->GetEnemy()->Die();
					CurrentRoomLocation->SetEnemy(0);
					SetInCombat(false);
				}
			}
		}
		else
		{
			std::cout << "You swung at the target and missed!" << std::endl;
		}
	}

}



