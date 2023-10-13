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

/*
* Function Prototyping
*/

Maze* CreateMaze(MazeBuilder* builder);
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

Maze* CreateMaze(MazeBuilder* builder)
{
	builder->BuildMaze();
	builder->BuildRoom(1);
	builder->BuildRoom(2);
	builder->BuildRoom(3);
	builder->BuildRoom(4);
	builder->BuildRoom(5);
	builder->BuildRoom(6);
	builder->BuildDoor(1, 2, ED_East);
	builder->BuildDoor(1, 3, ED_West);
	builder->BuildDoor(2, 4, ED_North);
	builder->BuildDoor(3, 5, ED_West);
	builder->BuildDoor(5, 6, ED_South);

	return builder->GetMaze();
}

GameState* InitalizeGameComponents()
{
	StandardMazeBuilder* s_Builder = new StandardMazeBuilder();
	EnchantedMazeBuilder* e_Builder = new EnchantedMazeBuilder();
	Maze* gameMaze = CreateMaze(e_Builder);
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
