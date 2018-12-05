//
// Created by Dorian on 01/12/2018.
//

#ifndef LASER_TERRAINMURSFINS_H
#define LASER_TERRAINMURSFINS_H

#include <vector>
#include "terrain.h"
#include "case.h"

class TerrainMursFins : public Terrain
{
public:
    TerrainMursFins(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles);
private:
    std::vector< std::vector<Case*> > d_terrain;
};


#endif //LASER_TERRAINMURSFINS_H
