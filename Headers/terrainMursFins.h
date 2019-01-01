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
    TerrainMursFins();
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
     * Permet de savoir si une cible ce trouve a la position donnee
     * @param [in] pos - position a verifier
     * @return bool - vrai si il y a une cible
     */
    virtual bool estCible(const Position &pos) const override ;

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


    /**
     * Permet de charger un terrain
     * @param [in} nomFichier - fichier a charger
     */
    virtual void charger(const std::string& nomFichier) override;
private:
};


#endif //LASER_TERRAINMURSFINS_H
