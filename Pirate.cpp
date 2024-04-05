/*********************************************************************
 * File:        Pirate.cpp
 * Project:     Project 2
 * Author:      Nathan Wooddell
 * Date:        10/7/2020
 * Section:     10/30
 * E-Mail:      nathanw2@umbc.edu
 *
 * This file contains the Pirate class definitions for project 2
 * This file contains the following commands: Pirate(), (overloaded)Pirate,
 * GetName(), GetRating(), SetRating(), GetOrigin(), GetDesc(), SetCurShip(ship),
 * CalcTreasure(), Battle(), RepairShip(), Flee(), and DisplayScore().
 *
 **********************************************************************/

#include "Pirate.h"
        //Standard Class Constructor
Pirate::Pirate(){
    m_pirateName = "Bob";
    m_pirateRating = 100;
    m_curShip = Ship();
    m_pirateDays = 0;
    m_pirateCargo = 0;
    m_pirateDesc = "A Basic Debug Pirate";
    m_pirateOrigin = "Maui";
}

        //Overloaded Class Constructor
Pirate::Pirate(string name, int rating, string origin, string desc){
    m_pirateName = name;
    m_pirateRating = rating;
    m_pirateOrigin = origin;
    m_pirateDesc = desc;
    m_pirateCargo = 0;
    m_pirateDays = 0;
}

        //Getter for name
string Pirate::GetName(){
    return m_pirateName;
}

        //Getter for Rating
int Pirate::GetRating(){
    return m_pirateRating;
}

        //Setter for Rating
void Pirate::SetRating(int rating){
 m_pirateRating = rating;
}

        //Getter for Origin
string Pirate::GetOrigin(){
    return m_pirateOrigin;
}

        //Getter for Description
string Pirate::GetDesc(){
 return m_pirateDesc;
}

        //Setter for Ship
void Pirate::SetCurShip(Ship curShip){
    m_curShip = curShip;
}

        //Calculates post battle treasure
void Pirate::CalcTreasure(Ship enemyShip){
    int cann, maxTou, piSpeed;
    int loot;

    //Greeting to the player
    cout << "Calculating Treasure: " << endl;

    //Handles the calculation of treasure earned from a fight and saves it to loot.
    cann = enemyShip.m_cannon;
    maxTou = enemyShip.m_toughness;
    piSpeed = enemyShip.m_speed;
    loot = (cann + maxTou + piSpeed)/3;

    //Adds the treasure earned to the cargo total.
    m_pirateCargo = m_pirateCargo+loot;

    //Tells the player how much treasure they earned
    cout << "You pilfered: " << loot << " tons of cargo." << endl;
}

        //Handles Battles
void Pirate::Battle(Pirate enemyPirate, Ship enemyShip){
    int round = 1;
    int myHits = 0, theirHits = 0;

    m_pirateDays++;

    //Message to start the naval combat
    cout << "A Naval Battle begins between: " << GetName() << " and " << enemyPirate.GetName() << endl;
    cout << "*********************************************************************" << endl;

    //While loop to manage combat
    while(m_curShip.m_curToughness > 0 || enemyShip.m_curToughness > 0){
        cout << "-----] Combat Round: " << round << " [-----" << endl;

        //Players Shooting Turn
        if(m_curShip.m_curToughness > 0 && enemyShip.m_curToughness > 0){
            cout << m_pirateName << " Fires: " << m_curShip.m_cannon << " cannons!" << endl;
            for(int i = 0; i < m_curShip.m_cannon; i++){
                //Checks to see if player hits
                if(m_pirateRating >= rand()%100+1) {
                    myHits++;
                    enemyShip.m_curToughness--;
                }
            }
            cout << myHits << " Hits!" << endl;
            myHits = 0;
        } else {
            //The condition if the player is out of health.
            cout << "Combat Lost " << endl;
            //Cargo Handler
            m_pirateCargo = m_pirateCargo/2;
            //Ensures toughness isn't below zero
            m_curShip.m_curToughness = 0;
            return;
        }

        //Enemy Shooting Turn
        if(enemyShip.m_curToughness > 0 && m_curShip.m_curToughness > 0){
            //Announces Enemy Shooting Turn
            cout << enemyPirate.GetName() << " Fires: " << enemyShip.m_cannon << " cannons!" << endl;
            //Fires Every Cannon
            for(int i = 0; i < enemyShip.m_cannon; i++){
                //Checks to Determine Hits
                if(enemyPirate.GetRating() >= rand()%100+1){
                    theirHits++;
                    m_curShip.m_curToughness--;
                }
            }
            cout <<theirHits << " Hits!" << endl;
            theirHits = 0;
        } else {
            // Calculates treasure for the player if they win a battle
            cout << "Combat Won!" << endl;
            cout << "*********************************************************************" << endl;
            CalcTreasure(enemyShip);
            cout << "*********************************************************************" << endl;
            return;
        }
        round++;
        }
}

        //Increments days, and m_currToughness
void Pirate::RepairShip(){
    //Makes sure that the ship is damaged before trying to repair it
    if(m_curShip.m_curToughness < m_curShip.m_toughness){
        cout << "You Repair your ship for " << m_curShip.m_toughness-m_curShip.m_curToughness << " days." << endl;
        //Adds a day to repair one toughness
        while(m_curShip.m_curToughness < m_curShip.m_toughness){
            m_curShip.m_curToughness++;
            m_pirateDays++;
        }
    } else {
        //Uses a day when the ship cant be repaired
        cout << "You waste a day trying to repair a perfect ship." << endl;
        m_pirateDays++;
    }
}

        //Allows for users to attempt to flee from battle
void Pirate::Flee(Pirate enemyPirate, Ship enemyShip){
    m_pirateDays++;
    //Checks to see if your ship is fast enough to escape the enemy pirate.
    if(m_curShip.m_speed > enemyShip.m_speed){
        cout << "You Narrowly escape " << enemyPirate.GetName() << " on their " << enemyShip.m_type << endl;
    } else {
        //If the enemy is faster, it alerts the user and begins combat
        cout << "You are unable to escape from " << enemyPirate.GetName() << "'s " << enemyShip.m_type;
        cout <<" as it is too fast!" << endl;
        Battle(enemyPirate, enemyShip);
    }
}

        //Displays the score in terminal
void Pirate::DisplayScore(){
    //Calculates the cargo per day rate
    float cargoPerDay = (float)m_pirateCargo / (float)m_pirateDays;

    //Output block to share the score with the user
    cout << "*********************************************************************" << endl;
    cout << "Name: " << m_pirateName << endl;
    cout << "Rating: " << GetRating() << endl;
    cout << "Country of Origin: " << GetOrigin() << endl;
    cout << "Description: " << GetDesc() << endl;
    cout << "Days Sailing: " << m_pirateDays << endl;
    cout << "Cargo Captured: " << m_pirateCargo << endl;
    cout << "Cargo per Day: " << cargoPerDay << endl;
    cout << "Ship Type: " << m_curShip.m_type << endl;
    cout << "Ship Cannons: " << m_curShip.m_cannon << endl;
    cout << "Ship Current Toughness: " << m_curShip.m_curToughness << endl;
    cout << "Ship Max Toughness: " << m_curShip.m_toughness << endl;
    cout << "Ship Speed: " << m_curShip.m_speed << endl;
    cout << "*********************************************************************" << endl;
}