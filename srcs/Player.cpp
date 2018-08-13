//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Player class implementation
//

#include <cstdlib>
#include <ctime>
#include <Bomb.hpp>
#include "Window.hpp"
#include "Map.hpp"
#include "Game.hpp"
#include "Time.hpp"
#include "Player.hpp"

Player::Player(Window *window, int nbplayer, std::vector<std::string> refreshmap)
{
	int	i = 0;
	int	j = 0;
	int	px = 0;
	int	py = 0;
	m_character2 =
		window->getM_sceneManager()->addAnimatedMeshSceneNode(
			window->getM_sceneManager()
			->getMesh(
				window->getPath("assets/textures/BomberMan.3ds")));
	if (m_character2) {
		if (nbplayer == 1) {
			for (int i = 0; i < 14; i++) {
				for (int j = 0; j < 14; j++) {
					if (refreshmap[i][j] == '1') {
						px = i - 1;
						py = j - 1;
					}
				}
			}
			m_character2->setPosition(irr::core::vector3df(-132 * py, 0, 132 * px));
		}
		else if (nbplayer == 2) {
			for (int i = 0; i < 14; i++) {
				for (int j = 0; j < 14; j++) {
					if (refreshmap[i][j] == '2') {
						px = i - 1;
						py = j - 1;
					}
				}
			}
			m_character2->setPosition(irr::core::vector3df(-132 * py, 0, 132 * px));
		}
		m_character2->setMaterialTexture(0, window
						 ->getM_driver()
						 ->getTexture(
							 window->getPath("assets/textures/BomberMan.tga")));
		m_character2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		m_character2->setAnimationSpeed(15);
		m_character2->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
		if (nbplayer == 1)
			m_character2->setRotation(irr::core::vector3df(-90, 180, 0));
		else if (nbplayer == 2)
			m_character2->setRotation(irr::core::vector3df(-90, 0, 0));
	}
}

Player::~Player()
{
	delete m_character2;
}

irr::scene::IAnimatedMeshSceneNode	*Player::getM_character2() const
{
	return m_character2;
}
