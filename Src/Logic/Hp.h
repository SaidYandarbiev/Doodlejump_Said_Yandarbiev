//
// Created by said2 on 21-7-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_HP_H
#define DOODLEJUMP_SAID_YANDARBIEV_HP_H

//Class representing hitpoints of a player or an enemy
class Hp
{
public:
        //Constructor
        explicit Hp(int Hitpoints);

        //This function is called when an enemy or the player is hit
        void Hit();

        //This function is called when the player gains health
        void GainHealth();

        //This function returns the current hitpoints of the model that it belongs to
        int GetHealth() const;

        //This function returns a boolean that tells if the model which the hp belongs to is dead or not
        bool GetDead() const;

private:
        //The current hitpoints of the model to which the hp belongs to
        int Current_Hitpoints;

        //If dead == true then the model to which the hp belongs to is dead
        bool dead = false;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_HP_H
