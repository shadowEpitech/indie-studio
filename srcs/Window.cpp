//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Window class implementation
//

#include <cstring>
#include <Game.hpp>
#include "Window.hpp"

Window::Window(unsigned int height, unsigned int width,
	       const wchar_t *title)
{
	m_musicDevice.setMusic(getPath("assets/music/SNESBomberman.ogg")
				   .c_str(),
			       true);
	m_driverType = irr::video::EDT_OPENGL;
	m_device = irr::createDevice(m_driverType,
				     irr::core::dimension2d<irr::u32>(height,
								      width),
                                 16, false, false, false, this);

	if (!m_device)
		exit(84);
	m_device->setWindowCaption(title);
	m_driver = m_device->getVideoDriver();
	m_gui = m_device->getGUIEnvironment();
	m_sceneManager = m_device->getSceneManager();
}

Window::~Window()
{}

bool	Window::createMenu(const wchar_t *title, int i)
{
	Game	game(this);
	m_sceneManager->clear();
	if (!m_device)
		return false;
	m_device->setWindowCaption(title);
	m_device->setResizable(false);
	m_gui->addImage(m_driver->getTexture(getPath("assets/img/menu"
						     ".png")),
			irr::core::position2d<irr::s32>(0, 0));
	createButton(irr::core::rect<irr::s32>(650, 270, 900, 490),
	        getPath("assets/img/start.png"), BUTTON_START);
	createButton(irr::core::rect<irr::s32>(650, 450, 900, 580),
	        getPath("assets/img/options.png"), BUTTON_OPTION);
	createButton(irr::core::rect<irr::s32>(650, 590, 900, 690 + 32),
	        getPath("assets/img/exit.png"), BUTTON_QUIT);
	m_device->getCursorControl()->setVisible(true);
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
		if (i == 1)
		game.startGame();
	}
	m_device->drop();
	return true;
}

irr::gui::IGUIButton	*Window::createButton(
    const irr::core::rect<irr::s32>&rectangle,
    const irr::io::path &imagePath, irr::s32 id)
{
	irr::gui::IGUIButton	*button = m_gui->addButton(rectangle, nullptr,
	    id);
	irr::video::ITexture	*textuStart = m_driver->getTexture(imagePath);
	button->setUseAlphaChannel(true);
	button->setDrawBorder(false);
	button->setImage(textuStart);
	return button;
}

bool	Window::OnEvent(const irr::SEvent &event)
{
	Game	game(this);

	if (event.EventType == irr::EET_GUI_EVENT) {
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
			switch (event.GUIEvent.Caller->getID()) {
				case BUTTON_START:
					game.initPlayer();
					break;
				case BUTTON_SOLO:
					game.startGame();
					break;
				case BUTTON_OPTION:
					option();
					return true;
				case BUTTON_OFF:
					m_musicDevice.removeAllSoundSources();
					break;
				case BUTTON_ON:
					m_musicDevice
					    .setMusic(getPath(
					        "assets/music/SNESBomberman.ogg").c_str()),
					     true;
					break;
				case BUTTON_BACK:
					createMenu(L"Bomberman menu", 0);
					break;
				case BUTTON_QUIT:
					m_device->closeDevice();
					exit(0);
			}
		}
	}
	return false;
}

irr::io::path	Window::getPath(std::string const &path)
{
	#ifdef __linux__
		std::string	absPath = "/usr/share/" + path;
		irr::io::path	path1(absPath.c_str());
	#elif __WIN32__
		std::string	absPath = "" + path;
		irr::io::path	path1(absPath.c_str());
	#endif
	return path1;
}

bool	Window::option()
{
	m_sceneManager->clear();
	if (!m_device)
		return false;
	m_device->setResizable(false);
	m_device->setWindowCaption(L"Options");
	irr::gui::IGUIScrollBar	*scrollbar = m_gui
	    ->addScrollBar(true, irr::core::rect<irr::s32>(585, 350, 890, 480),
			   nullptr, BUTTON_TRANS);
	scrollbar->setMax(255);
	scrollbar->setPos(255);
	setSkinTransparency((irr::u32)scrollbar->getPos(),
				       m_gui->getSkin());
	// set scrollbar position to alpha value of an arbitrary element
	scrollbar->setPos(m_gui->getSkin()->getColor(irr::gui::EGDC_WINDOW)
			      .getAlpha());
	m_gui->addImage(m_driver->getTexture(getPath("assets/img/back.jpeg")),
			irr::core::position2d<irr::s32>(0,0));
	createButton(
	    irr::core::rect<irr::s32>(900, 100, 1200, 490),
	    getPath("assets/img/Off.png"), BUTTON_OFF);
	createButton(
	    irr::core::rect<irr::s32>(200, 200, 900, 400),
	        getPath("assets/img/On.png"),
	    BUTTON_ON);
	createButton(
	    irr::core::rect<irr::s32>(630, 370, 1000, 680),
	        getPath("assets/img/Back3.png"), BUTTON_BACK);
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

irr::scene::ISceneManager	*Window::getM_sceneManager() const
{
	return m_sceneManager;
}

irr::gui::IGUIEnvironment	*Window::getM_gui() const
{
	return m_gui;
}

irr::video::IVideoDriver	*Window::getM_driver() const
{
	return m_driver;
}

irr::IrrlichtDevice	*Window::getM_device() const
{
	return m_device;
}

Music	&Window::getM_musicDevice()
{
	return m_musicDevice;
}

irr::gui::IGUIFont  *Window::setFontWindow(const irr::io::path &fontName) const
{
    irr::gui::IGUISkin    *skin = m_gui->getSkin();
    irr::gui::IGUIFont    *font = m_gui->getFont(fontName);
    if (font)
        skin->setFont(font);
    skin->setFont(m_gui->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    return font;
}
