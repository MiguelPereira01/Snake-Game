#pragma once
#include <stdio.h>
#include <conio.h>

class Player
{
public:
	int x;
	int y;
	char skin;
	int length;
	char lastKey;

	Player() : x(29), y(9) , skin('O'), lastKey('d') {}

	char getKey();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
};

