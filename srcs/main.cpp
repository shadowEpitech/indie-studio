/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** main for indie_studio
*/

#include <irr/irrlicht.h>
#include "Entity.hpp"
#include "Window.hpp"
#include "Map.hpp"

int	main()
{
	Window	window(HEIGHT, WIDTH, L"Bomberman");

	window.createMenu(L"Bomberman menu", 0);
	return 0;
}
