//
// Created by said2 on 17-11-2021.
//

#include "Score.h"
void Score::HandleEvent(float height) {
        score = height;
}

float Score::GetScore() const {return score;}
