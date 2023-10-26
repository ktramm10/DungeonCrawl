#pragma once
#include "StandardMazeBuilder.h"
#include <random>

enum Edirection;
class Interactables;
class Enemy;

class RandomMazeBuilder : public MazeBuilder
{
public:
	RandomMazeBuilder();
	virtual void BuildMaze() override;
	virtual void BuildRoom();
	virtual void BuildRandomDoor();
	virtual int GetLinkedRoom();
	virtual bool IsRoomFull(Room* room);
	virtual Maze* GetMaze() override { return currentMaze; }
	virtual EDirection SelectRandomSide(Room* room);
	virtual Interactables*  GenerateRandomLoot(Room* room);
	virtual Enemy* GenerateRandomEnemy();
	

private:
	Maze* currentMaze;
	std::default_random_engine eng;
};