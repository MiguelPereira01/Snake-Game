#include "mapGen.h"

void movUpdate();
void movimentation(char lastKey);


char map[21][61] = {}; // Inicializar o array vazio
Player player;
Map mapCoords;
char last;

void mapGenerator(int fun)
{
	int countX = 0, countY = 0;

	// Gerador do Mapa
	if (fun == 0)
	{
		for (; countY < mapCoords.y ; countY++) // Eixo Y;
		{
			for (countX = 0; countX < mapCoords.x; countX++) // Eixo X;
			{
				if (countY == 0 || countY == (mapCoords.y - 1))
				{
					map[countY][countX] = 254;
				}
				else if (countX == (mapCoords.x - 1) || countX == 0)
				{
					map[countY][countX] = 219;
				}
				else
				{
					map[countY][countX] = ' ';
				}
				
			}
		}
		map[player.y][player.x] = player.skin;
	}
	else // Frame Update
	{

		movimentation(player.lastKey);
		movUpdate();

		for (countY = 0; countY < mapCoords.y; countY++) // Eixo Y;
		{
			for (countX = 0; countX < mapCoords.x; countX++) // Eixo X;
			{
				cout << map[countY][countX];
			}
			cout << endl;
		}
	}
	return;
}

void clearscreen() // CODE TO "CLEAR" THE SCREEN
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}




void movUpdate()
{
	map[player.y][player.x] = player.skin;

	// Activate if a key was press
	if (_kbhit())
	{
		// Get a key and return its
		player.lastKey = player.getKey();
	}
}




void movimentation(char lastKey)
{
	// Clear last player position
	map[player.y][player.x] = ' ';

	switch (lastKey)
	{
	case 'w':
		// Snake will appear on the opposite limit's map site
		if (player.y - 1 == 0)
		{
			player.y = (mapCoords.y - 2); // player.y = 21-2 = 19
			break;
		}

		if (last == 's') // Snake can't move to opposite direction
		{
			player.moveDown();
			break;
		}
		// Normal Snake movement
		player.moveUp();
		last = lastKey;
		break;

	case 's':

		// Snake will appear on the opposite limit's map site
		if (player.y + 1 == mapCoords.y - 1)
		{
			player.y = 1; // player.y = 1
			break;
		}

		if (last == 'w') // Snake can't move to opposite direction
		{
			player.moveUp();
			break;
		}

		// Normal Snake Movement
		player.moveDown();
		last = lastKey;
		break;

	case 'd':

		// Snake will appear on the opposite limit's map site
		if (player.x + 1 == mapCoords.x - 1)
		{
			player.x = 1;
			break;
		}

		if (last == 'a') // Snake can't move to opposite direction
		{
			player.moveLeft();
			break;
		}

		// Normal Snake Movement
		player.moveRight();
		last = lastKey;
		break;

	case 'a':

		// Snake will appear on the opposite limit's map site
		if (player.x - 1 == 0)
		{
			player.x = (mapCoords.x - 2); // player.y = 61 - 2 = 59
			break;
		}

		if (last == 'd') // Snake can't move to opposite direction
		{
			player.moveRight();
			break;
		}

		// Normal Snake Movement
		player.moveLeft();
		last = lastKey;
		break;
		

	default:
		break;
	}
	
}


