#include "../Include/State_Main_Menu.h"
#include <iostream>
using std::cout;
using std::endl;

void Main_Menu::Initialize(sf::RenderWindow* window)
{
	cout << "Main Menu Init" << endl;
}

void Main_Menu::UpdateGame(sf::RenderWindow* window)
{
	//gamelogic
	cout << "Main Menu Update" << endl;
}

void Main_Menu::UpdateScreen(sf::RenderWindow* window)
{
	//window.draw()...
	cout << "Draw Main Menu" << endl;
}

void Main_Menu::Destroy(sf::RenderWindow* window)
{
	cout << "Main Menu Exit" << endl;
}
