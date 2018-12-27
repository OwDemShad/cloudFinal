//
// Created by Dorian on 01/12/2018.
//

#ifndef LASER_AFFICHAGE_H
#define LASER_AFFICHAGE_H


#include "terrain.h"
#include "terrainMursPleins.h"
#include "terrainMursFins.h"

class Affichage
{
public:
    Affichage(int longueur, int hauteur);
    void traceCarre(const Position& positionDepart) const;
    void afficherTerrainMursPleins(const TerrainMursPleins &terrain) const ;
    void afficherTerrainMursFins(const TerrainMursFins &terrain) const ;
    void update();
private:
    int d_longueur, d_hauteur;  // tailles du plateau
    const unsigned int d_tailleCase = 50;
};


#endif //LASER_AFFICHAGE_H
