#include "RandomMazeBuilder.h"
#include "Room.h"
#include "Door.h"
#include "Maze.h"
#include "Wall.h"
#include "GameState.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <random>
#include <chrono>
#include "MazeTypes.h"
#include "Coin.h"

RandomMazeBuilder::RandomMazeBuilder()
{
	currentMaze = 0;
	eng.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

void RandomMazeBuilder::BuildMaze()
{
	currentMaze = new Maze();
}

void RandomMazeBuilder::BuildRoom()
{
	Room* newRoom = new Room(currentMaze->nextRoomNumber, GenerateRandomLoot());
	currentMaze->AddRoom(newRoom);
	
	newRoom->SetSide(ED_North, new Wall);
	newRoom->SetSide(ED_South, new Wall);
	newRoom->SetSide(ED_East, new Wall);
	newRoom->SetSide(ED_West, new Wall);

	currentMaze->nextRoomNumber += 1;
}

void RandomMazeBuilder::BuildRandomDoor()
{
	std::vector<Room*> roomList = currentMaze->GetRoomList();
	Maze* maze = currentMaze;
	Room* r2 = currentMaze->RoomNo(roomList.size()-1);
	Room* connectingRoom = currentMaze->RoomNo(GetLinkedRoom());
	while (IsRoomFull(connectingRoom))
	{
		connectingRoom = currentMaze->RoomNo(GetLinkedRoom());
	}
	Room* r1 = connectingRoom;
	Door* newDoor = new Door(r1, r2);

	EDirection directionOfNewRoom = SelectRandomSide(r1);
	
	switch (directionOfNewRoom)
	{
	case ED_North:
		r1->SetSide(directionOfNewRoom, newDoor);
		r2->SetSide(ED_South, newDoor);
		break;
	case ED_South:
		r1->SetSide(directionOfNewRoom, newDoor);
		r2->SetSide(ED_North, newDoor);
		break;
	case ED_East:
		r1->SetSide(directionOfNewRoom, newDoor);
		r2->SetSide(ED_West, newDoor);
		break;
	case ED_West:
		r1->SetSide(directionOfNewRoom, newDoor);
		r2->SetSide(ED_East, newDoor);
		break;
	default:
		break;
	}

}

int RandomMazeBuilder::GetLinkedRoom() {
	std::vector<Room*> roomList = currentMaze->GetRoomList();
	std::uniform_int_distribution<int> uni(0, roomList.size()-2);
	return uni(eng);
}

bool RandomMazeBuilder::IsRoomFull(Room* room)
{
	if (room->CheckIfDoor(ED_North) && room->CheckIfDoor(ED_South) && room->CheckIfDoor(ED_East) && room->CheckIfDoor(ED_West))
	{
		return true;
	}
	else
	{
		return false;
	}
}

EDirection RandomMazeBuilder::SelectRandomSide(Room* room)
{
	EDirection directionResult;
	bool openWallFound = false;
	while (!openWallFound)
	{
		std::uniform_int_distribution<int> uni(1, 4);
		int result = uni(eng);
		switch (result)
		{
		case 1:
			if (!room->GetSide(ED_North)->IsDoor())
			{
				openWallFound = true;
				directionResult = ED_North;
			}
			break;
		case 2:
			if (!room->GetSide(ED_South)->IsDoor())
			{
				openWallFound = true;
				directionResult = ED_South;
			}
			break;
		case 3:
			if (!room->GetSide(ED_West)->IsDoor())
			{
				openWallFound = true;
				directionResult = ED_West;
			}
			break;
		case 4:
			if (!room->GetSide(ED_East)->IsDoor())
			{
				openWallFound = true;
				directionResult = ED_East;
			}
			break;
		}
	}
	return directionResult;
}

Interactables* RandomMazeBuilder::GenerateRandomLoot()
{
	std::uniform_int_distribution<int> uni(0, 2);
	switch (uni(eng))
	{
	case 0:
		return new Coin();
		break;
	default:
		return 0;
		break;
	}
}
	

