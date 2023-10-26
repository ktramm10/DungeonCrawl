#include "GameWidgets.h"
#include <iostream>
#include "Explorer.h"
#include "Room.h"
#include "MazeTypes.h"
#include "GameState.h"
#include "Sword.h"
#include "Enemy.h"
GameWidgets::GameWidgets(Explorer* e)
{
	PlayerCharacter = e;
}

void GameWidgets::DisplayHUD()
{
	std::cout << std::endl;
	std::cout << "Enter your movement input.     " << "/////////////////////////////////////" << std::endl;
	std::cout << "N -> North                     " << "<<< Health Points: " << PlayerCharacter->GetHealth() << "      >>>" << std::endl;
	std::cout << "S -> South                     " << "<<< Magic Points:  " << PlayerCharacter->GetMagicPoints() << "      >>>" << std::endl;
	std::cout << "E -> East                      " << "<<< Equipped Weapon: " << PlayerCharacter->GetEquippedWeapon()->GetItemName() << "  >>>" << std::endl;
	std::cout << "W -> West                      " << "<<< GP: " << PlayerCharacter->GetCoinsCollected() << "                   >>>" << std::endl;
	std::cout << "I -> View Inventory            " << "<<< Keys: " << PlayerCharacter->GetKeys() << "                 >>>" << std::endl;
	std::cout << "Press Q to end the game.       " << "/////////////////////////////////////" << std::endl;
	

}

void GameWidgets::DrawRoom(Explorer* e)
{	
	// 1 
	if (e->GetLocation()->GetSide(ED_North)->IsDoor() && !e->GetLocation()->GetSide(ED_South)->IsDoor() && !e->GetLocation()->GetSide(ED_West)->IsDoor() && !e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********---*********" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********************" << std::endl;
	}
	//2 
	if (!e->GetLocation()->GetSide(ED_North)->IsDoor() && !e->GetLocation()->GetSide(ED_South)->IsDoor() && !e->GetLocation()->GetSide(ED_West)->IsDoor() && e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********************" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   /" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********************" << std::endl;
	}
	//3
	if (!e->GetLocation()->GetSide(ED_North)->IsDoor() && e->GetLocation()->GetSide(ED_South)->IsDoor() && !e->GetLocation()->GetSide(ED_West)->IsDoor() && !e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********************" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********---*********" << std::endl;
	}
	//4
	if (!e->GetLocation()->GetSide(ED_North)->IsDoor() && !e->GetLocation()->GetSide(ED_South)->IsDoor() && e->GetLocation()->GetSide(ED_West)->IsDoor() && !e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********************" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " /                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********************" << std::endl;
	}
	//5
	if (e->GetLocation()->GetSide(ED_North)->IsDoor() && !e->GetLocation()->GetSide(ED_South)->IsDoor() && e->GetLocation()->GetSide(ED_West)->IsDoor() && !e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********---*********" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " /                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********************" << std::endl;
	}
	//6
	if (!e->GetLocation()->GetSide(ED_North)->IsDoor() && e->GetLocation()->GetSide(ED_South)->IsDoor() && !e->GetLocation()->GetSide(ED_West)->IsDoor() && e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********************" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   /" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********---*********" << std::endl;
	}
	//7
	if (!e->GetLocation()->GetSide(ED_North)->IsDoor() && !e->GetLocation()->GetSide(ED_South)->IsDoor() && e->GetLocation()->GetSide(ED_West)->IsDoor() && e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********************" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " /                   /" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********************" << std::endl;
	}
	//8
	if (!e->GetLocation()->GetSide(ED_North)->IsDoor() && e->GetLocation()->GetSide(ED_South)->IsDoor() && e->GetLocation()->GetSide(ED_West)->IsDoor() && !e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********************" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " /                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********---*********" << std::endl;
	}
	// 9 
	if (e->GetLocation()->GetSide(ED_North)->IsDoor() && !e->GetLocation()->GetSide(ED_South)->IsDoor() && !e->GetLocation()->GetSide(ED_West)->IsDoor() && e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********---*********" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   /" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********************" << std::endl;
	}
	// 10 
	if (e->GetLocation()->GetSide(ED_North)->IsDoor() && e->GetLocation()->GetSide(ED_South)->IsDoor() && !e->GetLocation()->GetSide(ED_West)->IsDoor() && !e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********---*********" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********---*********" << std::endl;
	}
	// 11
	if (e->GetLocation()->GetSide(ED_North)->IsDoor() && e->GetLocation()->GetSide(ED_South)->IsDoor() && e->GetLocation()->GetSide(ED_West)->IsDoor() && !e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********---*********" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " /                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********---*********" << std::endl;
	}
	// 12
	if (e->GetLocation()->GetSide(ED_North)->IsDoor() && e->GetLocation()->GetSide(ED_South)->IsDoor() && !e->GetLocation()->GetSide(ED_West)->IsDoor() && e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********---*********" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   /" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********---*********" << std::endl;
	}
	// 13
	if (e->GetLocation()->GetSide(ED_North)->IsDoor() && !e->GetLocation()->GetSide(ED_South)->IsDoor() && e->GetLocation()->GetSide(ED_West)->IsDoor() && e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********---*********" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " /                   /" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********************" << std::endl;
	}
	// 14
	if (!e->GetLocation()->GetSide(ED_North)->IsDoor() && e->GetLocation()->GetSide(ED_South)->IsDoor() && e->GetLocation()->GetSide(ED_West)->IsDoor() && e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********************" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " /                   /" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********---*********" << std::endl;
	}
	// 15
	if (e->GetLocation()->GetSide(ED_North)->IsDoor() && e->GetLocation()->GetSide(ED_South)->IsDoor() && e->GetLocation()->GetSide(ED_West)->IsDoor() && e->GetLocation()->GetSide(ED_East)->IsDoor())
	{
		std::cout << " *********---*********" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " /                   /" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *                   *" << std::endl;
		std::cout << " *********---*********" << std::endl;
	}
}

