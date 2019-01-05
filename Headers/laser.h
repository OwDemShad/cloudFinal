//
//  laser.h
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef laser_h
#define laser_h


#include <vector>
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
     * @param [in] pos - position qui initialise le laser
     * @param [in] direction - direction dans laquelle se deplace le laser
     * @param [in] t - pointeur sur le terrain
     */
    Laser(const std::vector<Position> &pos, const std::vector<int> directions, Terrain *t);

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

    /**
     * Augmente les points du laser
     */
    void incrementePoint();

    // -------------------- Methodes de rappel --------------------

    /**
     * Retourne les positions du laser
     * @return vector<Position> - positions actuelles du laser
     */
    std::vector<Position> positions() const;

    /**
     * Retourne la position du laser a l'indice i du tableau de positions d_positions
     * @param [in] i - indice de la position a retourner
     * @return Position - position a retourner (position actuelle a l'indice i du laser)
     */
    Position position(int i) const;

    /**
     * Retourne la direction du laser :
     * 0 1 2 3 (sens horaire)
     * @param [in] i - indice
     * @return int - direction
     */
    int direction(int i) const;

    /**
     * Retourne le nombre de points que le laser a recoltes
     * @return int - le nombre de point
     */
    int nbPoints() const;

    /**
     * Retourne le terrain sur lequel le laser evolue
     * @return Terrain* - terrain du laser
     */
    Terrain* terrain() const;

    // -------------------- Methodes de changement --------------------

    /**
     * Change la position du laser selon une direction
     * @param [in]  direction - sens du laser
     * @param [in] indice - indice de la position a modifier dans le vecteur d_positions
     */
    void changerPosition(int direction, int indice);

    /**
     * Deplace le trait d'un laser d'une case vers le haut
     */
    void deplacementHaut(int indice);

    /**
     * Deplace le laser d'une case vers la droite
     */
    void deplacementDroite(int indice);

    /**
     * Deplace le laser d'une case vers le bas
     */
    void deplacementBas(int indice);

    /**
     * Deplace le laser d'une case vers la gauche
     */
    void deplacementGauche(int indice);


    /**
     * Change la direction du laser selon un miroir
     * @param [in] miroir - '/' ou '\'
     * @param [in] indice - indice de la position et de la direction a modifier dans les vecteurs d_positions et d_directions
     */
    void changerDirection(int miroir, int indice);



    /**
     * Verifie que le laser puisse acceder a la case suivante
     * @return bool - acces possible ou non a la case suivante
     */
    bool peutAvancer();

    /**
     * Le laser va detruire la cible sur laquelle il se trouve
     */
    void detruitCibles();




private:
    Terrain* d_terrain;     // terrain sur lequel evolue le laser : le laser questionne le terrain
    std::vector<Position> d_positions;         // positions courantes du laser
    std::vector<int> d_directions;             // directions du laser : 0,1,2,3 (sens horaire)
    //int d_direction;        // direction du laser : 0,1,2,3 (sens horaire)
    int d_nbPoints;         // nombre de points que le laser a recoltes
};

#endif /* laser_h */
