// Zork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"


int main()
{
    // ROOM MOVEMENT TEST.
  
 

    //Create Rooms
    Room* LivingRoom = new Room("Living Room", "a place full of old furniture, you wonder how many stories happened her");
    Room* Kitchen = new Room("Kitchen", "a small kitchen, looks like it hasn't been used in a long time...");


    //Create Exits
    Exit* LivingRoomNorthExit = new Exit("NORTH", Kitchen);
    LivingRoom->AddEntity(LivingRoomNorthExit);

    //Add Objects

    Entity* bag = new Entity("Bag", "A bag that looks to contain some coins", Entity::ITEM);
    Kitchen->AddEntity(bag);

 
    //CreatePlayer
    Player* mainPlayer = new Player("Jonathan", "A wondering young person", LivingRoom);

    //PLAYER MOVEMENT TEST
    mainPlayer->TryToMoveToRoom("NORTH");




    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
