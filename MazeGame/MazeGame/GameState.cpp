#include "GameState.h"
#include "Maze.h"
#include "Explorer.h"

GameState::GameState(Maze* cm, Explorer* pc, GameWidgets* gw)
{
	maze = cm;
	isRunning = true;
	playerCharacter = pc;
	gameWidgets = gw;
}
