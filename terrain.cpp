//
//  terrain.cpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "terrain.h"
#include "case.h"
#include <cstdlib>


Terrain::Terrain (int nbColonnes, int nbLignes) : d_terrain {static_cast<size_t>(nbLignes), std::vector<Case*>(nbColonnes)}
{
    for (int i = 0 ; i < nbLignes ; ++i)
    {
        for (int j = 0 ; j < nbColonnes ; ++j)
        {
            d_terrain[i][j] = new Case(Position {i, j});
        }
    }
}


void Terrain::init()
{
    for (int i = 0 ; i < d_terrain.size() ; ++i)
    {
        for (int j = 0 ; j < d_terrain[i].size() ; ++j)
        {
            //Tire un chiffre aléatoire entre 0 et 3
            int alea = rand() % 4;
            
            if (alea == 1)
            {
                //d_terrain[i][j] = ;
            }
        }
    }
 
    
    
}
