//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <vector>
#include <pair>
#include "Entity.hpp"

Entity	*CollisionChecker(std::pair<int, int> position,
				std::vector<Entity *> map)
{
	for (int i = 0; i < map.size(); i++) {
		if ((position.first() == map[i]->getX())
		    && (position.second() == map[i]->getY()))
			return map[i];
	}
	return nullptr;
}
