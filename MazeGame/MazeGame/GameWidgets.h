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
	void ViewInventory();
	void CombatUI();
	void DrawOrcSprite();
protected:

private:
	Explorer* PlayerCharacter;

};