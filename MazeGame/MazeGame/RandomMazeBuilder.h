#pragma once
#include "StandardMazeBuilder.h"
class GameState;

class RandomMazeBuilder : public StandardMazeBuilder
{
public:
	RandomMazeBuilder(GameState* game);
	virtual void BuildRoom();
	virtual void BuildRandomDoor(Room* roomTo);
	virtual int GetLinkedRoom();

private:
	GameState* currentGame;
};