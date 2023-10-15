#include<iostream>
#include<string>
#include"Door.h"
#include"Room.h"
#include"Wall.h"
#include"Maze.h"
#include"Explorer.h"
#include"MazeFactory.h"
#include"StandardMazeBuilder.h"
#include"EnchantedMazeBuilder.h"
#include"GameWidgets.h"
#include"GameState.h"
#include"GameMenus.h"
#include"RandomMazeBuilder.h"

/*
* Function Prototyping
*/

Maze* CreateMaze(MazeBuilder* builder, int numOfRooms);
GameState* InitalizeGameComponents();
void GameLoop(GameState* game);
EDirection InterpretInput(GameState* game);
void MainMenu(GameMenus* gameMenu);

/*
* Variables
*/

bool isRunning = true;

int main()
{
	GameMenus* gameMenus = new GameMenus();
	GameState* currentGame = InitalizeGameComponents();
	currentGame->GetGameWidgets()->TitleCard();
	MainMenu(gameMenus);
	GameLoop(currentGame);

	

}

Maze* CreateMaze(RandomMazeBuilder* builder, int numOfRooms)
{
	builder->BuildMaze();

	for (int i = 0; i <= numOfRooms; i++)
	{
		if (i == 0)
		{
			std::cout << "Room Number Created: " << builder->GetMaze()->nextRoomNumber << std::endl;
			builder->BuildRoom();
			
		}
		else
		{
			std::cout << "Room Number Created: " << builder->GetMaze()->nextRoomNumber << std::endl;
			builder->BuildRoom();
			builder->BuildRandomDoor();
		}
	}
	return builder->GetMaze();
}

GameState* InitalizeGameComponents()
{
	RandomMazeBuilder* r_Builder = new RandomMazeBuilder();
	Maze* gameMaze = CreateMaze(r_Builder, 10);
	Explorer* playerCharacter = new Explorer(gameMaze);
	GameWidgets* gameWidgets = new GameWidgets(playerCharacter);
	GameState* gamestate = new GameState(gameMaze, playerCharacter, gameWidgets);

	return gamestate;
}

void GameLoop(GameState* game)
{
	while (game->GetIsRunning() && game->GetPlayerCharacter()->GetHealth() > 0)
	{
		EDirection direction = ED_NULL;
		game->GetGameWidgets()->DrawRoom(game->GetPlayerCharacter());
		game->GetGameWidgets()->DisplayHUD();
		while (direction == ED_NULL && game->GetIsRunning())
		{
			direction = InterpretInput(game);
			game->GetPlayerCharacter()->Move(direction);
		}
	}
	std::cout << "Game Over!" << std::endl;
}

EDirection InterpretInput(GameState* game)
{
	char input;
	std::cout << "Enter your movement input." << std::endl;
	std::cout << "N -> North" << std::endl;
	std::cout << "S -> South" << std::endl;
	std::cout << "E -> East" << std::endl;
	std::cout << "W -> West" << std::endl;
	std::cout << "Press Q to end the game." << std::endl;

	std::cin >> input;
	std::cout << std::endl;
	std::cout << std::endl;


	if (input == 'N' || input == 'n')
	{
		return ED_North;
	}
	else if (input == 'S' || input == 's')
	{
		return ED_South;
	}
	else if (input == 'E' || input == 'e')
	{
		return ED_East;
	}
	else if (input == 'W' || input == 'w')
	{
		return ED_West;
	}
	else if (input == 'Q' || input == 'q')
	{
		game->SetIsRunning(false);
		return ED_NULL;
	}
	else
	{
		std::cout << "That was not a valid input. Please try again." << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		return ED_NULL;
	}
}

void MainMenu(GameMenus* gameMenu)
{
	std::string result;
	gameMenu->PrintMainMenu();
	while (!gameMenu->GetIsValid())
	{
		result = gameMenu->InterpretInput(gameMenu->GetMainMenuInput());
	}
	if (result._Equal("quit"))
	{
		exit(0);
	}
	gameMenu->SetIsValid(false);
}	
