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
	TryToPickupItems();
}

//---------------------------------------------------------------------------------------------------------------
void Player::MoveToRoom(Room* room)
{
	currentRoom = room;
	currentRoom->Update();
	Update();
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

//---------------------------------------------------------------------------------------------------------------
void Player::TryToPickupItems()
{
	std::string input;
	if (currentRoom->GetbHasObjects())
	{
		std::cout << "Would you like to pickup the items? Y/N\n";
		std::getline(std::cin, input);
		if (input == "Y" || input == "y")
		{
			PickUpItems();
		}

		else if (input == "N" || input == "n")
		{
			std::cout << "You decided to leave the items behind.\n";
			return;
		}
		else
		{
			std::cout << "I don't understand... remember, if you want to pick them up press 'Y', or else you can just press 'N'.\n";
			TryToPickupItems();
		}
	}
}

//---------------------------------------------------------------------------------------------------------------

void Player::PickUpItems()
{
	std::list<Entity*> itemsToPick;

	for (Entity* entity : currentRoom->GetContents())
	{
		if (entity->GetType() == Entity::ITEM)
		{
			itemsToPick.push_back(entity);
		}
	}

	if (itemsToPick.empty())
	{
		std::cout << "There are no items to pick!\n";
		return;
	}

	for (Entity* item : itemsToPick)
	{
		inventory.push_back(item);
		currentRoom->RemoveEntity(item);
		std::cout << "Picked up " << item->GetName() << std::endl;
	}
		
}

//---------------------------------------------------------------------------------------------------------------

bool Player::HasItem(const std::string& itemName)
{
	for (Entity* item : inventory)
	{
		if (item->GetName() == itemName)
			return true;
	}
	return false;
}
//---------------------------------------------------------------------------------------------------------------
Room* Player::GetCurrentRoom() const
{
	return currentRoom;
}

