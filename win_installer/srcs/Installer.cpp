//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Installer class implementation
//

#include "Installer.hpp"
#include "Windows.hpp"

Installer::Installer(Window window) : m_window(window)
{}

Installer::~Installer()
{}

bool    Installer::setMenu(const wchar_t *title)
{
    m_window.getM_sceneManager()->clear();
    if (!m_window.getM_device())
        return false;
    m_window.getM_device()->setWindowCaption(title);
    m_window.getM_device()->setResizable(false);
    m_window.getM_gui()->addImage(m_window.getM_driver()
                                          ->getTexture("assets/img/mainmenu.png"),
                    irr::core::position2d<irr::s32>(0, 0));
    irr::gui::IGUIStaticText    *text = m_window.getM_gui()
            ->addStaticText(L"Path for install",
                            irr::core::rect<irr::s32>(200, 70, 550, 100));
    m_window.createButton(
            irr::core::rect<irr::s32>(900, 100, 1200, 490),
            "assets/img/Off.png", m_window.BUTTON_OFF);
    m_window.createButton(
            irr::core::rect<irr::s32>(200, 200, 900, 400), "assets/img/On.png",
            m_window.BUTTON_ON);
    m_window.createButton(irr::core::rect<irr::s32>(800, 490, 1000, 590 + 32),
            "assets/img/start.png", m_window.BUTTON_INSTALL);
    while (m_window.getM_device()->run() && m_window.getM_driver()) {
        if (m_window.getM_device()->isWindowActive()) {
            m_window.getM_driver()->beginScene(
                    true,
                    true,
                    irr::video::SColor(0, 0, 191, 255));
            m_window.getM_gui()->drawAll();
            m_window.getM_driver()->endScene();
            m_window.getM_device()->setEventReceiver(this);
        }
    }
    text->drop();
    m_window.getM_device()->drop();
    return true;
}

bool	Installer::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
            switch (event.GUIEvent.Caller->getID()) {
                case m_window.BUTTON_INSTALL:
                    install();
                    break;
                /*case m_window.BUTTON_CHECK_INSTALL:
                    check_install();
                    break;*/
                case m_window.BUTTON_LAUNCH_INSTALL:
                    install_bomberman();
                    break;
                case m_window.BUTTON_OFF:
                    m_window.getM_musicDevice().removeAllSoundSources();
                    break;
                case m_window.BUTTON_ON:
                    m_window.getM_musicDevice().setMusic
                            ("assets/music/Music_home.ogg",
                             true);
                    break;
                case m_window.BUTTON_BROWSE:
                    m_pathInstall = setPathInstall();
                    break;
            }
        }
    }
    return false;
}

bool    Installer::install()
{
    m_window.getM_sceneManager()->clear();
    if (!m_window.getM_device())
        return false;
    m_window.getM_device()->setWindowCaption(L"Choose directory of installation");
    m_window.getM_device()->setResizable(false);
    m_window.getM_gui()->addImage(m_window.getM_driver()
                                          ->getTexture("assets/img/back.jpeg"),
                                  irr::core::position2d<irr::s32>(0, 0));
    m_window.createButton(irr::core::rect<irr::s32>(200, 200, 900, 400),
                          "assets/img/options.png", m_window.BUTTON_BROWSE);
    m_window.createButton(irr::core::rect<irr::s32>(800, 490, 1000, 590 + 32),
                          "assets/img/start.png", m_window.BUTTON_LAUNCH_INSTALL);
    m_window.setFontWindow("irrlicht-1.8.4/media/fonthaettenschweiler.bmp");
    m_editBox = m_window.getM_gui()
            ->addEditBox(L"C:\\Users\\arthu\\Documents\\cpp_indie_studio",
                            irr::core::rect<irr::s32>(200, 80, 550, 100),
                            true);
    while (m_window.getM_device()->run() && m_window.getM_driver()) {
        if (m_window.getM_device()->isWindowActive()) {
            m_window.getM_driver()->beginScene(
                    true,
                    true,
                    irr::video::SColor(0, 0, 191, 255));
            m_window.getM_gui()->drawAll();
            m_window.getM_driver()->endScene();
            m_window.getM_device()->setEventReceiver(this);
        }
    }
    m_editBox->drop();
    m_window.getM_device()->drop();
    return true;
}

const wchar_t    *Installer::setPathInstall()
{
    std::string path = Windows::BrowseFolder();

    if (!path.empty()) {
        const wchar_t   *pathInstall = std::wstring(path.begin(),
                path.end()).c_str();
        m_editBox->setText(pathInstall);
        return pathInstall;
    }
    return std::wstring(path.begin(), path.end()).c_str();
}

bool    Installer::install_bomberman()
{
    m_window.getM_sceneManager()->clear();
    if (!m_window.getM_device())
        return false;
    m_window.getM_device()->setWindowCaption(L"Installation of Bomberman");
    m_window.getM_device()->setResizable(false);
    m_window.getM_gui()->addImage(m_window.getM_driver()
                                          ->getTexture("assets/img/back.jpeg"),
                                  irr::core::position2d<irr::s32>(0, 0));
    m_window.getM_gui()->addStaticText(L"You have sucessfully install"
                                       " Bomberman game",
        irr::core::rect<irr::s32>(800, 490, 1000, 590 + 32));
    m_window.createButton(irr::core::rect<irr::s32>(800, 490, 1000, 590 + 32),
                          "assets/img/quit.png", m_window.BUTTON_QUIT);
    m_window.setFontWindow("assets/media/fonthaettenschweiler.bmp");
    Windows::copyFolder(m_pathInstall);
    // Windows::createSymlink();
    while (m_window.getM_device()->run() && m_window.getM_driver()) {
        if (m_window.getM_device()->isWindowActive()) {
            m_window.getM_driver()->beginScene(
                    true,
                    true,
                    irr::video::SColor(0, 0, 191, 255));
            m_window.getM_gui()->drawAll();
            m_window.getM_driver()->endScene();
            m_window.getM_device()->setEventReceiver(this);
        }
    }
    m_window.getM_device()->drop();
    return true;
}

/*bool    Installer::check_install()
{
    m_window.getM_sceneManager()->clear();
    if (!m_window.getM_device())
        return false;
    m_window.getM_device()->setWindowCaption(L"Check informations before installing Bomberman");
    m_window.getM_device()->setResizable(false);
    m_window.getM_gui()->addImage(m_window.getM_driver()
                                          ->getTexture("assets/img/back.jpeg"),
                                  irr::core::position2d<irr::s32>(0, 0));
    m_window.createButton(
            irr::core::rect<irr::s32>(630, 370, 1000, 680),
            "assets/img/Back3.png", m_window.BUTTON_INSTALL);
    m_window.createButton(irr::core::rect<irr::s32>(800, 490, 1000, 590 + 32),
                          "assets/img/start.png", m_window.BUTTON_LAUNCH_INSTALL);
    m_window.setFontWindow("irrlicht-1.8.4/media/fonthaettenschweiler.bmp");
    m_window.getM_gui()->addStaticText(L"Path for install", irr::core::rect<irr::s32>(200, 70, 550, 100));
    while (m_window.getM_device()->run() && m_window.getM_driver()) {
        if (m_window.getM_device()->isWindowActive()) {
            m_window.getM_driver()->beginScene(
                    true,
                    true,
                    irr::video::SColor(0, 0, 191, 255));
            m_window.getM_gui()->drawAll();
            m_window.getM_driver()->endScene();
            m_window.getM_device()->setEventReceiver(this);
        }
    }
    m_window.getM_device()->drop();
    return true;
}*/


