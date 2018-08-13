//
// EPITECH PROJECT, 2018
//
// File description:
//
//
#include <irr/IVideoDriver.h>
#include "Lib.hpp"

LibIrrlicht::LibIrrlicht(irr::IrrlichtDevice *m_device,
			irr::gui::IGUIEnvironment *m_gui,
			irr::video::IVideoDriver *m_driver,
			irr::scene::ISceneManager *m_smgr)
{
	this->m_device = m_device;
	this->m_gui = m_gui;
	this->m_driver = m_driver;
	this->m_smgr = m_smgr;
}

LibIrrlicht::~LibIrrlicht()
{
	m_device->drop();
	m_smgr->clear();
	m_driver->drop();
}

bool	 LibIrrlicht::drawRect(Entity *node)
{
	irr::scene::ISceneNode	*n = m_smgr->addCubeSceneNode();

	if (n) {
		n->setMaterialTexture(0, m_driver->getTexture("../assets/img/media/t351sml.jpg"));
		//node->getTexturePath().c_str()));
		n->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		n->setPosition(irr::core::vector3df(node->getX() * 20,node->getY() * 20,0));
		n->setScale(irr::core::vector3df(10,10,0));
	}
	return true;
}

bool	 LibIrrlicht::drawModels(Entity *obj)
{
	irr::scene::IAnimatedMesh* mesh = m_smgr->getMesh(obj->getMeshPath().c_str());
	if (!mesh)
	{
		m_device->drop();
		return false;
	}
	irr::scene::IAnimatedMeshSceneNode* node = m_smgr->addAnimatedMeshSceneNode( mesh );
	if (node)
	{
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		if (!obj->getTexturePath().empty())
			node->setMaterialTexture( 0, m_driver->getTexture(obj->getTexturePath().c_str()));
		node->setPosition(irr::core::vector3df(obj->getX() * 20, obj->getY() * 20,0));
		node->setScale(irr::core::vector3df(10,10,0));
	}
	return true;
}

bool	LibIrrlicht::drawScene(const std::vector<Entity *> &map)
{
	bool correctly_draw = false;
	for (int i = 0; i < map.size(); i++)
		std::cout << map[i]->getType() << std::endl;
	for (int i = 0; i < map.size(); i++) {
		if (map[i]->getType() == Entity::BOMB) {
			correctly_draw = drawModels(map[i]);
		}
		if (map[i]->getType() == Entity::BRICK) {
			correctly_draw = drawRect(map[i]);
		}
		if (map[i]->getType() == Entity::WALL) {
			correctly_draw = drawRect(map[i]);
		}
		if (map[i]->getType() == Entity::RECT) {
			correctly_draw = drawRect(map[i]);
		}
		else {
				correctly_draw = drawRect(map[i]);

		}
		if (!correctly_draw)
			return false;
	}
	return correctly_draw;
}

bool	LibIrrlicht::displayScene()
{
	if (m_device->isWindowActive()) {
		m_gui->drawAll();
		m_smgr->drawAll();
		m_driver->endScene();
	}
	return true;
}
