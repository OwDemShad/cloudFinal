//
//  terrain.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef terrain_h
#define terrain_h

#include <iostream>
#include <vector>
#include "position.h"
#include "element.h"

class Terrain
{
public:

    Terrain();

    /**
     * Constructeur de terrain : cree un terrain vide (classe abstraite)
     * @param longueur - longueur du terrain
     * @param hauteur - hauteur du terrain
     * @param nbMiroirs - nombre de miroirs sur le terrain
     * @param nbSemiMiroirs - nombre de semi miroirs sur le terrain
     * @param nbCibles - nombre de cibles sur le terrain
     */
    Terrain(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles);

    /**
     * Destructeur virtuel
     */
    virtual ~Terrain();

    /**
     * Initialise un terrain depuis un fichier ou est enregistre la configuration du terrain
     * @param ifst - fichier à charger
     */
    //virtual void charger(const std::string &nomFichier);

    /**
     * Retourne par reference la donnee privee d_terrain
     * @return std::vector<std::vector<Element>>&
     */
    std::vector<std::vector<Element>>& terrain();

    /**
     * Indique si la case suivante est libre selon une position et une direction
     * La case est libre s'il n'y a pas de mur
     * @param pos
     * @param direction
     * @return boolean - vrai si la case est libre, faux sinon
     */
    virtual bool caseSuivanteEstLibre(const Position &pos, int direction) const = 0;

    /**
     * Positionne un element sur le terrain a une position
     * @param element - element a placer --> 0 : rien, 1 : mur, 2 : \, 3 : /, 4 : cible
     * @param pos - position de l'element sur le terrain
     */
    virtual void placeElement(int element, const Position &pos);

    /**
     * Indique s'il y a un mur a la position donnee
     * @param pos[in] - position a tester
     * @return boolean - vrai s'il y a un mur, faux sinon
     */
    virtual bool estMur(const Position &pos) const = 0;

    virtual bool estCible(const Position &pos) const = 0;

    /**
     * Indique le type de miroir a la position donnee
     * @param pos - position a tester
     * @return int - 0 : pas de miroir, 1 : \, 2 : /, 3 : \ (semi-miroir); 4 : / (semi-miroir)
     */
    virtual int typeMiroir(const Position &pos) const = 0;

    /**
     * Indique si le jeu est termine
     * Le jeu est termine si le laser ne peut plus avancer, ou s'il a touche toutes les cibles
     * @return boolean - vrai si le jeu est termine
     */
    virtual bool fin() const = 0;

    /**
     * Decremente le nombre de cibles du terrain
     */
    void decrementeNombreDeCibles();

    virtual void charger(const std::string& nomFichier) = 0;



    bool positionLibre(Position &pos) const;

    bool positionValide(Position &pos) const;

    Position saisirPositionMiroir();

    int saisieTypeTypeMiroir(bool miroirSimple);


    void placerMiroirs() ;



    // METHODES DE RAPPEL
    int longueur() const;

    int hauteur() const;

    int nbMiroirs() const;

    int nbSemiMiroirs() const;

    int nbCibles() const;

    // TESTS
    void print(std::ostream &ost) const;





    void longueur(int longueur) ;

    void hauteur(int hauteur) ;

    void nbMiroirs(int nbMiroirs) ;

    void nbSemiMiroirs(int nbSemiMiroirs) ;

    void nbCibles(int nbCibles) ;

protected:
    int d_longueur, d_hauteur;
    int d_nbMiroirs;
    int d_nbSemiMiroirs;
    int d_nbCibles;
    std::vector<std::vector<Element>> d_terrain;
};

#endif /* terrain_h */
