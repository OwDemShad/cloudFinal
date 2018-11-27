//
//  terrain.hpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef terrain_h
#define terrain_h

#include <vector>
#include "case.h"

class Terrain
{
public:
    Terrain (int nbColonnes, int nbLignes);
    
    
private:
    std::vector<std::vector<Case*>> d_terrain;
};

#endif /* terrain_h */
