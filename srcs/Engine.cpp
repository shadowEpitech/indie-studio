//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "Engine.hpp"
#include "Map.hpp"
#include "Lib.hpp"

#pragma comment(lib, "irrKlang.lib") //link with irrKlang.dll

Engine::Engine()
{
	Window	window(1600, 800, L"Bomberman menu");
}


Engine::~Engine()
{}

bool	Engine::initWindow()
{
	m_sceneManager->clear();
	if (!m_device)
		return false;
	m_device->setWindowCaption(L"Bomberman menu");
	m_device->setResizable(false);
	m_gui->addImage(m_driver->getTexture("assets/img/mainmenu.png"),
			irr::core::position2d<irr::s32>(0,0));
	irr::gui::IGUIButton *start = m_gui->addButton(
	    irr::core::rect<irr::s32>(750, 170, 1000, 390),
	    nullptr,
	    BUTTON_START);
	irr::video::ITexture *textuStart = m_driver
	    ->getTexture("assets/img/start.png");
	start->setUseAlphaChannel(true);
	start->setDrawBorder(false);
	start->setImage(textuStart);
	irr::gui::IGUIButton	*option = m_gui->addButton(irr::core::rect<irr::s32>(750, 350, 1060, 480),
							nullptr,
							BUTTON_OPTION);
	textuStart = m_driver->getTexture("assets/img/options.png");
	option->setUseAlphaChannel(true);
	option->setDrawBorder(false);
	option->setImage(textuStart);
	irr::gui::IGUIButton	*quit =  m_gui->addButton(irr::core::rect<irr::s32>(800, 490, 1000, 590 + 32),
						       nullptr,
						       BUTTON_QUIT);
	textuStart = m_driver->getTexture("assets/img/exit.png");
	quit->setUseAlphaChannel(true);
	quit->setDrawBorder(false);
	quit->setImage(textuStart);
	return true;

}

int				Engine::run()
{
	if (!initWindow() || !m_driverType)
		return 84;
	while (m_device->run() && m_driver) {
		if (m_device->isWindowActive()) {
			m_driver->beginScene(
			    true,
			    true,
			    irr::video::SColor(0, 0, 191, 255));
			m_gui->drawAll();
			m_driver->endScene();
			m_device->setEventReceiver(this);
		}
	}
	m_device->drop();
	m_musicDevice.drop();
	return 0;

}

irr::scene::IAnimatedMeshSceneNode	*Engine::create_character_one
    (irr::scene::ISceneManager* smgr, irr::video::IVideoDriver *driver)
{
	irr::scene::IAnimatedMeshSceneNode* node =
	    smgr->addAnimatedMeshSceneNode(smgr->getMesh
		("assets/assets/textures/BomberMan.3ds"));
	if (node)
	{
		node->setPosition(irr::core::vector3df(0,0,30));
		node->setMaterialTexture(0, driver->getTexture("assets/assets/textures/BomberMan.tga"));
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);

		node->setFrameLoop(183, 204);
		node->setAnimationSpeed(15);

		node->setScale(irr::core::vector3df(1.f,1.f,1.f));
		node->setRotation(irr::core::vector3df(-90,0,0));
	}
	return (node);
}

irr::scene::IAnimatedMeshSceneNode	*Engine::create_character_two
    (irr::scene::ISceneManager* smgr, irr::video::IVideoDriver *driver)
{
	irr::scene::IAnimatedMeshSceneNode* character2 =
	    smgr->addAnimatedMeshSceneNode(smgr->getMesh("assets/assets/textures/BomberMan.3ds"));
	if (character2)
	{
		character2->setPosition(irr::core::vector3df(120,0,30));
		character2->setMaterialTexture(0, driver->getTexture("assets/assets/textures/BomberMan.tga"));
		character2->setMaterialFlag(irr::video::EMF_LIGHTING, false);

		character2->setFrameLoop(183, 204);
		character2->setAnimationSpeed(15);

		character2->setScale(irr::core::vector3df(1.f,1.f,1.f));
		character2->setRotation(irr::core::vector3df(-90,0,0));
	}
	return (character2);
}

