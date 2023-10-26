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
#include"Enemy.h"

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
void CombatLoop(GameState* game);
void ActionSelect(GameState* game);
int CombatInput();
bool ValidateCombatInput(int input);
void InterpretCombatInput(int input, GameState* game);

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
		if (game->GetPlayerCharacter()->GetLocation()->GetEnemy())
		{
			game->GetPlayerCharacter()->SetInCombat(true);
			CombatLoop(game);
		}
		if (game->GetPlayerCharacter()->GetLocation()->GetRoomLoot())
		{
			game->GetPlayerCharacter()->CheckForLoot();
			
		}
	}
	std::cout << "Game Over!" << std::endl;
}

char GameInput()
{
	char input;
	std::cin >> input;
	input = tolower(input);
	return input;
}

bool ValidateGameInput(char input)
{
	return input == 'n' || input == 's' || input == 'w' || input == 'e' || input == 'q' || input == 'i';
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
void CombatLoop(GameState* game)
{
	while (game->GetIsRunning() && game->GetPlayerCharacter()->GetInCombat() && game->GetPlayerCharacter()->GetHealth() > 0)
	{
		game->GetGameWidgets()->CombatUI();
		game->GetGameWidgets()->DrawOrcSprite();
		int input;
		bool ValidInput = false;
		while (!ValidInput)
		{
			std::cout << "IN SECOND WHILE LOOP" << std::endl;
			input = CombatInput();
			if (ValidateCombatInput(input))
			{
				break;
			}
			else
			{
				std::cout << "This input was not valid please try again." << std::endl;
			}
		}
		InterpretCombatInput(input, game);
		if (game->GetPlayerCharacter()->GetLocation()->GetEnemy())
		{
			game->GetPlayerCharacter()->GetLocation()->GetEnemy()->Attack(game->GetPlayerCharacter());
			system("pause");
		}
		else
		{
			system("pause");
		}
	}
}

void ActionSelect(GameState* game)
{
	int input;
	bool ValidGameInput = false;
	while (!ValidateGameInput)
	{
		input = CombatInput();
		if (ValidateCombatInput(input))
		{
			break;
		}
		else
		{
			std::cout << "This input was not valid please try again." << std::endl;
		}
		InterpretCombatInput(input, game);
	}

}

int CombatInput()
{
	int input;
	std::cin >> input;
	return input;
}

bool ValidateCombatInput(int input)
{
	return input == 1 || input == 2;
}

void InterpretCombatInput(int input, GameState* game)
{
	switch (input)
	{
	case 1:
		game->GetPlayerCharacter()->Attack();
		break;
	case 2:
		std::cout << "THIS DOES NOTHING RIGHT NOW" << std::endl;
		break;
	}
		
}
