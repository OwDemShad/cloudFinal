//
//  case.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef case_h
#define case_h

#include "position.h"

class Element;

class Case
{
    //friend class Terrain;
    
public:
    Case(const Position& p);
    int element() const;
    Position position() const;
    
private:
    Position d_pos;
    Element* d_element;
};


#endif /* case_h */
