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
     *
     */
    TerrainMursPleins();

    /**
     * Constructeur d'un terrain avec murs pleins
     */

    /**
     * Constructeur vide d'un TerrainMursPleins (pour le chargement d'un fichier)
     * @param [in] longueur - longueur du terrain
     * @param [in] hauteur - hauteur du terrain
     * @param [in] nbMiroirs - nombres de miroirs a placer
     * @param [in] nbSemiMiroirs - nombres de semi-miroirs a placer
     * @param [in] nbCibles - nombre de cible sur le terrain
     */
    TerrainMursPleins(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles);    // inutile mais ça compile pas sinon

    // ----------------- Methodes redefinies -----------------



    /**
     * Indique si la case suivante est libre selon une position et une direction
     * @param [in] pos - position actuelle
     * @param [in] direction - 0,1,2,3 (sens horaire)
     * @return boolean - vrai si la case suivante est libre, faux sinon
     */
    virtual bool caseSuivanteEstLibre(const Position &pos, int direction) const override ;

    /**
     * Place un element sur le terrain (dans le vector en private)
     * @param [in] element - element a placer --> 0 : rien, 1 : mur, 2 : \, 3 : /, 4 : cible
     * @param [in] pos - position de l'element sur le terrain
     */
    virtual void placeElement(int element, const Position &pos) override ;

    // ----------------- Methodes classiques de l'objet -----------------

    /**
     * Indique si l'element a la position donnee est un mur
     * @param [in] pos - position a tester
     * @return boolean - vrai s'il y a un mur a la position pos
     */
    bool estMur(const Position &pos) const ;


    /**
     * Indique si la partie est terminee
     * La parte est terminee si le laser ne peut plus bouge, ou s'il a detruit toutes les cibles
     * @return bool - vrai si la partie est terminee
     */
    virtual bool fin() const override ;


    /**
     * Permet de charger un terrain
     * @param [in] nomFichier - fichier a charger
     */
    virtual void charger(const std::string& nomFichier) override;

private:
    // tableau 2D de int car les classes elements sont inutiles
};


#endif //LASER_TERRAINMURPLEIN_H
