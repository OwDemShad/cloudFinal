//
// Created by Dorian on 01/12/2018.
//

#ifndef LASER_TERRAINMURPLEIN_H
#define LASER_TERRAINMURPLEIN_H

#include <iostream>
#include <vector>
#include "terrain.h"

class TerrainMursPleins : public Terrain
{
public:
    /**
     * Constructeur d'un terrain avec murs pleins
     */
    TerrainMursPleins(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles);    // inutile mais ça compile pas sinon

    // ----------------- Methodes redefinies -----------------



    /**
     * Indique si la case suivante est libre selon une position et une direction
     * @param pos - position actuelle
     * @param direction - 0,1,2,3 (sens horaire)
     * @return boolean - vrai si la case suivante est libre, faux sinon
     */
    virtual bool caseSuivanteEstLibre(const Position &pos, int direction) const override ;

    /**
     * Place un element sur le terrain (dans le vector en private)
     * @param element - element a placer --> 0 : rien, 1 : mur, 2 : \, 3 : /, 4 : cible
     * @param pos - position de l'element sur le terrain
     */
    virtual void placeElement(int element, const Position &pos) override ;

    // ----------------- Methodes classiques de l'objet -----------------

    /**
     * Indique si l'element a la position donnee est un mur
     * @param pos - position a tester
     * @return boolean - vrai s'il y a un mur a la position pos
     */
    virtual bool estMur(const Position &pos) const override ;

    /**
     * Indique le type de miroir a la position donnee
     * @param pos - position a tester
     * @return int - 0 : pas de miroir, 1 : \, 2 : /, 3 : \ (semi-miroir); 4 : / (semi-miroir)
     */
    virtual int typeMiroir(const Position &pos) const override ;

    /**
     * Indique si la partie est terminee
     * La parte est terminee si le laser ne peut plus bouge, ou s'il a detruit toutes les cibles
     * @return
     */
    virtual bool fin() const override ;
private:
    // tableau 2D de int car les classes elements sont inutiles
    std::vector< std::vector<int> > d_terrain;
};


#endif //LASER_TERRAINMURPLEIN_H
