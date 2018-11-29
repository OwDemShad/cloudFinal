//
//  terrain.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef terrain_h
#define terrain_h

#include <vector>
class Case;

class Terrain
{
public:
    Terrain (int nbColonnes, int nbLignes);
    
    ///Initialise le terrain avec des murs
    void init();
    
    
private:
    std::vector<std::vector<Case*>> d_terrain;
    
    //Tableau qui contient les numéros des cases qui (s)ont un mur
    std::vector<std::vector<int>> d_numCasesAvecMurs;
};

#endif /* terrain_h */
