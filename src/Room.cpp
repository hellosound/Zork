#include "Room.h"
#include <iostream>
#include "Player.h"


Room::Room(const std::string& name, const std::string& description, const bool bShouldCheckObjects) 
    : Entity(name, description, Entity::ROOM)
{
    {
        bHasObjects = false;
        bTryToCheckObjects = bShouldCheckObjects;
    }
}

//---------------------------------------------------------------------------------------------------------------
void Room::Update()
{
	PresentRoom();
    if (bTryToCheckObjects)
    {
        CheckIfHasObjects();
        TryListRoomObjects();
    }

}

//---------------------------------------------------------------------------------------------------------------
void Room::PresentRoom() const
{
	std::cout << "You arrive to the " << GetName() << ", " << GetDescription() << std::endl;
}

//---------------------------------------------------------------------------------------------------------------
void Room::CheckIfHasObjects()
{
    //Safety reset to make sure that the loop behaves the way it should.
    bHasObjects = false;

    for (Entity* entity : GetContents())
    {
        if (entity->GetType() == Entity::ITEM)
        {
            bHasObjects = true;
            break;
        }
    }
}

//---------------------------------------------------------------------------------------------------------------
void Room::TryListRoomObjects()
{
    if (!bHasObjects)
    {
        std::cout << "There are no objects in this room." << std::endl;
        return;
    }

    std::cout << "You look around and you see this: " << std::endl;

    for (Entity* entity : GetContents())
    {
        if (entity->GetType() == Entity::ITEM)
        {
            std::cout << "- " << entity->GetName() << std::endl;
        }
    }
}
