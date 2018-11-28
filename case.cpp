//
//  case.cpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "case.h"

Case::Case(const Position& p) : d_pos{p}, d_element{}
{}

/*
int Case::element() const
{
    return d_element->valeur();
}
*/

Position Case::position() const
{
    return d_pos;
}
