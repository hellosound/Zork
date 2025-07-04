// Zork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"


int main()
{
    //Create Rooms
    Room* LivingRoom = new Room("Living Room", "a place full of old furniture, you wonder how many stories happened her");
    Room* Kitchen = new Room("Kitchen", "a small kitchen, looks like it hasn't been used in a long time...");
    Room* Garden = new Room("Garden", " a garden full of plants you've never seen... smells funny though.");


    //Create Exits
    Exit* nToKitchen = new Exit("NORTH", Kitchen);
    Exit* sToLivingRoom = new Exit("SOUTH", LivingRoom);
    Exit* eToGarden = new Exit("EAST", Garden);
    Exit* wToKitchen = new Exit("WEST", Kitchen);


    //Add Exits
    LivingRoom->AddEntity(nToKitchen);
    Kitchen->AddEntity(sToLivingRoom);
    Kitchen->AddEntity(eToGarden);
    Garden->AddEntity(wToKitchen);


    //Add Objects
    Entity* bag = new Entity("Bag", "A bag that looks to contain some coins", Entity::ITEM);
    Kitchen->AddEntity(bag);

    //CreatePlayer
    Player* mainPlayer = new Player("Jonathan", "A wondering young person", LivingRoom);

    //Welcome Message
    std::cout << "Welcome to Zork!\n";

    //--Game Loop--//
    std::string input;

    while (true)
    {
        std::cout << "\nEnter a direction to move (NORTH,EAST,SOUTH,WEST)";
        std::getline(std::cin, input);
    
         mainPlayer->TryToMoveToRoom(input);
    }
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
