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

}

void Laser::changerDirection(int miroir)
{

}
