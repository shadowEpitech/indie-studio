//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Event class definition
//

#ifndef _MyEventReceiver_H_
#define _MyEventReceiver_H_

#include <irr/irrlicht.h>
#include <irr/driverChoice.h>

class MyEventReceiver : public irr::IEventReceiver
{
	public:
		MyEventReceiver();
		~MyEventReceiver() override;
		bool	OnEvent(const irr::SEvent &event) override;
		bool	isKeyDown(irr::EKEY_CODE keyCode) const;
		void	setSkinTransparency(irr::u32 alpha,
						irr::gui::IGUISkin *skin);
	private:
		bool		m_keyIsDown[irr::KEY_KEY_CODES_COUNT];
};

#endif /* _MyEventReceiver_H_ */
