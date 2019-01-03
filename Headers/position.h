//
//  position.h
//  PLaser
//
//  Created by Thibaud B. on 28/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#ifndef position_h
#define position_h

//Coordonnées des cases du terrain
class Position
{
public:

    /**
     * constructeur de la position
     * @param [in] x - l'abscisse de la position
     * @param [in] y - l'ordonne de la position
     */
    Position (int x, int y);

    /**
     * Constructeur par recopie
     * @param [in] p - la position a recopier
     */
    Position (const Position& p);

    /**
     * retourne la coordonnee x
     * @return int - l'abscisse
     */
    int x() const;

    /**
     * retourne la coordonnee y
     * @return int - l'ordonnee
     */
    int y() const;

    /**
     * modifie l'abscisse de la position
     * @param [in] x - la nouvelle abscisse
     */
    void changerX(int x);

    /**
     * modifie l'ordonnee de la position
     * @param [in] x - la nouvelle ordonnee
     */
    void changerY(int y);
    
private:
    int d_x, d_y;
};

#endif /* position_h */