void	Engine::movement_character_one(irr::scene::IAnimatedMeshSceneNode
					   *node, irr::u32 then,
				   const irr::f32 MOVEMENT_SPEED,
				   const irr::f32 frameDeltaTime,
				   MyEventReceiver &receiver)
{
	irr::core::vector3df nodePosition = node->getPosition();

	if(receiver.isKeyDown(irr::KEY_KEY_S)) {
		nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
		node->setAnimationSpeed(15);
		node->setScale(irr::core::vector3df(1.f,1.f,1.f));
		node->setRotation(irr::core::vector3df(-90,180,0));
	}
	else if(receiver.isKeyDown(irr::KEY_KEY_Z)) {
		nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
		node->setAnimationSpeed(15);
		node->setScale(irr::core::vector3df(1.f,1.f,1.f));
		node->setRotation(irr::core::vector3df(-90,0,0));
	}
	else
		node->setAnimationSpeed(15);

	if(receiver.isKeyDown(irr::KEY_KEY_D)) {
		nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
		node->setAnimationSpeed(15);
		node->setScale(irr::core::vector3df(1.f,1.f,1.f));
		node->setRotation(irr::core::vector3df(-90,-90,0));
	}
	else if(receiver.isKeyDown(irr::KEY_KEY_Q)) {
		nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
		node->setAnimationSpeed(15);
		node->setScale(irr::core::vector3df(1.f,1.f,1.f));
		node->setRotation(irr::core::vector3df(-90,90,0));
	}
	else
		node->setAnimationSpeed(15);
	node->setPosition(nodePosition);
}

void	Engine::movement_character_two(
    irr::scene::IAnimatedMeshSceneNode *character2, 
    irr::u32 then, const irr::f32 MOVEMENT_SPEED, 
    const irr::u32 now, const irr::f32 frameDeltaTime, 
    MyEventReceiver &receiver)
{
    irr::core::vector3df nodePosition2 = character2->getPosition();
	if (!receiver.isKeyDown(irr::KEY_DOWN)) {
		if (receiver.isKeyDown(irr::KEY_UP)) {
			nodePosition2.Z -= MOVEMENT_SPEED * frameDeltaTime;
			character2->setAnimationSpeed(15);
			character2->setScale(
			    irr::core::vector3df(1.f, 1.f, 1.f));
			character2->setRotation(
			    irr::core::vector3df(-90, 0, 0));
		} else
			character2->setAnimationSpeed(15);
	} else {
		nodePosition2.Z += MOVEMENT_SPEED * frameDeltaTime;
		character2->setAnimationSpeed(15);
		character2->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
		character2->setRotation(irr::core::vector3df(-90, 180, 0));
	}
	if (!receiver.isKeyDown(irr::KEY_RIGHT)) {
		if (receiver.isKeyDown(irr::KEY_LEFT)) {
			nodePosition2.X -= MOVEMENT_SPEED * frameDeltaTime;
			character2->setAnimationSpeed(15);
			character2->setScale(
			    irr::core::vector3df(1.f, 1.f, 1.f));
			character2->setRotation(
			    irr::core::vector3df(-90, 90, 0));
		} else
			character2->setAnimationSpeed(15);
	} else {
		nodePosition2.X += MOVEMENT_SPEED * frameDeltaTime;
		character2->setAnimationSpeed(15);
		character2->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
		character2->setRotation(irr::core::vector3df(-90, -90, 0));
	} // fin pour mouvement personnage	
    character2->setPosition(nodePosition2);
}

irr::scene::IAnimatedMeshSceneNode	*Engine::createNode(
    irr::video::IVideoDriver *driver, irr::scene::ISceneManager	*smgr)
{
	irr::scene::IAnimatedMeshSceneNode	*node =  smgr->addAnimatedMeshSceneNode(smgr->getMesh("assets/assets/textures/BomberMan.3ds"), nullptr, 0);
	if (node) {
		node->setPosition(irr::core::vector3df(0,0,30));
		node->setMaterialTexture(0, driver->getTexture("assets/assets/textures/BomberMan.tga"));
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);

		node->setAnimationSpeed(15);

		node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
		node->setRotation(irr::core::vector3df(-90, 0, 0));

		node->getMaterial(0).NormalizeNormals = true;
		node->getMaterial(0).Lighting = true;
	}
	return node;
}

