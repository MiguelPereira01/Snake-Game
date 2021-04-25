#include "Player.h"


char Player::getKey()
{
	char key = _getch();
	return key;
}

void Player::moveRight()
{
	this->x+=2;
}

void Player::moveLeft()
{
	this->x-=2;
}

void Player::moveUp()
{
	this->y--;
}

void Player::moveDown()
{
	this->y++;
}


