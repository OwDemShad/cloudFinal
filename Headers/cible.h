//
//  cible.h
//  PLaser
//
//  Created by Thibaud B. on 28/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef cible_h
#define cible_h

#include "element.h"
#include "position.h"

class Cible : public Element
{
public:
    Cible (const Position& p);
    
    Position position() const;
    
private:
    Position d_pos;
};

#endif /* cible_h */
