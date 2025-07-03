#pragma once
#include "Entity.h"

class Room : public Entity
{
public:

    Room(const std::string& name, const std::string& description);

    void Update() override;

    void PresentRoom() const;

    void CheckIfHasObjects();

    //For when we have to add or remove objects from the room
    //void UpdateRoomObjects();

    void TryListRoomObjects();

private:

    bool bHasObjects = false;

};