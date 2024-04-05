//Title: Game.h
//Author: Jeremy Dixon
//Date: 9/14/2020
//Description: This is part of the Pirates Project in CMSC 202 @ UMBC

#ifndef GAME_H //Header Guard
#define GAME_H //Header Guard
#include <fstream>
#include "Ship.h"
#include "Pirate.h"

//Constants (additional constants allowed)
const string PROJ2_SHIPS= "proj2_ships.txt"; //Ship file constant
const string PROJ2_PIRATES= "proj2_pirates.txt"; //Pirate file constant

class Game{
public:
    /* Name: Game() Default Constructor
    // Desc - Builds a new game by:
    // 1. Displaying the Game Title
    // 2. Loads all ships and their information into m_ships
    // 3. Loads all pirates and their information into m_pirates
    // Preconditions - None
    // Postconditions - m_allPirates and m_ships are populated
    */
    Game(); //Default Constructor
    // Name: LoadShips
    // Desc - Loads each type of ship into m_ships from file (Do not use EOF)
    // Preconditions - Requires file with valid ship data
    // Postconditions - m_ships is populated with ship structs
    void LoadShips();
    // Name: LoadPirates
    // Desc - Loads each pirate into m_allPirates from file (Do not use EOF)
    // Preconditions - Requires file with valid pirate data
    // Postconditions - m_allPirates is populated with pirate objects
    void LoadPirates();
    // Name: StartGame()
    // Desc - Does the following:
    //        1. Randomly assigns a pirate from the list as the user's pirate (m_myPirate)
    //        2. Randomly assigns a ship to the user's pirate (updates m_myPirate's ship)
    //        3. Manages the game itself including win conditions continually
    //         calling the main menu
    // Preconditions - Player (Pirate) is placed in game
    // Postconditions - Continually checks to see if player has entered 4 (retires)
    void StartGame();
    // Name: MainMenu()
    // Desc - Displays and manages menu.
    // Preconditions - Player has a Pirate
    // Postconditions - Returns number including exit
    int MainMenu();
    // Name: SearchTreasure()
    // Desc - Attempts to search for ships and allows user to either battle or attempt to flee
    // Preconditions - Pirates loaded
    // Postconditions - Identifies enemy pirate to fight
    void SearchTreasure();
    // Name: RequestShip()
    // Desc - Requests ship for battle
    // Preconditions - Pirate has ship for battle
    // Postconditions - Returns integer of chosen ship for battle
    void RequestShip(int &choice);
    // Name: GameTitle()
    // Desc - Title for Game (Do not edit)
    // Preconditions - None
    // Postconditions - None
    void GameTitle(){
        cout << "******************************************************************" << endl;
        cout << " PPPPPP   IIIIIII  RRRRRR    AAAAA   TTTTTTT  EEEEEEE  SSSSSSS  !!" << endl;
        cout << " P     P     I     R     R  A     A     T     E        S        !!" << endl;
        cout << " P     P     I     R     R  A     A     T     E        S        !!" << endl;
        cout << " PPPPPP      I     RRRRRR   AAAAAAA     T     EEEEEEE  SSSSSSS  !!" << endl;
        cout << " P           I     RR       A     A     T     E              S  !!" << endl;
        cout << " P           I     R  R     A     A     T     E              S    " << endl;
        cout << " P        IIIIIII  R    R   A     A     T     EEEEEEE  SSSSSSS  !!" << endl;
        cout << "******************************************************************" << endl;
    }
private:
    Pirate m_allPirates[MAX_PIRATES]; //All Pirates in game (loaded from file)
    Pirate m_myPirate; //Player's Pirate for the game
    Ship m_ships[MAX_SHIPS]; //All ships in the game (loaded from file)
};

#endif //Exit Header Guard
