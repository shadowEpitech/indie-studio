//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Entity class definition
//

#ifndef BOMB_HPP
# define BOMB_HPP

#include <ctime>
#include "Window.hpp"
#include "Entity.hpp"

class	Bomb: public Entity
{
	public:
		Bomb(int x, int y, Entity::ObjectType type);
//		void	explode()
		irr::scene::IAnimatedMeshSceneNode	*createBomb(
		    irr::scene::IAnimatedMeshSceneNode *character2,
		    Window *window);
		bool	checkDelete(Window *window);
		bool	exist();

	private:
		Entity::ObjectType	m_type;
		int			m_x;
		int			m_y;
		std::string		m_mesh_path;
		irr::io::path		m_texture_path;
		time_t 			m_time;
		irr::scene::IAnimatedMeshSceneNode	*m_bomb;

};

#endif /* BOMB_HPP */
