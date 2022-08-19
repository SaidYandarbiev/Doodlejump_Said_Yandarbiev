//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_VIEW_H

#include "Entity_view.h"

//Class representing the view of a platform
class Platform_View : public Entity_view
{
public:

        //Constructor
        Platform_View(bool breaker, bool vertical, bool horizontal, bool broken, bool notmoving, Vector2f pos);

        //Function that returns the width of a platform
        double GetWidth() override;

        //Function that returns the height of a platform
        double GetHeight() override;

        //Function that changes the position of the sprite of the platform
        void SetPosition(Vector2f pos);

        //Event handled every update
        void HandleEvent(Vector2f vector2F, float factorx, float factory) override;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_VIEW_H
