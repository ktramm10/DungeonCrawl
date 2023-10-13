#include "StandardMazeBuilder.h"
#include "MazeTypes.h"
#include "Door.h"
#include "Maze.h"
#include "Room.h"
#include "Wall.h"
#include <typeinfo>


StandardMazeBuilder::StandardMazeBuilder()
{
	_currentMaze = 0;
}

void StandardMazeBuilder::BuildMaze()
{
	_currentMaze = new Maze;
}

void StandardMazeBuilder::BuildRoom(int roomNo)
{
	if (!_currentMaze->RoomNo(roomNo))
	{
		Room* room = new Room(roomNo);
		_currentMaze->AddRoom(room);

		room->SetSide(ED_North, new Wall);
		room->SetSide(ED_South, new Wall);
		room->SetSide(ED_East, new Wall);
		room->SetSide(ED_West, new Wall);
	}
	else {
		throw std::invalid_argument("MULTIPLE ROOMS ATTEMPTED TO BE CREATED WITH THE SAME NUMBER.");
	}
}

void StandardMazeBuilder::BuildDoor(int roomFrom, int roomTo, EDirection roomFromDirection)
{
	Room* r1 = _currentMaze->RoomNo(roomFrom);
	Room* r2 = _currentMaze->RoomNo(roomTo);
	Door* newDoor = new Door(r1, r2);

	switch (roomFromDirection)
	{
	case ED_North:
		r1->SetSide(roomFromDirection, newDoor);
		r2->SetSide(ED_South, newDoor);
		break;
	case ED_South:
		r1->SetSide(roomFromDirection, newDoor);
		r2->SetSide(ED_North, newDoor);
		break;
	case ED_East:
		r1->SetSide(roomFromDirection, newDoor);
		r2->SetSide(ED_West, newDoor);
		break;
	case ED_West:
		r1->SetSide(roomFromDirection, newDoor);
		r2->SetSide(ED_East, newDoor);
		break;
	default:
		break;
	}
}

