//
// Created by said2 on 21-7-2022.
//

#include "Hp.h"
Hp::Hp(int Hitpoints) {
        Current_Hitpoints = Hitpoints;
}

void Hp::Hit()
{
        if(Current_Hitpoints != 0){
                Current_Hitpoints -= 1;
        }

        if(Current_Hitpoints == 0){
                dead = true;
        }
}

void Hp::GainHealth()
{
        if (Current_Hitpoints != 3){
                Current_Hitpoints += 1;
        }
}

int Hp::GetHealth() const { return Current_Hitpoints; }

bool Hp::GetDead() const { return dead;}
