#include "Explorer.h"
#include "Room.h"
#include "Maze.h"
#include "MazeTypes.h"
#include "Door.h"
#include "GameState.h"
#include "Interactables.h"
#include "Sword.h"
#include "Chest.h"
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
		CheckForLoot();
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
		if (!static_cast<Chest*>(CurrentRoomLocation->GetRoomLoot()))
		{
			CurrentRoomLocation->SetRoomLoot(NULL);
		}
		
	}
}


