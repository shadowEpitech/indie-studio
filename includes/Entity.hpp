//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Entity class definition
//

#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <iostream>
#include <vector>
#include <string>
#include <irr/IReadFile.h>

class Entity
{
	public:
		enum ObjectType {
			BOMB,
			BRICK,
			EMPTY,
			WALL,
			RECT
		};
		Entity();
		virtual ~Entity() = default;
		virtual Entity::ObjectType	getType() const;
		int			getX() const;
		int			getY() const;
		void			setX(int x);
		void			setY(int y);
		irr::io::path		getTexturePath() const;
		std::string		getMeshPath();
	protected:
		int			m_x;
		int			m_y;
		Entity::ObjectType	m_type;
		std::string		m_mesh_path;
		irr::io::path		m_texture_path;
};

class Rect: public Entity
{
	public:
		Rect(int x, int y, Entity::ObjectType type);
	private:
		Entity::ObjectType	m_type;
		int			m_x;
		int			m_y;
		std::string		m_mesh_path;
		irr::io::path		m_texture_path;
};

class Brick: public Entity
{
	public:
		Brick(int x, int y, Entity::ObjectType type);
//		void	break()
	private:
		Entity::ObjectType	m_type;
		int			m_x;
		int			m_y;
		std::string		m_mesh_path;
		irr::io::path		m_texture_path;

};

class Wall: public Entity
{
	public:
		Wall(int x, int y, Entity::ObjectType type);
	private:
		int			m_x;
		int			m_y;
		Entity::ObjectType	m_type;
		std::string		m_mesh_path;
		irr::io::path		m_texture_path;

};

class Empty: public Entity {
	public:
		Empty(int x, int y, Entity::ObjectType _type);
	private:
		Entity::ObjectType	m_type;
		int			m_x;
		int			m_y;
		std::string		m_mesh_path;
		irr::io::path		m_texture_path;
};

#endif /* ENTITY_HPP */
