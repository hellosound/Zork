// Zork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Entity.h"
#include "Room.h"


int main()
{
    std::cout << "Hello ZORK!\n";


    /**/Entity* TestRoom = new Entity("TestRoom", "A room with 4 doors, the front one is bigger and mysterious", Entity::ROOM);
    Entity* Monster = new Entity("Monster", "A large monster with wings and a golden neclace", Entity::ENEMY);
    Entity* Key = new Entity("Key", "Rusty Key", Entity::ITEM);
    Entity* Bag = new Entity("Bag", "Old Bag", Entity::ITEM);

    Room* LivingRoom = new Room ("Living Room", "a small living room");


    TestRoom->AddEntity(Monster);
    TestRoom->AddEntity(Key);

    std::cout << "Room:" << TestRoom->GetName() << "-" << TestRoom->GetDescription() << std::endl;
    std::cout << "Contains" << std::endl;

    for (Entity* entity : TestRoom->GetContents())
    {
        std::cout << "-" << entity->GetName() << std::endl;
    }

    TestRoom->RemoveEntity(Monster); //First Remove the pointer
    delete Monster; //Then remove the entity

    std::cout << "Room:" << TestRoom->GetName() << "-" << TestRoom->GetDescription() << std::endl;
    std::cout << "Contains" << std::endl;


    for (Entity* entity : TestRoom->GetContents())
    {
        std::cout << "-" << entity->GetName() << std::endl;
    }

    TestRoom->AddEntity(Bag); //Add a mew Entity
    std::cout << "Room:" << TestRoom->GetName() << "-" << TestRoom->GetDescription() << std::endl;
    std::cout << "Contains" << std::endl;

    for (Entity* entity : TestRoom->GetContents())
    {
        std::cout << "-" << entity->GetName() << std::endl;
    }

    LivingRoom->Update();

    LivingRoom->AddEntity(Bag);

    LivingRoom->Update();



    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
