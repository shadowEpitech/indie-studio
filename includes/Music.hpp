//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Music class definition
//

#ifndef _MUSIC_HPP_
#define _MUSIC_HPP_

#include <irr/irrlicht.h>
#include <irrKlang/irrKlang.h>
#include <string>

/* Music.hpp */
class Music
{
	public:
		Music();
		~Music();
		bool	setMusic(const char *soundFileName,
				     bool playLooped = false);
		bool	removeAllSoundSources();
		const char	*getPath(std::string const &path);

	private:
		irrklang::ISoundEngine	*m_musicDevice;
};

#endif /* _MUSIC_HPP_ */
