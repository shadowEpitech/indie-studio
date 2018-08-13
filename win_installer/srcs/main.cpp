//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// main for installer Bomberman
//

#include <irr/irrlicht.h>
#include <Window.hpp>
#include "Installer.hpp"

int main()
{
    Window  window(1200, 600, L"Bomberman installer");
    Installer   installer(window);

    installer.setMenu(L"Welcome to bomberman installer");
    return 0;
}
