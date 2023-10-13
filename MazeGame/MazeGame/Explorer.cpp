#include "Explorer.h"
#include "Room.h"
#include "Maze.h"
#include "MazeTypes.h"
#include "Door.h"
#include "GameState.h"

Explorer::Explorer(Maze* maze)
{
	GameMaze = maze;
	CurrentRoomLocation = maze->RoomNo(1);
	health = maxHealth;
	magicPoints = maxMagicPoints;
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
		CurrentRoomLocation->GetSide(direction)->Enter(this);
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


