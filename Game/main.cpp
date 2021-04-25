#include "mapGen.h"
#include "Player.h"



int main()
{
	mapGenerator(0); // Gera o mapa

	while(1)
	{	
		mapGenerator(1); // Dá load ao mapa 
		clearscreen();
		Sleep(150);
	}
	
	return 0;
}