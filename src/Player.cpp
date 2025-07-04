#include "Player.h"
#include "Exit.h"
#include <iostream>

Player:: Player(const std::string& name, const std::string& description, Room* startingRoom)
	: Entity(name, description, Entity::HUMAN), currentRoom(startingRoom) 
	{
		currentRoom->Update();
	}

//---------------------------------------------------------------------------------------------------------------
void Player::Update()
{
	//space for custom features of player later
}

//---------------------------------------------------------------------------------------------------------------
void Player::MoveToRoom(Room* room)
{
	currentRoom = room;
	currentRoom->Update();
}

//---------------------------------------------------------------------------------------------------------------
void Player::TryToMoveToRoom(const std::string& direction)
{
	bool foundExit = false;

	for (Entity* entity : currentRoom->GetContents())
	{
		if (entity->GetType() == EXIT)
		{
			Exit* exit = dynamic_cast<Exit*>(entity);
			if (exit && exit->GetDirection() == direction)
			{
				MoveToRoom(exit->GetDestination());
				foundExit = true;
				return;
			}
		}
	}
	if (!foundExit)
	{
		std::cout << "You can't go " << direction << " from here.";
	}
}