//
//  laser.cpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "../Headers/laser.h"
#include "../Headers/terrain.h"

Laser::Laser(const Position &pos, int direction, Terrain *t) : d_terrain{t}, d_pos{pos}, d_direction{direction},d_nbPoints{0}
{
//    d_terrain = &t;
}

Laser::~Laser()
{
    delete d_terrain;
}

void Laser::incrementePoint()
{
    d_nbPoints ++;
}

bool Laser::estSurCible() const
{
     return d_terrain->estCible(d_pos);

}

Position Laser::position() const
{
    return d_pos;
}

int Laser::direction() const {
    return d_direction;
}

int Laser::nbPoints() const {
    return d_nbPoints;
}


void Laser::deplacementHaut()
{
    d_pos = Position{d_pos.x(), d_pos.y() - 1};
}

void Laser::deplacementDroite()
{
    d_pos = Position{d_pos.x() + 1, d_pos.y()};
}

void Laser::deplacementBas()
{
    d_pos = Position{d_pos.x(), d_pos.y() + 1};
}

void Laser::deplacementGauche()
{
    d_pos = Position{d_pos.x() - 1, d_pos.y()};
}

void Laser::changerPosition(int direction)
{
    switch(direction)
    {
        case 0 :
            deplacementHaut();
            break;

        case 1 :
            deplacementDroite();
            break;

        case 2 :
            deplacementBas();
            break;

        case 3 :
            deplacementGauche();
            break;

        default :
            break;
    }
}

void Laser::changerDirection(int miroir)
{
    switch(miroir)
    {
        // pas de miroir
        case 0 :
            break;
        case 1 :
            break;

        // '\' miroir normal
        case 2 :

            if(d_direction == HAUT) d_direction = GAUCHE ;

            else if(d_direction == DROITE) d_direction = BAS ;

            else if(d_direction == BAS) d_direction = DROITE ;

            else d_direction = HAUT ;

            break;

        // '/' miroir normal
        case 3 :

            if(d_direction == HAUT) d_direction = DROITE ;

            else if(d_direction == DROITE) d_direction = HAUT ;

            else if(d_direction == BAS) d_direction = GAUCHE ;

            else d_direction = BAS ;

            break;

        // '\' semi miroir
        case 4 :
            break;

        // '/' semi miroir
        case 5 :
            break;

        default :
            break;
    }
}

void Laser::avance()
{
    changerPosition(d_direction);

    if (estSurCible())
    {
        incrementePoint();
        detruitCible();
    }



    int valeur = d_terrain->typeMiroir(d_pos);

    if(valeur != LIBRE) changerDirection(valeur);
}

bool Laser::peutAvancer()
{
    return d_terrain->caseSuivanteEstLibre(d_pos, d_direction);
}

void Laser::detruitCible()
{
    d_terrain->detruitCible(d_pos);
    d_terrain->decrementeNombreDeCibles();
}




