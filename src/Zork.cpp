// Zork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Entity.h"

int main()
{
    std::cout << "Hello ZORK!\n";


    Entity* Room = new Entity("TestRoom", "A room with 4 doors, the front one is bigger and mysterious", Entity::ROOM);
    Entity* Monster = new Entity("Monster", "A large monster with wings and a golden neclace", Entity::ENEMY);

    Room->AddEntity(Monster);

    std::cout << "Room:" << Room->GetName() << "-" << Room->GetDescription() << std::endl;
    std::cout << "Contains" << std::endl;

    for (Entity* entity : Room->GetContents())
    {
        std::cout << "-" << entity->GetName() << std::endl;
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
