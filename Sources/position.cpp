//
//  position.cpp
//  PLaser
//
//  Created by Thibaud B. on 28/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "../Headers/position.h"

Position::Position (int x, int y) : d_x {x}, d_y {y}
{}

Position::Position(const Position& p) : d_x{p.d_x}, d_y{p.d_y}
{}

int Position::x() const
{
    return d_x;
}

int Position::y() const
{
    return d_y;
}

void Position::changerX(int x)
{
    d_x = x;
}

void Position::changerY(int y)
{
    d_y = y;
}

