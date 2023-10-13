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

RandomMazeBuilder::RandomMazeBuilder(GameState* game)
{
	currentGame = game;
}

void RandomMazeBuilder::BuildRoom()
{
	Maze* maze = currentGame->GetMaze();
	
	Room* newRoom = new Room(maze->nextRoomNumber);
	maze->AddRoom(newRoom);
	
	newRoom->SetSide(ED_North, new Wall);
	newRoom->SetSide(ED_South, new Wall);
	newRoom->SetSide(ED_East, new Wall);
	newRoom->SetSide(ED_West, new Wall);

	maze->nextRoomNumber += 1;
}

void RandomMazeBuilder::BuildRandomDoor(Room* RoomTo)
{
	std::vector<Room*> roomList = currentGame->GetMaze()->GetRoomList();
	Maze* maze = currentGame->GetMaze();
	Room* r1 = maze->RoomNo(roomList.size());
	Room* r2 = maze->RoomNo(GetLinkedRoom());
}

int RandomMazeBuilder::GetLinkedRoom()
{
	//std::vector<Room*> roomList = currentGame->GetMaze()->GetRoomList();
	//if (!roomList.size() == 0)
	//{
	//	srand(time(0));
	//	return (rand() % roomList.size()-1) + 1;
	//
	//}
	//return 0;
	
	// THIS CODE IS A RESULT THAT SEMI WORKS HOWEVER I WILL NEED TO GET MULTIPLE DIFFERENT RANDOM NUMBERS VERY FAST DURING RUNTIME AND THIS RETURNS THE SAME NUMBER.


	std::vector<Room*> roomList = currentGame->GetMaze()->GetRoomList();
	std::uniform_int_distribution<int> uni(0, roomList.size());
	return // I NEED TO RETURN THE RESULT OF THE ABOVE LINE AS TYPE INTEGER. IS THERE A WAY HOW?
}
	

