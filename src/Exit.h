#pragma once
#include "Entity.h"
#include "Room.h"
class Exit : public Entity
{
public:
    Exit(const std::string& direction, Room* destination);

    const std::string& GetDirection() const;
    Room* GetDestination() const;

private:
    std::string direction;
    Room* destination;
};

