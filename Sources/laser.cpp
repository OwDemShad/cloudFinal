//
//  laser.cpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "../Headers/laser.h"
#include "../Headers/terrain.h"

Laser::Laser(const std::vector<Position> &pos, const std::vector<int> directions, Terrain *t) : d_terrain{t}, d_positions{pos}, d_directions{directions},d_nbPoints{0}
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
    for ( int i = 0 ; i < d_positions.size() ; ++i)
    {
        if ( d_terrain->estCible(d_positions[i])) return true;
    }

    return false;

}

std::vector<Position> Laser::positions() const
{
    return d_positions;
}

Position Laser::position(int i) const
{
    return d_positions[i];
}

int Laser::direction(int i) const {
    return d_directions[i];
}

int Laser::nbPoints() const {
    return d_nbPoints;
}

Terrain* Laser::terrain() const
{
    return d_terrain;
}


void Laser::deplacementHaut(int indice)
{
    d_positions[indice] = Position { d_positions[indice].x(), d_positions[indice].y() - 1 };
}

void Laser::deplacementDroite(int indice)
{
    d_positions[indice] = Position { d_positions[indice].x() + 1, d_positions[indice].y() };
}

void Laser::deplacementBas(int indice)
{
    d_positions[indice] = Position { d_positions[indice].x(), d_positions[indice].y() + 1 };
}

void Laser::deplacementGauche(int indice)
{
    d_positions[indice] = Position { d_positions[indice].x() - 1, d_positions[indice].y() };
}

void Laser::changerPosition(int direction, int indice)
{
    switch(direction)
    {
        case 0 :
            deplacementHaut(indice);
            break;

        case 1 :
            deplacementDroite(indice);
            break;

        case 2 :
            deplacementBas(indice);
            break;

        case 3 :
            deplacementGauche(indice);
            break;

        default :
            break;
    }
}

void Laser::changerDirection(int miroir, int indice)
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

            if(d_directions[indice] == HAUT) d_directions[indice] = GAUCHE ;

            else if(d_directions[indice] == DROITE) d_directions[indice] = BAS ;

            else if(d_directions[indice] == BAS) d_directions[indice] = DROITE ;

            else d_directions[indice] = HAUT ;

            break;

        // '/' miroir normal
        case 3 :

            if(d_directions[indice] == HAUT) d_directions[indice] = DROITE ;

            else if(d_directions[indice] == DROITE) d_directions[indice] = HAUT ;

            else if(d_directions[indice] == BAS) d_directions[indice] = GAUCHE ;

            else d_directions[indice] = BAS ;

            break;

        // '\' semi miroir
        case 4 :

            d_directions.push_back(d_directions[indice]) ;
            d_positions.push_back(d_positions[indice]);

            if(d_directions[indice] == HAUT) d_directions[indice] = GAUCHE ;

            else if(d_directions[indice] == DROITE) d_directions[indice] = BAS ;

            else if(d_directions[indice] == BAS) d_directions[indice] = DROITE ;

            else d_directions[indice] = HAUT ;

            break;

        // '/' semi miroir
        case 5 :

            d_directions.push_back(d_directions[indice]) ;
            d_positions.push_back(d_positions[indice]);

            if(d_directions[indice] == HAUT) d_directions[indice] = DROITE ;

            else if(d_directions[indice] == DROITE) d_directions[indice] = HAUT ;

            else if(d_directions[indice] == BAS) d_directions[indice] = GAUCHE ;

            else d_directions[indice] = BAS ;

            break;

        default :
            break;
    }
}

void Laser::avance()
{
    for ( int i = 0 ; i < d_directions.size() ; ++i )
    {

        changerPosition(d_directions[i], i);

        if (estSurCible())
        {
            incrementePoint();
            detruitCibles();
        }

        int valeur = d_terrain->typeMiroir(d_positions[i]);

        if(valeur != LIBRE) changerDirection(valeur, i);
    }




}

bool Laser::peutAvancer()
{
    for ( int i = 0 ; i < d_positions.size() ; ++i )
    {
        if ( d_terrain->caseSuivanteEstLibre(d_positions[i], d_directions[i]) ) return true;
    }
    return false;
}

void Laser::detruitCibles()
{
    for ( int i = 0 ; i < d_positions.size() ; ++i )
    {
        d_terrain->detruitCible(d_positions[i]);
        d_terrain->decrementeNombreDeCibles();
    }
}




