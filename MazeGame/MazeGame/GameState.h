#pragma once
class Maze;
class Explorer;
class GameWidgets;

class GameState
{
public:
	GameState(Maze* currentMaze, Explorer* playerCharacter, GameWidgets* gameWidgets);

public:
	void SetMaze(Maze* m) { maze = m; }
	void SetIsRunning(bool b) { isRunning = b; }
	bool GetIsRunning() { return isRunning; }
	Maze* GetMaze() { return maze; }
	Explorer* GetPlayerCharacter() { return playerCharacter; }
	GameWidgets* GetGameWidgets() { return gameWidgets; }
protected:
	
private:
	bool isRunning;
	Maze* maze;
	Explorer* playerCharacter;
	GameWidgets* gameWidgets;
};