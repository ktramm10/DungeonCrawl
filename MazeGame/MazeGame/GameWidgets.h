#pragma once
#include <iostream>
#include "MazeTypes.h"
class Explorer;
class GameState;


class GameWidgets
{
public:
	GameWidgets(Explorer* e);
	void DisplayHUD();
	void DrawRoom(Explorer* e);
	void TitleCard();
protected:

private:
	Explorer* PlayerCharacter;

};