bool	Engine::startGame()
{
	MyEventReceiver receiver;

	irr::IrrlichtDevice	*device = irr::createDevice(irr::video::EDT_OPENGL,
							irr::core::dimension2d<irr::u32>(640, 480),
							    16, false, false, false, &receiver);

	if (!device)
		return false; // fin initialisation
	irr::video::IVideoDriver	*driver = device->getVideoDriver();
	irr::scene::ISceneManager	*smgr = device->getSceneManager();
	device->setWindowCaption(L"Bomberman");
	device->getFileSystem()->addFileArchive("irrlicht-1.8.4/media/map-20kdm2.pk3");

	irr::scene::ITriangleSelector *selector = nullptr;

	irr::scene::ISceneNode	*block = smgr->addCubeSceneNode();
	if (block) {
		block->setPosition(irr::core::vector3df(20,0,30));
		block->setMaterialTexture(0, driver->getTexture("irrlicht-1.8.4/media/t351sml.jpg"));
		block->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		block->setScale(irr::core::vector3df(13.f,13.f,13.f));
	}
	//create_character_one(smgr, driver);
	irr::scene::IAnimatedMeshSceneNode	*node =
	    smgr->addAnimatedMeshSceneNode(m_sceneManager->getMesh("assets/textures/BomberMan.3ds"), 0, 0);
	if (node)
	{
		node->setPosition(irr::core::vector3df(0,0,30));
		node->setMaterialTexture(0, m_driver->getTexture("assets/textures/BomberMan.tga"));
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);

		node->setAnimationSpeed(15);

		node->setScale(irr::core::vector3df(1.f,1.f,1.f));
		node->setRotation(irr::core::vector3df(-90,0,0));

		node->getMaterial(0).NormalizeNormals = true;
		node->getMaterial(0).Lighting = true;
	}
	//create_character_two(smgr, driver);
	irr::scene::IAnimatedMeshSceneNode	*character2 =
	    smgr->addAnimatedMeshSceneNode(smgr->getMesh("assets/textures/BomberMan.3ds"));
	if (character2) {
		character2->setPosition(irr::core::vector3df(120,0,30));
		character2->setMaterialTexture(0, driver->getTexture("assets/textures/BomberMan.tga"));
		character2->setMaterialFlag(irr::video::EMF_LIGHTING, false);

		character2->setAnimationSpeed(15);

		character2->setScale(irr::core::vector3df(1.f,1.f,1.f));
		character2->setRotation(irr::core::vector3df(-90,0,0));
	}
	irr::scene::ICameraSceneNode *camera = smgr->addCameraSceneNode(nullptr,
									irr::core::vector3df(0, 1200, -1500),
									irr::core::vector3df(0, -500, 2000)); // début pour mouvement personnage
	device->getCursorControl()->setVisible(false);
	if (selector) {
		irr::scene::ISceneNodeAnimator *anim = smgr->createCollisionResponseAnimator(
		    selector, camera, irr::core::vector3df(30,50,30));
		selector->drop();
		camera->addAnimator(anim);
		anim->drop();
	}
	selector = smgr->createTriangleSelector(node);
	node->setTriangleSelector(selector);
	selector->drop();

	irr::scene::ISceneNode	*highlightedSceneNode = nullptr;
	irr::scene::ISceneCollisionManager	*collMan = smgr->getSceneCollisionManager();
	irr::video::SMaterial material;

	irr::u32 then = device->getTimer()->getTime();

	const irr::f32 MOVEMENT_SPEED = 400.f;

	auto	map = Map::MapGenerator();
	while(device->run()) {
		const irr::u32 now = device->getTimer()->getTime();
		const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f;
		then = now;

		//movement_character_one(create_character_one(smgr, driver), then, MOVEMENT_SPEED,
		//receiver);
		irr::core::vector3df nodePosition = node->getPosition();
		Map::print_map_entity(driver, map);
		if(receiver.isKeyDown(irr::KEY_KEY_S)) {
			nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
			node->setAnimationSpeed(15);
			node->setScale(irr::core::vector3df(1.f,1.f,1.f));
			node->setRotation(irr::core::vector3df(-90,180,0));
		}
		else if(receiver.isKeyDown(irr::KEY_KEY_Z)) {
			nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
			node->setAnimationSpeed(15);
			node->setScale(irr::core::vector3df(1.f,1.f,1.f));
			node->setRotation(irr::core::vector3df(-90,0,0));
		}
		else
			node->setAnimationSpeed(15);

		if (receiver.isKeyDown(irr::KEY_KEY_D)) {
			nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
			node->setAnimationSpeed(15);
			node->setScale(irr::core::vector3df(1.f,1.f,1.f));
			node->setRotation(irr::core::vector3df(-90,-90,0));
		}
		else if(receiver.isKeyDown(irr::KEY_KEY_Q)) {
			nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
			node->setAnimationSpeed(15);
			node->setScale(irr::core::vector3df(1.f,1.f,1.f));
			node->setRotation(irr::core::vector3df(-90,90,0));
		}
		else
			node->setAnimationSpeed(15);

		irr::core::vector3df nodePosition2 = character2->getPosition();

		if (receiver.isKeyDown(irr::KEY_UP)) {
			nodePosition2.Z += MOVEMENT_SPEED * frameDeltaTime;
			character2->setAnimationSpeed(15);
			character2->setScale(irr::core::vector3df(1.f,1.f,1.f));
			character2->setRotation(irr::core::vector3df(-90,180,0));
		}
		else if (receiver.isKeyDown(irr::KEY_DOWN)) {
			nodePosition2.Z -= MOVEMENT_SPEED * frameDeltaTime;
			character2->setAnimationSpeed(15);
			character2->setScale(irr::core::vector3df(1.f,1.f,1.f));
			character2->setRotation(irr::core::vector3df(-90,0,0));
		}
		else
			character2->setAnimationSpeed(15);

		if (receiver.isKeyDown(irr::KEY_RIGHT)) {
			nodePosition2.X += MOVEMENT_SPEED * frameDeltaTime;
			character2->setAnimationSpeed(15);
			character2->setScale(irr::core::vector3df(1.f,1.f,1.f));
			character2->setRotation(irr::core::vector3df(-90,-90,0));
		}
		else if (receiver.isKeyDown(irr::KEY_LEFT)) {
			nodePosition2.X -= MOVEMENT_SPEED * frameDeltaTime;
			character2->setAnimationSpeed(15);
			character2->setScale(irr::core::vector3df(1.f,1.f,1.f));
			character2->setRotation(irr::core::vector3df(-90,90,0));
		}
		else
			character2->setAnimationSpeed(15); // fin pour mouvement personnage
		if (receiver.isKeyDown(irr::KEY_KEY_B)) {
			irr::scene::IAnimatedMeshSceneNode *bomb =
				smgr->addAnimatedMeshSceneNode(smgr->getMesh("assets/textures/bomb.obj"), 0, 0);
			if (bomb) {
				bomb->setPosition(character2->getPosition());
				bomb->setMaterialTexture(0, driver->getTexture("assets/textures/bomb.tga"));
				bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			}
			for (auto runUntils = std::chrono::system_clock::now() + std::chrono::seconds(1);
			     std::chrono::system_clock::now() < runUntils;) {
			}
			irr::scene::IAnimatedMeshSceneNode* fire =
				smgr->addAnimatedMeshSceneNode(smgr->getMesh("assets/textures/fire.obj"), 0, 0);

			irr::scene::IAnimatedMeshSceneNode* fire2 =
				smgr->addAnimatedMeshSceneNode(smgr->getMesh("assets/textures/fire.obj"), 0, 0);

			if (fire) {
		        	fire->setPosition(character2->getPosition() - 25);
				fire2->setPosition(character2->getPosition() - 50);
		        	fire->setMaterialTexture(0, driver->getTexture("assets/textures/fire.tga"));
				fire->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				fire->setScale(irr::core::vector3df(5, 5, 5));
			}
		}

		node->setPosition(nodePosition);
		character2->setPosition(nodePosition2);
		driver->beginScene(true, true, irr::video::SColor(255,113,113,133));

		smgr->drawAll();
		device->getGUIEnvironment()->drawAll();

		irr::core::line3d<irr::f32> ray;
		ray.start = camera->getPosition();
		ray.end = ray.start + (camera->getTarget() - ray.start).normalize() * 1000.0f;

		irr::core::vector3df	intersection;
		irr::core::triangle3df	hitTriangle;

		irr::scene::ISceneNode	*selectedSceneNode = collMan->getSceneNodeAndCollisionPointFromRay(
		    ray, intersection, hitTriangle, 0);
		if (selectedSceneNode) {
			node->setPosition(intersection);
			driver->setTransform(irr::video::ETS_WORLD, irr::core::matrix4());
			driver->setMaterial(material);
			driver->draw3DTriangle(hitTriangle, irr::video::SColor(0,255,0,0));

			if ((selectedSceneNode->getID() & 1) == 1) {
				highlightedSceneNode = selectedSceneNode;

				highlightedSceneNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			}
		}
		m_gui->drawAll();
		smgr->drawAll();
		driver->endScene();
	}
	device->drop();
	return true;
}

