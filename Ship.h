//Title: Ship.h
//Author: Jeremy Dixon
//Date: 9/24/2020
//Description: This is part of the Pirates project in CMSC 202 @ UMBC

#ifndef SHIP_H //Include/Header Guard
#define SHIP_H //Include/Header Guard

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// Name: Ship struct
// Desc - Used to store data about ships
struct Ship{
    string m_type; //Type of Ship
    int m_cannon; //Cannons on Ship
    int m_toughness; //Max Toughness of ship
    int m_curToughness; //Current toughness of ship (can't exceed max)
    int m_speed; //Speed of Ship
    string m_desc; //Description of ship
    Ship(){
        m_type = "boat";
        m_cannon = 1;
        m_toughness = 1;
        m_curToughness = 1;
        m_speed = 1;
        m_desc = "Basic Debug Boat";
    } //Default constructor
    Ship (string type, int cannon, int toughness, int speed, string desc){ //Overloaded Constructor
        m_type = type; //Type of ship
        m_cannon = cannon; //Cannons on ship
        m_toughness = toughness; //Max Toughness of ship
        m_curToughness = toughness; //Current Toughness of ship (changes during battle)
        m_speed = speed; //Speed of ship
        m_desc = desc; //Description of ship
    }
};

#endif