void GameWidgets::TitleCard()
{
	std::cout << "///////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << " ____                                        ____                    _ " << std::endl;
	std::cout << "|  _ \\ _   _ _ __   __ _  ___  ___  _ __    / ___|_ __ __ ___      _| |" << std::endl;
	std::cout << "| | | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\  | |   | '__/ _` \\ \\ /\\ / / |" << std::endl;
	std::cout << "| |_| | |_| | | | | (_| |  __/ (_) | | | | | |___| | | (_| |\\ V  V /| |" << std::endl;
	std::cout << "|____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\____|_|  \\__,_| \\_/\\_/ |_|" << std::endl;
	std::cout << "                   |___/                                               " << std::endl;
	std::cout << "///////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;


}

void GameWidgets::ViewInventory()
{
	system("cls");
	std::cout << "INVENTORY: " << std::endl;
	for (Items* item : PlayerCharacter->GetInventoryList())
	{
		std::cout << "<<< " << item->GetItemName() << " >>>" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

}

void GameWidgets::CombatUI()
{
	system("cls");
	std::cout << "/////////////////////////////////////" << "           " << "/////////////////////////////////////" << std::endl;
	std::cout << "<<< Health Points: " << PlayerCharacter->GetHealth() << "                         " << "   <<< Enemy: " << PlayerCharacter->GetLocation()->GetEnemy()->GetEnemyName() << std::endl;
	std::cout << "<<< Magic Points:  " << PlayerCharacter->GetMagicPoints() << "                         " << "   <<< Enemy HP: " << PlayerCharacter->GetLocation()->GetEnemy()->GetHealth() << std::endl;
	std::cout << "<<< Equipped Weapon: " << PlayerCharacter->GetEquippedWeapon()->GetItemName() << "                      " << "<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << "<<< GP: " << PlayerCharacter->GetCoinsCollected() << "           " << std::endl;
	std::cout << "<<< Keys: " << PlayerCharacter->GetKeys() << "           " << std::endl;
	std::cout << "/////////////////////////////////////" << "           " << "/////////////////////////////////////" << std::endl;
	std::cout << "Make Your Action... " << std::endl;
	std::cout << "1. Attack With Equipped Weapon" << std::endl;
	std::cout << "2. Run" << std::endl;
}

void GameWidgets::DrawOrcSprite()
{
	std::cout << "           _ " << std::endl;
	std::cout << "          / |" << std::endl;
	std::cout << "    ___   |||" << std::endl;
	std::cout << "  _/___\\_ |||" << std::endl;
	std::cout << " _\\\\___//_|||" << std::endl;
	std::cout << "/. \\/_\\/ .|||" << std::endl;
	std::cout << "\\__\\__ . [___]" << std::endl;
	std::cout << "|-   -|. [_ -\\" << std::endl;
	std::cout << "\\ {/} /_/ \\__/" << std::endl;
	std::cout << " \\___/=]|]    " << std::endl;
	std::cout << " ||  /\\  ||   " << std::endl;
	std::cout << " ([]|   |[])  " << std::endl;
	std::cout << " |_ |   | _|  " << std::endl;
	std::cout << "[___|   |___] " << std::endl;

}