irr::core::vector3df	&Engine::place(const MyEventReceiver &receiver,
				    irr::scene::IAnimatedMeshSceneNode *node,
				    const irr::f32 MOVEMENT_SPEED,
				    const irr::f32 frameDeltaTime,
				    irr::core::vector3df &nodePosition) const
{
	if (!receiver.isKeyDown(irr::KEY_KEY_S)) {
		if (receiver.isKeyDown(irr::KEY_KEY_Z)) {
			nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
			setNode(node);
			node->setRotation(irr::core::vector3df(-90, 0, 0));
		} else {
			node->setFrameLoop(184, 205);
			node->setAnimationSpeed(15);
		}
	} else {
		nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
		setNode(node);
		node->setRotation(irr::core::vector3df(-90, 180, 0));
	}
	if (!receiver.isKeyDown(irr::KEY_KEY_D)) {
		if (receiver.isKeyDown(irr::KEY_KEY_Q)) {
			nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
			setNode(node);
			node->setRotation(irr::core::vector3df(-90, 90, 0));
		} else {
			node->setFrameLoop(184, 205);
			node->setAnimationSpeed(15);
		}
	} else {
		nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
		setNode(node);
		node->setRotation(irr::core::vector3df(-90, -90, 0));
	} // fin mouvement personnage
	return nodePosition;
}

