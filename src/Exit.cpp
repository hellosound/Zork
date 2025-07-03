#include "Exit.h"
#include "Room.h"

Exit::Exit(const std::string& direction, Room* destination)
		:Entity("Exit", "An exit to the" + direction, Entity::EXIT),
		direction(direction),
		destination(destination)
{}

//---------------------------------------------------------------------------------------------------------------
const std::string& Exit::GetDirection() const
{
	return direction;
}

//---------------------------------------------------------------------------------------------------------------
Room* Exit::GetDestination() const
{
	return destination;
}



