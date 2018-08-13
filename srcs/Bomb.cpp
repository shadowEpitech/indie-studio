//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb class implementation
//

#include "Bomb.hpp"

Bomb::Bomb(int x, int y, Entity::ObjectType type)
{
	m_x = x;
	m_y = y;
	m_type = type;
	m_time = time(nullptr);
	m_mesh_path = "";
	m_texture_path = Window::getPath(
	    "assets/img/terrain-texture.jpg").c_str();
	m_bomb = nullptr;
}

bool	Bomb::checkDelete(Window *window)
{
	if (time(nullptr) - m_time >= 3) {
		auto	BombPosition = m_bomb->getPosition() - 25;
		m_bomb->remove(); //enlèvement de la bombe
		//début création feu et vérification du temp qui passe
		irr::scene::IParticleSystemSceneNode *ps =
		    window->getM_sceneManager()->addParticleSystemSceneNode
			(false);
		//création feu
		irr::scene::IParticleEmitter *em = ps->createBoxEmitter(
		    irr::core::aabbox3d<irr::f32>(-7, 0, -7, 7, 1, 7),
		    irr::core::vector3df(0.0f, 0.06f, 0.0f), 80, 100,
		    irr::video::SColor(0, 255, 255, 255),
		    irr::video::SColor(0, 255, 255, 255), 800, 2000, 0,
		    irr::core::dimension2df(10.f, 10.f),
		    irr::core::dimension2df(20.f, 20.f));
		ps->setEmitter(em);
		em->drop();
		irr::scene::IParticleAffector *paf = ps
		    ->createFadeOutParticleAffector();
		ps->addAffector(paf);
		paf->drop();
		ps->setPosition(BombPosition);
		ps->setScale(irr::core::vector3df(5, 5, 5));
		ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		ps->setMaterialTexture(0, window->getM_driver()
		    ->getTexture
			(Window::getPath("assets/textures/fire.bmp")));
		return true;
	}
	return false;
}

bool	Bomb::exist()
{
	return (m_bomb != nullptr);
}

irr::scene::IAnimatedMeshSceneNode	*Bomb::createBomb(
    irr::scene::IAnimatedMeshSceneNode *character2,
    Window *window)
{
	m_mesh_path = Window::getPath(
	    "assets/img/aquabomb.obj").c_str();
	m_texture_path = "";
	m_bomb = window->getM_sceneManager()->addAnimatedMeshSceneNode(
		window->getM_sceneManager()->getMesh
		    (Window::getPath("assets/textures/bomb.obj")),
		nullptr, 0); //initialisation bombe
	if (m_bomb) {
		m_bomb->setPosition(character2->getPosition());
		m_bomb->setMaterialTexture(0, window->getM_driver()->getTexture
		    (Window::getPath("assets/textures/bomb.tga")));
		m_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);

		 // fin création feu et vérification du temp qui passe
	}
}