void	Engine::setNode(irr::scene::IAnimatedMeshSceneNode *node) const
{
	node->setFrameLoop(0, 13);
	node->setAnimationSpeed(15);
	node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
}

bool	Engine::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_GUI_EVENT) {
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
			switch (event.GUIEvent.Caller->getID()) {
			case BUTTON_START:
				initPlayer();
				break;
			case BUTTON_SOLO:
				startGame();
				break;
			case BUTTON_OPTION:
				initOption();
				return true;
			case BUTTON_OFF:
				m_musicDevice.removeAllSoundSources();
				break;
			case BUTTON_ON:
				m_musicDevice.setMusic
				    ("assets/music/Music_home.ogg", true);
				break;
			case BUTTON_BACK:
				initWindow();
				break;
			case BUTTON_QUIT:
				std::cout << "close"
					  << std::endl;
				m_device->closeDevice();
				exit(0);
		        }
		}
	}
	return false;
}

bool	Engine::initOption()
{
	m_sceneManager->clear();
	if (!m_device)
		return false;
	m_device->setResizable(false);
	m_device->setWindowCaption(L"Options");
	irr::gui::IGUIScrollBar	*scrollbar = m_gui->addScrollBar(true,
						     irr::core::rect<irr::s32>
						         (585, 350, 890, 480),
									nullptr,
									BUTTON_TRANS);
	scrollbar->setMax(255);
	scrollbar->setPos(255);
	setSkinTransparency((irr::u32)scrollbar->getPos(), m_gui->getSkin());
	// set scrollbar position to alpha value of an arbitrary element
	scrollbar->setPos(m_gui->getSkin()->getColor(irr::gui::EGDC_WINDOW)
			      .getAlpha());
	m_gui->addImage(m_driver->getTexture("assets/img/back.jpeg"),
			irr::core::position2d<irr::s32>(0,0));
	irr::gui::IGUIButton *off = m_gui->addButton(irr::core::rect<irr::s32>(900, 100, 1200, 490),
						     nullptr,
						     BUTTON_OFF);
	irr::video::ITexture *textuStart = m_driver->getTexture("assets/img/Off.png");
	off->setUseAlphaChannel(true);
	off->setDrawBorder(false);
	off->setImage(textuStart);
	irr::gui::IGUIButton *on = m_gui->addButton(irr::core::rect<irr::s32>(200, 200, 900, 400),
						    nullptr,
						    BUTTON_ON);
	textuStart = m_driver->getTexture("assets/img/On.png");
	on->setUseAlphaChannel(true);
	on->setDrawBorder(false);
	on->setImage(textuStart);
	irr::gui::IGUIButton *back = m_gui->addButton(irr::core::rect<irr::s32>(630, 370, 1000, 680),
						      nullptr,
						      BUTTON_BACK);
	textuStart = m_driver->getTexture("assets/img/Back3.png");
	back->setUseAlphaChannel(true);
	back->setDrawBorder(false);
	back->setImage(textuStart);
	while (m_device->run() && m_driver) {
		if (m_device->isWindowActive()) {
			m_driver->beginScene(
			    true,
			    true,
			    irr::video::SColor(0, 0, 191, 255));
			m_gui->drawAll();
			m_driver->endScene();
			m_device->setEventReceiver(this);
		}
	}
	return true;
}

