//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Event class definition
//

#include "Window.hpp"

class Player
{
public:
	Player(Window *window, int nbplayer, std::vector<std::string> refreshmap);
	~Player();
	irr::scene::IAnimatedMeshSceneNode	*getM_character2() const;

private:
	irr::scene::IAnimatedMeshSceneNode	*m_character2;
};
