#pragma once
#include "Entity.h"

class Room : public Entity
{
public:

    Room(const std::string& name, const std::string& description, const bool bShouldCheckObjects);

    void Update() override;

    void PresentRoom() const;

    void CheckIfHasObjects();

    void TryListRoomObjects();
    bool GetbHasObjects() { return bHasObjects; }

private:

    bool bHasObjects = false;
    bool bTryToCheckObjects = false;

};