bool	Engine::initPlayer()
{
	m_device->setWindowCaption(L"Game mode");
	m_gui->addImage(m_driver->getTexture("assets/img/back.jpeg"),
			irr::core::position2d<irr::s32>(0,0));
	irr::gui::IGUIButton *solo = m_gui->addButton(irr::core::rect<irr::s32>(120, 90, 900, 490),
						      nullptr,
						      BUTTON_SOLO);
	irr::video::ITexture     *textuStart = m_driver->getTexture("assets/img/solo2.png");
	solo->setUseAlphaChannel(true);
	solo->setDrawBorder(false);
	solo->setImage(textuStart);

	irr::gui::IGUIButton	*multi = m_gui->addButton(irr::core::rect<irr::s32>(650, 70, 1600, 490),
						       nullptr,
						       BUTTON_MULTI);
	textuStart = m_driver->getTexture("assets/img/multi2.png");
	multi->setUseAlphaChannel(true);
	multi->setDrawBorder(false);
	multi->setImage(textuStart);

	irr::gui::IGUIButton	*back = m_gui->addButton(irr::core::rect<irr::s32>(600, 455, 1000, 800),
						      nullptr,
						      BUTTON_BACK);
	textuStart = m_driver->getTexture("assets/img/Back3.png");
	back->setUseAlphaChannel(true);
	back->setDrawBorder(false);
	back->setImage(textuStart);
	while (m_device->run() && m_driver) {
		if (m_device->isWindowActive()) {
			m_driver->beginScene(
			    true,
			    true,
			    irr::video::SColor(0, 0, 191, 255));
			m_gui->drawAll();
			m_driver->endScene();
			m_device->setEventReceiver(this);
		}
	}
	return true;
}
