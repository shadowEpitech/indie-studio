/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** MyEventReceiver for cpp_indie_studio
*/

#include "MyEventReceiver.hpp"

MyEventReceiver::MyEventReceiver()
{
	for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++) {
		m_keyIsDown[i] = false;
	}
}

MyEventReceiver::~MyEventReceiver()
{}

bool	MyEventReceiver::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		m_keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	return false;
}

bool	MyEventReceiver::isKeyDown(irr::EKEY_CODE keyCode) const
{
	return m_keyIsDown[keyCode];
}

void	 MyEventReceiver::setSkinTransparency(irr::u32 alpha, irr::gui::IGUISkin *skin)
{
	for (irr::s32 i = 0; i < irr::gui::EGDC_COUNT; i++)
	{
		irr::video::SColor col = skin->getColor(
		    (irr::gui::EGUI_DEFAULT_COLOR)i);
		col.setAlpha(alpha);
		skin->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
	}
}
