#pragma once

#include "Entity.h"
#include "Room.h"

class Player : public Entity
{
public:
	Player(const std::string& name, const std::string& destription, Room* startingRoom);

	void MoveToRoom(Room* room);

	void TryToMoveToRoom(const std::string& direction);

	void TryToPickupItems();

	void PickUpItems();

	bool HasItem(const std::string& itemName);

	Room* GetCurrentRoom() const;

	void Update() override;
	

private:
	Room* currentRoom;
	std::list<Entity*> inventory;
	bool bHasItem = false;
};

