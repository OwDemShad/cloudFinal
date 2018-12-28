//
// Created by Dorian on 01/12/2018.
//

#include "../Headers/affichage.h"
#include "../Headers/graphics.h"

const int DECALAGEX = 50;
const int DECALAGEY = 50;

Affichage::Affichage(int longueur, int hauteur) : d_longueur{longueur}, d_hauteur{hauteur}
{
    // ici mettre les methodes de winbgi pour pouvoir creer la fenetre
}

void Affichage::afficherTerrainMursPleins(const Terrain &terrain) const
{
    Position depart{ DECALAGEX, DECALAGEY};

    for ( int i = 0 ; i < d_hauteur ; ++i)
    {
        for ( int j = 0 ; j < d_longueur ; ++j)
        {
            traceCarre(depart);
            if ( terrain.terrain()[i][j].valeur() == MUR )
            {
                floodfill ( depart.x() + d_tailleCase/2, depart.y() + d_tailleCase/2, WHITE );
            }
            else if ( terrain.terrain()[i][j].valeur() == CIBLE )
            {
                setcolor(GREEN);
                setlinestyle(0, 1, 2);

                circle ( depart.x() + d_tailleCase/2, depart.y() + d_tailleCase/2, d_tailleCase/2 );
                circle ( depart.x() + d_tailleCase/2, depart.y() + d_tailleCase/2, d_tailleCase/4 );

                setlinestyle(0, 1, 1);
                setcolor(WHITE);
            }

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

void Affichage::update(const Terrain &t) const
{

}

void Affichage::afficherMiroirs(const Terrain &t) const
{
    for ( int i = 0 ; i < d_hauteur ; ++i)
    {
        for ( int j = 0 ; j < d_longueur ; ++j)
        {
            if ( t.terrain()[i][j].valeur() == MIROIR1 )
            {
                setcolor(GREEN);
                setlinestyle(0, 1, 2);

                Position caseHautGauche{DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase};
                Position caseBasDroit(DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase);

                line(caseHautGauche.x(), caseHautGauche.y(), caseBasDroit.x(), caseBasDroit.y());

                setlinestyle(0, 1, 1);
                setcolor(GREEN);
            }

            else if ( t.terrain()[i][j].valeur() == MIROIR2 )
            {
                setcolor(GREEN);
                setlinestyle(0, 1, 2);

                Position caseHautDroit(DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase);
                Position caseBasGauche{DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase};

                line(caseHautDroit.x(), caseHautDroit.y(), caseBasGauche.x(), caseBasGauche.y());

                setlinestyle(0, 1, 1);
                setcolor(GREEN);
            }
        }
    }
}

void Affichage::afficherLaser(const Laser &laser) const
{
    delay(100);
    setcolor(RED);
    setlinestyle(0,1,4);

    Position departLaser { DECALAGEX + laser.position().x() * d_tailleCase, DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase/2 } ;
    Position arriveeLaser ( DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase/2, DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase/2 ) ;

    line(departLaser.x(), departLaser.y(), arriveeLaser.x(), arriveeLaser.y());

    setlinestyle(0,1,1);
    setcolor(WHITE);
}
