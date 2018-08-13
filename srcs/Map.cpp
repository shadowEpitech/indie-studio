/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map for cpp_indie_studio
*/

#include <ctime>
#include <fstream>
#include "Map.hpp"
#include "Bomb.hpp"

int				Map::get_rand_value(int tail, int top)
{
	return std::rand() % (top + 1 - tail) + tail;
}

std::string			Map::put_walls(std::string line, int density)
{
	bool	finish;
	int	n;

	for (int i = 0; i != density ; i++) {
		finish = false;
		while (!finish) {
			n = Map::get_rand_value(1, (int)(line.size() - 2));
			if (line[n] == ' ') {
				line[n] = 'X';
				finish = true;
			}
		}
	}
	return line;
}

std::vector<std::string>	Map::clear_corner(
    std::vector<std::string> &map)
{
	int begin = 1;
	unsigned long	end_map = map.size() - 2;
	unsigned long	end_line = map[0].size() - 2;

	map[begin][begin] = ' ';
	map[begin][begin + 1] = ' ';
	map[begin + 1][begin] = ' ';
	map[end_map][begin] = ' ';
	map[end_map - 1][begin] = ' ';
	map[end_map][begin + 1] = ' ';
	map[end_map][end_line] = ' ';
	map[end_map - 1][end_line] = ' ';
	map[end_map][end_line - 1] = ' ';
	map[begin][end_line] = ' ';
	map[begin + 1][end_line] = ' ';
	map[begin][end_line - 1] = ' ';
	return map;
}


std::vector<std::string>	Map::fill_my_map(
    std::vector<std::string> &map, int density)
{
	std::srand((unsigned int)std::time(nullptr));

	for (int i = 1; i < map.size() - 1; i++)
		map[i] = put_walls(map[i], density);
	map = clear_corner(map);
	return map;
}

std::vector<std::string>	Map::get_map_in_file(
    const std::string &filename)
{
	std::string	line;
	std::ifstream	myfile(filename, std::ifstream::in);
	std::vector<std::string>	map;

	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, line);
			map.push_back(line);
		}
		myfile.close();
	} else
		std::cerr << "Unable to open the file" << std::endl;
	return map;
}

void	Map::print_map_entity(
    irr::scene::ISceneNode	*block,
    Window *window,
    const std::vector<Entity *> &map_in_object)
{
	for (int x = 0; x < map_in_object.size(); x++) {
		switch (map_in_object[x]->getType()) {
			case Entity::WALL:
				block->setMaterialTexture(
				    0, window->getM_driver()
					->getTexture("assets/img/wall.jpeg"));
				break;
		}
	}
}

Entity	*Map::fact(int x, int y, Entity::ObjectType type)
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

std::vector<Entity *>	Map::get_objects_from_map(
    const std::vector<std::string> &map)
{
	std::vector<Entity *>	map1;

	for(int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			if (map[i][j] == 'O') {
				map1.push_back(dynamic_cast<Bomb *>
					       (Map::fact(i, j, Entity::BOMB)));
			}
			else if (map[i][j] == '*') {
				map1.push_back(dynamic_cast<Wall *>
					       (Map::fact(i, j, Entity::WALL)));
			}
			else if (map[i][j] ==  'X') {
				map1.push_back(dynamic_cast<Brick *>
					       (Map::fact(i, j, Entity::BRICK)));
			}
			else {
				map1.push_back(
				    dynamic_cast<Empty *>
				    (Map::fact(i, j, Entity::EMPTY)));
			}
		}
	}
	return map1;
}

std::vector<Entity *>	Map::MapGenerator(int *x, int *y)
{
	std::vector<std::string>	map = Map::get_map_in_file
		(Window::getPath("assets/map/map").c_str());
	std::vector<Entity *> map_in_object;

	*x = map.size();
	*y = map[0].length();
	map = Map::fill_my_map(map, 5);
	map_in_object = Map::get_objects_from_map(map);
	return map_in_object;
}


