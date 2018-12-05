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
    Affichage(int longueur, int largeur);
    void afficherTerrainMursPleins(const TerrainMursPleins &terrain) const ;
    void afficherTerrainMursFins(const TerrainMursFins &terrain) const ;
    void update();
private:
    int d_longueur, d_largeur;  // taille de la fenetre
    const unsigned int d_tailleCase = 50;
};


#endif //LASER_AFFICHAGE_H
