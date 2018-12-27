//
// Created by Dorian on 01/12/2018.
//

#include "../Headers/affichage.h"
#include "../Headers/graphics.h"

Affichage::Affichage(int longueur, int hauteur) : d_longueur{longueur}, d_hauteur{hauteur}
{
    // ici mettre les methodes de winbgi pour pouvoir creer la fenetre
}

void Affichage::afficherTerrainMursPleins(const TerrainMursPleins &terrain) const
{
    Position depart{50,50};
    for ( int i = 0 ; i < d_hauteur ; ++i)
    {
        for ( int j = 0 ; j < d_longueur ; ++j)
        {
            traceCarre(depart);
            depart.changerX ( depart.x() + d_tailleCase );
        }

        depart.changerX(50);
        depart.changerY( depart.y() + d_tailleCase );
    }
}

void Affichage::traceCarre(const Position& depart) const
{
    line(depart.x(), depart.y(), depart.x() + d_tailleCase, depart.y());
    line(depart.x() + d_tailleCase, depart.y(), depart.x() + d_tailleCase, depart.y() + d_tailleCase);
    line(depart.x() + d_tailleCase, depart.y() + d_tailleCase, depart.x(), depart.y() + d_tailleCase);
    line(depart.x(), depart.y() + d_tailleCase, depart.x(), depart.y());
}

void Affichage::afficherTerrainMursFins(const TerrainMursFins &terrain) const
{

}

void Affichage::update()
{

}
