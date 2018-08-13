//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Entity class implementation
//

#include "Window.hpp"
#include "Entity.hpp"
#include "Bomb.hpp"

Entity::Entity()
{
	m_x = 0;
	m_y = 0;
	m_type = Entity::EMPTY;
	m_mesh_path = "";
	m_texture_path = "";
}

Brick::Brick(int x, int y, Entity::ObjectType type)
{
	m_x = x;
	m_y = y;
	m_type = type;
	m_mesh_path = "";
	m_texture_path = Window::getPath(
	    "assets/img/terrain-texture.jpg").c_str();
}

Wall::Wall(int x, int y, Entity::ObjectType type)
{
	m_x = x;
	m_y = y;
	m_type = type;
	m_mesh_path = "";
	m_texture_path = Window::getPath(
	    "assets/img/media/t351sml.jpg").c_str();
}

Empty::Empty(int x, int y, Entity::ObjectType type)
{
	m_x = x;
	m_y = y;
	m_type = type;
	m_mesh_path = "";
	m_texture_path = Window::getPath(
	    "assets/img/media/t351sml.jpg").c_str();
}

Rect::Rect(int x, int y, Entity::ObjectType type)
{
	m_x = x;
	m_y = y;
	m_type = type;
	m_mesh_path = "";
	m_texture_path = Window::getPath(
	    "assets/img/media/t351sml.jpg").c_str();
}

Entity	*fact(int x, int y, Entity::ObjectType type)
{
	switch (type) {
		case Entity::BOMB :
			return new Bomb(x, y, type);
		case Entity::WALL :
			return new Wall(x, y, type);
		case Entity::BRICK :
			return new Brick(x, y, type);
		case Entity::EMPTY :
			return new Empty(x, y, type);
		case Entity::RECT :
			return new Rect(x, y, type);
	}
}

Entity::ObjectType	Entity::getType() const
{
	return m_type;
}

int			Entity::getX() const
{
	return m_x;
}
int			Entity::getY() const
{
	return m_y;
}
void			Entity::setX(int x)
{
	m_x = x;
}
void			Entity::setY(int y)
{
	m_y = y;
}

irr::io::path		Entity::getTexturePath() const
{
	return Window::getPath(m_texture_path.c_str());
}

std::string		Entity::getMeshPath()
{
	return m_mesh_path;
}