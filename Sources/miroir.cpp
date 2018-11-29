//
//  miroir.cpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "../Headers/miroir.h"

Miroir::Miroir(const Position& p) : d_pos{p}
{}

Position Miroir::position() const
{
    return d_pos;
}

int Miroir::valeur() const
{
    return D_VALEUR;
}

bool Miroir::orientationMiroir() const
{
    return d_orientationMiroir;
}
