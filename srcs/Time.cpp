//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Time class implementation
//

#include "Time.hpp"

Time::Time(Window *window) : m_then(window
					->getM_device()
					->getTimer()
					->getTime())
{}

irr::u32	Time::getM_then() const
{
	return m_then;
}

void	Time::setTime(const irr::u32 time)
{
	m_then = time;
}
