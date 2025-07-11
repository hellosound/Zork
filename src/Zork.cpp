// Zork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"

void StartGame(const std::string& playerName);

int main()
{
    std::cout << "Well, hello... I see that you finally made it here\n";

    std::cout << "After a long journey trying to get out of the house of horrors, you are finally on your final test\n";
    std::cout << "So... what's your name?\n";

    std::string playerName;
    std::getline(std::cin, playerName);

    std::cout << "Ah... " << playerName << ", interesting... sounds European!\n";
    std::cout << "Would you like to start your final test? Y/N\n";

    std::string answer;
    std::getline(std::cin, answer);

    if (!answer.empty() && toupper(answer[0]) == 'Y') // Accepts 'y' or 'Y'
    {
        StartGame(playerName);
    }
    else
    {
        std::cout << "Maybe another time... Farewell, " << playerName << "!\n";
    }

    return 0;
}
void StartGame(const std::string& playerName)
{
    std::string input;

    // Create Rooms
    Room* StartingRoom = new Room("Main Entrance", " you see a door to the place where your adventure will begin. You can feel a strange presence inside", false);
    Room* LivingRoom = new Room("Living Room", "a place full of old furniture, you wonder how many stories happened here... you see a strange door in front of you", true);
    Room* Kitchen = new Room("Kitchen", "a small kitchen, looks like it hasn't been used in a long time...", true);
    Room* Garden = new Room("Garden", " a garden full of plants you've never seen... smells funny though.", true);
    Room* FinalRoom = new Room("House exit", "YOU FINALLY MADE IT. Congratulations " + playerName + " You are out of the house and are free to leave.", false);

    // Create Exits
    Exit* nToLivingRoom = new Exit("NORTH", LivingRoom);
    Exit* eToGarden = new Exit("EAST", Garden);
    Exit* wToLivingRoom = new Exit("WEST", LivingRoom);
    Exit* nToFinalRoom = new Exit("NORTH", FinalRoom);
    Exit* wToKitchen = new Exit("WEST", Kitchen);
    Exit* eToLivingRoom = new Exit("EAST", LivingRoom);

    // Connect Exits to Rooms
    StartingRoom->AddEntity(nToLivingRoom);

    LivingRoom->AddEntity(wToKitchen);
    LivingRoom->AddEntity(eToGarden);

    Kitchen->AddEntity(eToLivingRoom);
    Garden->AddEntity(wToLivingRoom);

    // Add Items to rooms
    Entity* ring = new Entity("Ring", "A ring used to open the sealed door", Entity::ITEM);
    Kitchen->AddEntity(ring);

    // Create Player
    Player* mainPlayer = new Player(playerName, "A wandering young person", StartingRoom);
   
    // Lock Living Room North Exit
    bool bNorthExitUnlocked = false;


    // Game Loop -> Navigation
    while (true)
    {
        std::cout << "\nEnter a direction to move (NORTH, EAST, SOUTH, WEST) or type QUIT to exit: ";
        std::getline(std::cin, input);

        // Make input uppercase
        for (char& c : input)
        {
            c = toupper(c);
        }

        if (input == "QUIT")
        {
            std::cout << "Leaving so soon? Well... thanks for playing, " << playerName << "!\n";
            break;
        }

        mainPlayer->TryToMoveToRoom(input);

        if (!bNorthExitUnlocked && mainPlayer->HasItem("Ring"))
        {
            LivingRoom->AddEntity(nToFinalRoom);
            bNorthExitUnlocked = true;
            std::cout << "\nThe ring is glowing... you hear a creaking sound coming from Living Room... like a door opening!\n";
        }

        if (mainPlayer->GetCurrentRoom() == FinalRoom)
        {
            std::cout << "Thank you for playing!\n";
            std::cout << "\nPress Enter to exit the game...";
            std::cin.get();

            break;
        }
    }
}