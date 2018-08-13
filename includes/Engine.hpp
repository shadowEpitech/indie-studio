//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Engine class definition
//

#ifndef	ENGINE_HPP_
#define ENGINE_HPP_

#include <vector>
#include <string>
#include <irr/driverChoice.h>
#include <irr/irrlicht.h>
#include <irrKlang/irrKlang.h>
#include "MyEventReceiver.hpp"
#include "Entity.hpp"
#include "Music.hpp"
#include "Window.hpp"
#include <iostream>
#include <chrono>

enum {
	BUTTON_START,
	BUTTON_OPTION,
	BUTTON_QUIT,
	BUTTON_BACK,
	BUTTON_SOLO,
	BUTTON_MULTI,
	BUTTON_LVL,
	BUTTON_MUSIQUE,
	BUTTON_LUM,
	BUTTON_TRANS,
	BUTTON_ON,
	BUTTON_OFF
};

class Engine : public MyEventReceiver
{
	public:
		Engine();
		~Engine() override;
		int	run();
		// irr::EKEY_CODE	move(MyEventReceiver receiver);
		bool	initWindow();
		bool	OnEvent(const irr::SEvent &event) override;
		bool	startGame();
//		irr::scene::ISceneNode	*getBlock(
 //		    irr::scene::ISceneManager *smgr,
//		    irr::video::IVideoDriver *driver);
		irr::scene::IAnimatedMeshSceneNode	*createNode(
		    irr::video::IVideoDriver *driver,
		    irr::scene::ISceneManager *smgr);
		void	setNode(irr::scene::IAnimatedMeshSceneNode *node) const;
		irr::core::vector3df	&place(
		    const MyEventReceiver &receiver,
		    irr::scene::IAnimatedMeshSceneNode *node,
		    const irr::f32 MOVEMENT_SPEED,
		    const irr::f32 frameDeltaTime,
		    irr::core::vector3df &nodePosition) const;
		bool	initOption();
		bool	initPlayer();
		irr::scene::IAnimatedMeshSceneNode	*create_character_two
		    (irr::scene::ISceneManager *smgr,
		     irr::video::IVideoDriver *driver);
		irr::scene::IAnimatedMeshSceneNode	*create_character_one
		    (irr::scene::ISceneManager* smgr, irr::video::IVideoDriver *driver);
		void	movement_character_one(irr::scene::IAnimatedMeshSceneNode *node, irr::u32 then,
					   const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime,
					   MyEventReceiver &receiver);
		void	movement_character_two(
		    irr::scene::IAnimatedMeshSceneNode *character2,
		    irr::u32 then, const irr::f32 MOVEMENT_SPEED,
		    const irr::u32 now, const irr::f32 frameDeltaTime,
		    MyEventReceiver &receiver);
	private:
		Window				m_window;
		MyEventReceiver			m_receiver;
};

#endif /* ENGINE_HPP_ */
