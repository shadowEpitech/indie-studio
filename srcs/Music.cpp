//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Music class implementation
//

#include <Music.hpp>

Music::Music()
{
	m_musicDevice = irrklang::createIrrKlangDevice();
}

Music::~Music()
{}

bool	Music::setMusic(const char *soundFileName, bool playLooped)
{
	if (m_musicDevice && !m_musicDevice->isCurrentlyPlaying(soundFileName)) {
		removeAllSoundSources();
		m_musicDevice->play2D(soundFileName, playLooped);
	}
}

bool	Music::removeAllSoundSources()
{
	m_musicDevice->removeAllSoundSources();
}
