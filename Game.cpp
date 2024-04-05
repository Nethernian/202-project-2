/*********************************************************************
 * File:        Game.cpp
 * Project:     Project 2
 * Author:      Nathan Wooddell
 * Date:        10/7/2020
 * Section:     10/30
 * E-Mail:      nathanw2@umbc.edu
 *
 * This File contains the game functions and handles the main game loop.
 * This File contains Game() and it's overloaded counterpart, as well as:
 * LoadShips(), LoadPirates(), StartGame(), MainMenu(), SearchTreasure(), and
 * RequestShip().
 *
 **********************************************************************/
#include "Game.h"

    //Default constructor for the game loop
Game::Game(){
    //Step 1: Displays Game Titles
    GameTitle();
    //Step 2: Loads Ship Data
    LoadShips();
    //Step 3: Loads Pirate Data
    LoadPirates();
}

    //Loads the ships from the file
void Game::LoadShips() {
    //Loads the Ships from PROJ2_SHIPS
    string line, shipName, shipDesc;
    int cannons, toughness, speed;
    //
    ifstream shipFile;
    shipFile.open(PROJ2_SHIPS);
    //Loop to assign the
    for(int i = 0; i < MAX_SHIPS; i++){
        //Gets the name of the ship
        getline(shipFile, shipName, ',');

        //Gets the value for cannons as int
        shipFile >> cannons;

        //Handles the comma
        getline(shipFile, line, ',');

        //Gets the value of toughness as int
        shipFile >> toughness;

        //Handles the comma
        getline(shipFile, line, ',');

        //Gets the value of speed as int
        shipFile >> speed;

        //Handles the comma
        getline(shipFile, line, ',');

        //finish off the line and make cursor read for the next one
        getline(shipFile, shipDesc);

        m_ships[i] = Ship(shipName, cannons, toughness, speed, shipDesc);
    }
    cout << MAX_SHIPS << " Ships have been loaded" << endl;
}

    //Loads the pirates from the file
void Game::LoadPirates() {
    string piName, piOrigin, piDesc,line;
    int piRate;

    ifstream pirateFile;
    pirateFile.open(PROJ2_PIRATES);

    for(int i = 0; i < MAX_PIRATES; i++){
        //Gets a string for pirate name
        getline(pirateFile, piName, ',');

        //Gets the integer for
        pirateFile >> piRate;

        //Handler for the comma
        getline(pirateFile, line, ',');

        //The Pirate's Origin
        getline(pirateFile, piOrigin, ',');

        //The Pirate's Description
        getline(pirateFile, piDesc);

        m_allPirates[i] = Pirate(piName, piRate, piOrigin, piDesc);
    }
    cout << MAX_PIRATES << " pirates have been loaded" << endl;

    pirateFile.close();
}

    //Starts the game
void Game::StartGame() {
    //Game Loop Variables
    int menuChoice = 0;
    int randomPirate = rand()%MAX_PIRATES;
    int randomShip = rand()%MAX_SHIPS;

    //Creates and prints the title screen
    GameTitle();

    //Assigns a random pirate
    m_myPirate = m_allPirates[randomPirate];
    cout << "Captain: " << m_myPirate.GetName() << " is ready to set sail!" << endl;

    //Assigns a random ship
    m_myPirate.SetCurShip(m_ships[randomShip]);
    cout << m_myPirate.GetName() << " is aboard a " << m_ships[randomShip].m_type << endl;

    //The Main While loop to contain the game.
    while(menuChoice != 4){
        cout << "*********************************************************************" << endl;
        menuChoice = MainMenu();
        switch(menuChoice){
            case 1:
                //Treasure Hunt Case
                cout << "Searching for treasures!" << endl;
                SearchTreasure();
                break;
            case 2:
                //Ship repair case
                cout << "*********************************************************************" << endl;
                cout << "Repairing the Ship!" << endl;
                m_myPirate.RepairShip();
                break;
            case 3:
                //The Scoreboard Case
                cout << "Printing Score!" << endl;
                m_myPirate.DisplayScore();
                break;
            case 4:
                //The Retirement case
                m_myPirate.DisplayScore();
                cout << m_myPirate.GetName() << " sails into retirement. " << endl;
                cout << "Thank you for playing pirates!" << endl;
                break;
            default:
                // A default that kicks the user back to menu.
                menuChoice = 0;
                break;
        }
    }
}

int Game::MainMenu() {
    int choice;
    cout << "What Would you like to do:" << endl;
    cout << "1. Search for Treasure" << endl;
    cout << "2. Repair Ship" << endl;
    cout << "3. See Score" << endl;
    cout << "4. Retire" << endl;
    cin >> choice;
    return choice;
 }

void Game::SearchTreasure() {
    int sel = rand() % MAX_SHIPS, selTwo = rand() % MAX_PIRATES;
    int choice;

    cout << "*********************************************************************" << endl;
    cout << "You scan the horizon for perspective targets..." << endl;
    cout << "*********************************************************************" << endl;

    Ship enemyShip = m_ships[sel];
    Pirate hostilePirate = m_allPirates[selTwo];
    hostilePirate.SetCurShip(enemyShip);

    //The output for the flee function
    cout << "Off in the distance you spy: " << hostilePirate.GetName() << " Sailing on a " << enemyShip.m_type << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Attack " << hostilePirate.GetName() << endl;
    cout << "2. Flee from " << hostilePirate.GetName() << endl;

    cin >> choice;

    switch(choice){
        case 1:
            m_myPirate.Battle(hostilePirate, enemyShip);
            break;
        case 2:
            m_myPirate.Flee(hostilePirate, enemyShip);
            break;
        default:
            cout << "You attack " << hostilePirate.GetName();
            m_myPirate.Battle(hostilePirate, enemyShip);
            break;
    }
}

void Game::RequestShip(int &choice) {
    m_myPirate.SetCurShip(m_ships[choice]);
}