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

    bool estMurHaut(const Position &pos) const;

    bool estMurDroit(const Position &pos) const;

    bool estMurBas(const Position &pos) const;

    bool estMurGauche(const Position &pos) const;



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
