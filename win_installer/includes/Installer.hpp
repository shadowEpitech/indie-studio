//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Installer class definition
//

#ifndef _INSTALLER_HPP_
#define _INSTALLER_HPP_

#include "Window.hpp"

class Installer : public MyEventReceiver
{
    public:
        Installer(Window window);
        ~Installer();
        bool    setMenu(const wchar_t *title);
        bool	OnEvent(const irr::SEvent &event);
        bool    install();
        const wchar_t    *setPathInstall();
        bool    check_install();
        bool    install_bomberman();

    private:
        Window                  m_window;
        irr::gui::IGUIEditBox   *m_editBox;
        const wchar_t           *m_pathInstall;
};

#endif /*_INSTALLER_HPP_ */
