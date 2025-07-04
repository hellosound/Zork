#pragma once

#include "Entity.h"
#include "Room.h"

class Player : public Entity
{
public:
	Player(const std::string& name, const std::string& destription, Room* startingRoom);

	void MoveToRoom(Room* room);

	void TryToMoveToRoom(const std::string& direction);

	void Update() override;
	

private:
	Room* currentRoom;
	
};

