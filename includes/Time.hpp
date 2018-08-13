//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Time class definition
//

#ifndef _TIME_HPP_
#define _TIME_HPP_

#include "Window.hpp"

class	Time
{
	public:
		Time(Window *window);
		irr::u32	getM_then() const;
		void		setTime(const irr::u32 now);

	private:
		irr::u32	m_then;
};

#endif /* _TIME_HPP_ */
