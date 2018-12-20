//
//  laser.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef laser_h
#define laser_h


#include "terrain.h"
#include "position.h"

const int HAUT = 0;
const int DROITE = 1;
const int BAS = 2;
const int GAUCHE = 3;



class Laser
{
public:
    /**
     * Constructeur de laser
     * @param pos - position qui initialise le laser
     */
    Laser(const Position &pos, int direction, Terrain *t);

    /**
     * Destructeur de laser : detruit le terrain
     */
    ~Laser();

    /**
     * Fait avancer le laser d'une case
     */
    void avance();

    /**
     * Indique si le laser est sur la cible
     * @return boolean - vrai si le laser est sur la cible, faux sinon
     */
    bool estSurCible() const;


    void incrementePoint();

    // -------------------- Methodes de rappel --------------------

    /**
     * Retourne la position du laser
     * @return Position
     */
    Position position() const;

    /**
     * Retourne la direction du laser :
     * 0 1 2 3 (sens horaire)
     * @return int - direction
     */
    int direction() const;

    /**
     * Retourne le nombre de points que le laser a recoltes
     * @return int
     */
    int nbPoints() const;

    // -------------------- Methodes de changement --------------------

    /**
     * Change la position du laser selon une direction
     * @param direction - sens du laser
     */
    void changerPosition(int direction);

    /**
     * Deplace le laser d'une case vers le haut
     */
    void deplacementHaut();

    /**
     * Deplace le laser d'une case vers la droite
     */
    void deplacementDroite();

    /**
     * Deplace le laser d'une case vers le bas
     */
    void deplacementBas();

    /**
     * Deplace le laser d'une case vers la gauche
     */
    void deplacementGauche();


    /**
     * Change la direction du laser selon un miroir
     * @param miroir - '/' ou '\'
     */
    void changerDirection(int miroir);



    /**
     * Verifie que le laser puisse acceder a la case suivante
     * @return bool - acces possible ou non a la case suivante
     */
    bool peutAvancer();

    /**
     * Le laser va detruire la cible sur laquelle il se trouve
     */
    void detruitCible();




private:
    Terrain* d_terrain;     // terrain sur lequel evolue le laser : le laser questionne le terrain
    Position d_pos;         // position courante du laser
    int d_direction;        // direction du laser : 0,1,2,3 (sens horaire)
    int d_nbPoints;         // nombre de points que le laser a recoltes
};

#endif /* laser_h */
