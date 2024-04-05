//Title: Pirate.h
//Author: Jeremy Dixon
//Date: 9/24/2020
//Description: This is part of the Pirate Project in CMSC 202 @ UMBC
// This is the non-pointer version header files

#ifndef PIRATE_H //Include/Header Guard
#define PIRATE_H //Include/Header Guard

#include "Ship.h" //Include for the ship struct
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Constants (allowed to add more as needed)
const int MAX_SHIPS = 15; //Max number of ships in game (total in file)
const int MAX_PIRATES = 352; //Max number of pirates in game (total in file)

class Pirate{
public:
    // Name: Pirate() - Default Constructor
    // Desc: Used to build a new Pirate
    // Preconditions - Requires default values
    // Postconditions - Creates a new Pirate
    Pirate();
    // Name: Pirate(name, rating, years, origin, desc) - Overloaded Constructor
    // Desc: Used to build a new Pirate
    // Preconditions - Requires new values
    // Postconditions - Creates a new Pirate
    Pirate(string name, int rating, string origin, string desc);
    // Name: GetName()
    // Desc - Getter for Pirate name
    // Preconditions - Pirate exists
    // Postconditions - Returns the name of the Pirate
    string GetName();
    // Name: GetRating()
    // Desc - Gets the Pirate's rating
    // Preconditions - Pirate exists
    // Postconditions - Returns rating of Pirate
    int GetRating();
    // Name: SetRating()
    // Desc - Sets the Pirate's rating
    // Preconditions - Pirate exists
    // Postconditions - Updates the Pirate's rating
    void SetRating(int rating);
    // Name: GetOrigin()
    // Desc - Describes the country of origin of the Pirate
    // Preconditions - Pirate exists
    // Postconditions - Returns the country of origin on the Pirate
    string GetOrigin();
    // Name: GetDesc()
    // Desc - Describes the Pirate
    // Preconditions - Pirate exists
    // Postconditions - Returns the description of the Pirate
    string GetDesc();
    // Name: SetCurShip (ship)
    // Desc - Sets the pirates' type of ship
    // Preconditions - Pirate exists
    // Postconditions - Updates m_curShip
    void SetCurShip(Ship curShip);
    // Name: CalcTreasure
    // Desc - Calculates treasure and added to m_pirateCargo
    // Calculated as enemy ship's cannon, max toughness, and speed divided by 3
    // Preconditions - Pirate exists and battle has concluded
    // Postconditions - Updates total cargo
    void CalcTreasure(Ship enemyShip);
    // Name: Battle(pirate, ship)
    // Desc - Battles user pirate vs computer's enemy pirate
    //        If user's ship has m_curToughness of 0 then must repair before battle
    //        Two outcomes possible - User pirate wins = CalcTreasure and maybe damaged ship
    //        Computer pirate wins = damaged ship and pirate's m_cargo halved
    //        User always attacks enemy pirate first
    //        Pirate rating (higher = better) is percentage liklihood of hit
    //        (rating 95 = 95% hit per cannon)
    //        When either user curToughness < 1 or enemyShip curToughness < 1 battle is over
    // Preconditions - Enemy pirate found
    // Postconditions - Either user pirate wins or enemy pirate wins
    void Battle(Pirate enemyPirate, Ship enemyShip);
    // Name: RepairShip
    // Desc - Repairs m_curShip and increases m_pirateDays by 1 per m_maxToughness - m_curToughness
    // Preconditions - Ship damaged
    // Postconditions - Repairs ship and increases days (1 day per point of damage)
    void RepairShip();
    // Name: Flee(pirate, ship)
    // Desc - User pirate tries to fleet enemy pirate.
    // If m_curShip's speed is higher than enemy then successful flee otherwise Battle occurs
    // Preconditions - Pirate tries to flee
    // Postconditions - Returns to menu or Battle occurs
    void Flee(Pirate enemyPirate, Ship enemyShip);
    // Name: DisplayScore()
    // Desc - Describes information about the Pirate
    // Preconditions - Pirate exists
    // Postconditions - Displays name, rating, origin, desc, cargo, days, cargo/days, and
    //  info about m_curShip
    void DisplayScore();
private:
    string m_pirateName; //Name of Pirate
    int m_pirateRating; //Rating of Pirate
    string m_pirateOrigin; //Country of Origin of Pirate
    string m_pirateDesc; //Description of Pirate
    int m_pirateCargo; //Tons of cargo earned
    int m_pirateDays; //Days elapsed
    Ship m_curShip; //Pirate's current ship
};

#endif //Exit Header Guard
