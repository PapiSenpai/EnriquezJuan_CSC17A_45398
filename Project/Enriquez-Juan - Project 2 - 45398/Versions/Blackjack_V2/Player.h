/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: MSOS
 *
 * Created on July 27, 2021, 4:15 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

/******************************************************************************
* Player Structure
******************************************************************************/
class Player{
public:
    string name;
    Card hand[20];
    int total;
};

#endif /* PLAYER_H */

