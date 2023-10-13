#include "EnchantedMazeBuilder.h"
#include "EnchantedWall.h"
#include "Room.h"
#include "Maze.h"

EnchantedMazeBuilder::EnchantedMazeBuilder()
{
}

void EnchantedMazeBuilder::BuildRoom(int roomNo)
{
	if (!GetMaze()->RoomNo(roomNo))
	{
		Room* room = new Room(roomNo);
		GetMaze()->AddRoom(room);

		room->SetSide(ED_North, new EnchantedWall);
		room->SetSide(ED_South, new EnchantedWall);
		room->SetSide(ED_West, new EnchantedWall);
		room->SetSide(ED_East, new EnchantedWall);
	}
	else {
		throw std::invalid_argument("MULTIPLE ROOMS ATTEMPTED TO BE CREATED WITH THE SAME NUMBER.");
	}
}
