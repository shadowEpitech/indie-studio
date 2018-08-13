/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map for cpp_indie_studio
*/

#ifndef _Map_H_
#define _Map_H_

#include <irr/irrlicht.h>
#include "Window.hpp"
#include "Entity.hpp"

class Map
{
public:
	Map() = default;
	~Map() = default;
	static Entity			*fact(
		int x, int y, Entity::ObjectType type);
	static std::vector<Entity *>	get_objects_from_map(
		const std::vector<std::string> &map);
       	static std::vector<Entity *>			MapGenerator(int *x, int *y);
	static std::vector<std::string>	get_map_in_file(
		const std::string &filename);
	static std::vector<std::string>	fill_my_map(
		std::vector<std::string> &map, int density);
	static std::string	put_walls(
		std::string line, int density);
	static void	print_map_entity(
		irr::scene::ISceneNode	*block,
		Window *window,
		const std::vector<Entity *> &map_in_object);
//	void getMapImg(long x, long y, const char *img) const;
//	int	get_rand_value(int tail, int top);
//	std::vector<std::string>	clear_corner(
//		std::vector<std::string> &map);
	
private:
	 static int	get_rand_value(int tail, int top);
        static std::vector<std::string> clear_corner(
		std::vector<std::string> &map);
	//Window	*m_window;
};

#endif /* _Map_H_ */
