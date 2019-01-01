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
            if ( terrain.terrain()[i][j]->valeur() == MUR )
            {
                floodfill ( depart.x() + d_tailleCase/2, depart.y() + d_tailleCase/2, WHITE );
            }
            else if ( terrain.terrain()[i][j]->valeur() == CIBLE )
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

void Affichage::afficherMiroir(const Position &depart, const Position &arrivee) const
{
    setcolor(GREEN);
    setlinestyle(0, 1, 2);

    line(depart.x(), depart.y(), arrivee.x(), arrivee.y());

    setlinestyle(0, 1, 1);
    setcolor(GREEN);
}

void Affichage::afficherMiroirs(const Terrain &t) const
{
    for ( int i = 0 ; i < d_hauteur ; ++i)
    {
        for ( int j = 0 ; j < d_longueur ; ++j)
        {
            if ( t.terrain()[i][j]->valeur() == MIROIR1 )
            {

                afficherMiroir ( Position { DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase },
                                Position { DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase } ) ;
            }

            else if ( t.terrain()[i][j]->valeur() == MIROIR2 )
            {

                afficherMiroir ( Position { DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase },
                                Position { DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase } ) ;
            }
        }
    }
}

void Affichage::afficherLaserUnDemiTrait(const Position &depart, const Position &arrivee) const
{
    delay(50);
    setcolor(RED);
    setlinestyle(0,1,6);

    line(depart.x(), depart.y(), arrivee.x(), arrivee.y());

    setlinestyle(0,1,1);
    setcolor(RED);
}

void Affichage::afficherLaserUnDemiTraitSensNord(const Position &depart, const Position &arrivee) const
{
    afficherLaserUnDemiTrait(depart, arrivee);
}

void Affichage::afficherLaserUnDemiTraitSensEst(const Position &depart, const Position &arrivee) const
{
    afficherLaserUnDemiTrait(depart, arrivee);
}

void Affichage::afficherLaserUnDemiTraitSensSud(const Position &depart, const Position &arrivee) const
{
    afficherLaserUnDemiTrait(depart, arrivee);
}

void Affichage::afficherLaserUnDemiTraitSensOuest(const Position &depart, const Position &arrivee) const
{
    afficherLaserUnDemiTrait(depart, arrivee);
}

void Affichage::afficherLaserPremierDemiTrait(const Laser &laser) const
{
    switch ( laser.direction() )
    {
        case 0 :
            afficherLaserUnDemiTraitSensNord ( Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                          DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2},
                                               Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                          DECALAGEY + laser.position().y() * d_tailleCase} ) ;
            break;

        case 1 :
            afficherLaserUnDemiTraitSensEst ( Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                         DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2},
                                              Position { DECALAGEX + ( laser.position().x() + 1 ) * d_tailleCase,
                                                         DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2} ) ;
            break;

        case 2 :
            afficherLaserUnDemiTraitSensSud ( Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                        DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2 },
                                             Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                        DECALAGEY + ( laser.position().y() + 1 ) * d_tailleCase } ) ;
            break;

        case 3 :
            afficherLaserUnDemiTraitSensOuest ( Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                           DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2},
                                                Position { DECALAGEX + laser.position().x() * d_tailleCase,
                                                           DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2} ) ;
            break;

        default :
            break;
    }
}

void Affichage::afficherLaserDeuxiemeDemiTrait(const Laser &laser) const
{

    switch ( laser.direction() )
    {
        case 0 :
            afficherLaserUnDemiTraitSensNord ( Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                          DECALAGEY + laser.position().y() * d_tailleCase},
                                               Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                          DECALAGEY + laser.position().y() * d_tailleCase - d_tailleCase / 2} ) ;
            break;

        case 1 :
            afficherLaserUnDemiTraitSensEst ( Position { DECALAGEX + ( laser.position().x() + 1 ) * d_tailleCase,
                                                         DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2},
                                              Position { DECALAGEX + ( laser.position().x() + 1 ) * d_tailleCase + d_tailleCase / 2,
                                                         DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2} ) ;
            break;

        case 2 :
            afficherLaserUnDemiTraitSensSud ( Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                         DECALAGEY + ( laser.position().y() + 1 ) * d_tailleCase},
                                              Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                                         DECALAGEY + ( laser.position().y() + 1 ) * d_tailleCase + d_tailleCase / 2} ) ;
            break;

        case 3 :
            afficherLaserUnDemiTraitSensOuest ( Position { DECALAGEX + laser.position().x() * d_tailleCase,
                                                           DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2},
                                                Position { DECALAGEX + laser.position().x() * d_tailleCase - d_tailleCase / 2,
                                                           DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2} ) ;
            break;

        default :
            break;
    }
}

void Affichage::afficherLaserPremierTraitGrille(const Laser &laser) const
{
    afficherLaserUnDemiTrait ( Position { DECALAGEX + laser.position().x() * d_tailleCase - d_tailleCase / 4,
                                          DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2 },
                               Position { DECALAGEX + laser.position().x() * d_tailleCase,
                                          DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2 } ) ;

    afficherLaserUnDemiTrait ( Position { DECALAGEX + laser.position().x() * d_tailleCase,
                                          DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2 },
                               Position { DECALAGEX + laser.position().x() * d_tailleCase + d_tailleCase / 2,
                                          DECALAGEY + laser.position().y() * d_tailleCase + d_tailleCase / 2 }) ;
}


