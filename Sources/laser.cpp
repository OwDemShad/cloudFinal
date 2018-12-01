//
//  laser.cpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "../Headers/laser.h"


Laser::Laser(const Position &pos, int direction) : d_terrain{}, d_pos{pos}, d_direction{direction}, d_nbPoints{0}
{

}

Laser::~Laser()
{

}

void Laser::avance()
{
    if(d_terrain->caseSuivanteEstLibre(d_pos, d_direction))
    {
        changerPosition(d_direction);

        int valeur = d_terrain->typeMiroir(d_pos);

        if(valeur != 0) changerDirection(valeur);
    }
}

bool Laser::estSurCible() const
{

}

Position Laser::position() const
{
    return d_pos;
}

int Laser::direction() const {
    return d_direction;
}

int Laser::nbPoints() const {
    return d_nbPoints;
}

void Laser::changerPosition(int direction)
{
    switch(direction)
    {
        case 0 :
            d_pos = Position{d_pos.x(), d_pos.y() - 1};
            break;

        case 1 :
            d_pos = Position{d_pos.x() + 1, d_pos.y()};
            break;

        case 2 :
            d_pos = Position{d_pos.x(), d_pos.y() + 1};
            break;

        case 3 :
            d_pos = Position{d_pos.x() - 1, d_pos.y()};
            break;

        default :
            break;
    }
}

void Laser::changerDirection(int miroir)
{
    switch(miroir)
    {
        // pas de miroir
        case 0 :
            break;

        // '\' miroir normal
        case 1 :

            if(d_direction == 0) d_direction = 3 ;

            else if(d_direction == 1) d_direction = 2 ;

            else if(d_direction == 2) d_direction = 1 ;

            else if(d_direction == 3) d_direction = 0 ;

            else break;

        // '/' miroir normal
        case 2 :

            if(d_direction == 0) d_direction = 1 ;

            else if(d_direction == 1) d_direction = 0 ;

            else if(d_direction == 2) d_direction = 3 ;

            else if(d_direction == 3) d_direction = 2 ;

            else break;

        // '\' semi miroir
        case 3 :
            break;

        // '/' semi miroir
        case 4 :
            break;

        default :
            break;
    }
}
