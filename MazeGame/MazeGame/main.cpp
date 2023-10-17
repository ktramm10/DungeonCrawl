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
char GameInput();
bool ValidateGameInput(char input);
void InterpretGameInput(char input, GameState* game);
void MainMenu(GameMenus* gameMenu);

/*
* Variables
*/



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
	Maze* gameMaze = CreateMaze(r_Builder, 5);
	Explorer* playerCharacter = new Explorer(gameMaze);
	GameWidgets* gameWidgets = new GameWidgets(playerCharacter);
	GameState* gamestate = new GameState(gameMaze, playerCharacter, gameWidgets);

	return gamestate;
}

void GameLoop(GameState* game)
{
	char input;
	bool ValidGameInput = false;

	while (game->GetIsRunning() && game->GetPlayerCharacter()->GetHealth() > 0)
	{
		game->GetGameWidgets()->DrawRoom(game->GetPlayerCharacter());
		game->GetGameWidgets()->DisplayHUD();
		
		while (!ValidGameInput)
		{
			input = GameInput();
			if (ValidateGameInput(input))
			{
				break;
			}
			else
			{
				std::cout << "That was not a valid game input. Please try again..." << std::endl;
			}
		}
		InterpretGameInput(input, game);
	}
	std::cout << "Game Over!" << std::endl;
}

char GameInput()
{
	char input;
	std::cout << "Enter your movement input." << std::endl;
	std::cout << "N -> North" << std::endl;
	std::cout << "S -> South" << std::endl;
	std::cout << "E -> East" << std::endl;
	std::cout << "W -> West" << std::endl;
	std::cout << "I -> View Inventory" << std::endl;
	std::cout << "Press Q to end the game." << std::endl;

	std::cin >> input;
	input = tolower(input);
	return input;


	
}

bool ValidateGameInput(char input)
{
	if (input == 'n' || input == 's' ||  input == 'w' || input == 'e'
		|| input == 'q' || input == 'i')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void InterpretGameInput(char input, GameState* game)
{
	
	switch (input)
	{
	case 'n':
		game->GetPlayerCharacter()->Move(ED_North);
		break;
	case 's':
		game->GetPlayerCharacter()->Move(ED_South);
		break;
	case 'w':
		game->GetPlayerCharacter()->Move(ED_West);
		break;
	case 'e':
		game->GetPlayerCharacter()->Move(ED_East);
		break;
	case 'q':
		game->SetIsRunning(false);
		break;
	case 'i':
		game->GetGameWidgets()->ViewInventory();
	default:
		break;
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
