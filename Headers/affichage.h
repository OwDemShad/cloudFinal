//
// Created by Dorian on 01/12/2018.
//

#ifndef LASER_AFFICHAGE_H
#define LASER_AFFICHAGE_H


#include "terrain.h"
#include "terrainMursPleins.h"
#include "terrainMursFins.h"
#include "laser.h"

class Affichage
{
public:
    Affichage(int longueur, int hauteur);
    void traceCarre(const Position& positionDepart) const;
    void afficherTerrainMursPleins(const Terrain &terrain) const ;
    void afficherTerrainMursFins(const TerrainMursFins &terrain) const ;
    void update(const Terrain &terrain) const;
    void afficherMiroir(const Position &depart, const Position &arrivee) const;
    void afficherMiroirs(const Terrain &terrain) const;
    void afficherLaserUnDemiTrait(const Position &depart, const Position &arrivee) const;
    void afficherLaserUnDemiTraitSensNord(const Position &depart, const Position &arrivee) const;
    void afficherLaserUnDemiTraitSensEst(const Position &depart, const Position &arrivee) const;
    void afficherLaserUnDemiTraitSensSud(const Position &depart, const Position &arrivee) const;
    void afficherLaserUnDemiTraitSensOuest(const Position &depart, const Position &arrivee) const;
    void afficherLaserPremierDemiTrait(const Laser &laser) const;
    void afficherLaserDeuxiemeDemiTrait(const Laser &laser) const;
    void afficherLaserPremierTraitGrille(const Laser &laser) const;
private:
    int d_longueur, d_hauteur;  // tailles du plateau
    const int d_tailleCase = 50;
};


#endif //LASER_AFFICHAGE_H
