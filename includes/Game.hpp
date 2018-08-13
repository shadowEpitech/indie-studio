//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Game class definition
//

#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <irr/irrlicht.h>
#include "Window.hpp"
#include "Entity.hpp"

class Game
{
public:
	explicit Game(Window *window);
	~Game();
	bool	initPlayer();
	bool	startGame();
	void	printMap(std::vector<std::string>	mymap) const;
	irr::core::vector3df mouvementCharacter1(
		const MyEventReceiver &lreceiver,
		irr::scene::IAnimatedMeshSceneNode *character1,
		const irr::f32 MOVEMENT_SPEED,
		const irr::f32 frameDeltaTime, int *check,
	        std::vector<std::string> *refreshmap,
		std::vector<std::string> myrefreshmap,
		float now, float *timer) const;
	irr::core::vector3df mouvementCharacter2(
		const MyEventReceiver &lreceiver,
		irr::scene::IAnimatedMeshSceneNode *character2,
		const irr::f32 MOVEMENT_SPEED,
		const irr::f32 frameDeltaTime, int *check,
	        std::vector<std::string> *refreshmap,
		std::vector<std::string> myrefreshmap,
		float now, float *timer) const;
		irr::scene::IAnimatedMeshSceneNode	*createNode() const;
	/*irr::scene::IAnimatedMeshSceneNode	*setBomb(
	  const irr::scene::IAnimatedMeshSceneNode
	  *character2);
		void	setFire(irr::scene::IAnimatedMeshSceneNode *bomb,
		const irr::scene::IAnimatedMeshSceneNode
			     *character2);
			     void	countdown(float time);*/


private:
	void		getMapImg(
		int x, int y, int z, const char *img) const;
	Window  	*m_window;
	const irr::f32	m_movementSpeed = 400.f;
};

#endif /* _GAME_HPP_ */
