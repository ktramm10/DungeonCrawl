#include "GameWidgets.h"
#include <iostream>
#include "Explorer.h"
#include "Room.h"
#include "MazeTypes.h"
#include "GameState.h"
GameWidgets::GameWidgets(Explorer* e)
{
	PlayerCharacter = e;
}

void GameWidgets::DisplayHUD()
{
	std::cout << std::endl;
	std::cout << "///////////////////////////" << std::endl;
	std::cout << "<<< Health Points: " << PlayerCharacter->GetHealth() << " >>>" << std::endl;
	std::cout << "<<< Magic Points:  " << PlayerCharacter->GetMagicPoints() << " >>>" << std::endl;
	std::cout << "<<< GP: " << PlayerCharacter->GetCoinsCollected() << "             >>>" << std::endl;
	std::cout << "///////////////////////////" << std::endl;
	std::cout << std::endl;
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

