//
// EPITECH PROJECT, 2018
// 
// File description:
// Lib irrlicht class
//

#ifndef LIB_HPP
# define LIB_HPP

#include <irr/driverChoice.h>
#include <vector>
#include <irr/irrlicht.h>
#include <vector>
#include <string>
#include "Entity.hpp"

class LibIrrlicht {
	public:
	LibIrrlicht(irr::IrrlichtDevice *m_device,
			irr::gui::IGUIEnvironment *m_gui,
			irr::video::IVideoDriver *m_driver,
			irr::scene::ISceneManager *m_smgr
		);

	~LibIrrlicht();
		bool drawScene(const std::vector<Entity *> &map);
		bool drawModels(Entity *node);
		bool drawRect(Entity *node);
		bool	displayScene();
	//	bool drawText(Entity *node);
	private:
		irr::IrrlichtDevice		*m_device;
		irr::gui::IGUIEnvironment	*m_gui;
		irr::video::IVideoDriver	*m_driver;
		irr::scene::ISceneManager	*m_smgr;
};

#endif /* LIB_HPP */
