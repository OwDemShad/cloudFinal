//
//  miroir.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef miroir_h
#define miroir_h

#include "element.h"
#include "position.h"

class Miroir : public Element
{
public:
    Miroir(const Position& p);
    
    Position position() const;
    
    //Redéfinition de la valeur d'un élément
    virtual int valeur() const override;
    bool orientationMiroir() const;
    
private:
    Position d_pos;
    bool d_orientationMiroir; // \0  /1
    const int D_VALEUR = 2;
};

#endif /* miroir_h */
