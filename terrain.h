//
//  terrain.hpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef terrain_hpp
#define terrain_hpp

#include <vector>

class Terrain
{
public:
    Terrain (int nbColonnes, int nbLignes);
    
    
private:
    std::vector<std::vector<Case*>> d_terrain;
};

#endif /* terrain_hpp */
