//
//  cible.cpp
//  PLaser
//
//  Created by Thibaud B. on 28/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "../Headers/cible.h"

Cible::Cible (const Position& p) : d_pos{p}
{}

Position Cible::position() const
{
    return d_pos;
}
