//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Window class definition
//

#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <irr/irrlicht.h>
#include <string>
#include "MyEventReceiver.hpp"
#include "Music.hpp"

#define HEIGHT	1600
#define WIDTH	800

/* Window.hpp */
class Window : public MyEventReceiver
{
	public:
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
			BUTTON_OFF,
			BUTTON_INSTALL,
            		BUTTON_BROWSE,
			BUTTON_CHECK_INSTALL,
			BUTTON_LAUNCH_INSTALL,
			BUTTON_EXIT
		};

		Window();
		Window(unsigned int height, unsigned int width,
		       const wchar_t *title);
		~Window();
		bool	createMenu(const wchar_t *title, int i);
		irr::gui::IGUIButton	*createButton(
		    const irr::core::rect<irr::s32>&rectangle,
		    const irr::io::path &imagePath, irr::s32 id = -1);
		bool	option();
		bool	OnEvent(const irr::SEvent &event) override;
		irr::scene::ISceneManager *getM_sceneManager() const;
		irr::gui::IGUIEnvironment *getM_gui() const;
		irr::video::IVideoDriver *getM_driver() const;
		irr::IrrlichtDevice *getM_device() const;
		Music   &getM_musicDevice();
		irr::gui::IGUIFont  *setFontWindow(const irr::io::path &fontName) const;
	static irr::io::path	getPath(std::string const &path);

	protected:
		irr::video::E_DRIVER_TYPE	m_driverType;
		irr::scene::ISceneManager	*m_sceneManager;
		irr::gui::IGUIEnvironment	*m_gui;
		irr::video::IVideoDriver	*m_driver;
		irr::IrrlichtDevice		*m_device;
        	Music				m_musicDevice;
};

#endif /* _WINDOW_HPP_ */
