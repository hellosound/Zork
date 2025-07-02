#include "Room.h"
#include <iostream>

Room::Room(const std::string& name, const std::string& description)
	: Entity(name, description, Entity::ROOM)
{
}

void Room::Update()
{
	std::cout << "You are in room" << GetName() << std::endl;
}
