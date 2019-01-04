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

void Affichage::traceCible(const Position &pos, int radiusDivizer) const
{
    circle( pos.x() + d_tailleCase/2, pos.y() + d_tailleCase/2, d_tailleCase/radiusDivizer );
    circle( pos.x() + d_tailleCase/2, pos.y() + d_tailleCase/2, d_tailleCase/radiusDivizer/2 );
}

void Affichage::changerCouleurTrait(int coulour) const
{
    setcolor(coulour);
}

void Affichage::changerEpaisseurTrait(int epaisseur) const
{
    setlinestyle(0,1,epaisseur);
}

void Affichage::afficherTerrainMursPleins(const Terrain &terrain) const
{
    Position depart{ DECALAGEX, DECALAGEY };

    for ( int i = 0 ; i < d_hauteur ; ++i )
    {
        for ( int j = 0 ; j < d_longueur ; ++j )
        {
            traceCarre(depart);

            if ( terrain.terrain()[i][j].valeur() == MUR )
            {
                floodfill ( depart.x() + d_tailleCase/2, depart.y() + d_tailleCase/2, WHITE );
            }
            else if ( terrain.terrain()[i][j].valeur() == CIBLE )
            {
                changerCouleurTrait(GREEN);
                changerEpaisseurTrait(2);

                traceCible ( depart, 2 );

                changerEpaisseurTrait(1);
                changerCouleurTrait(WHITE);
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

void Affichage::afficherTerrainMursFins(const Terrain &terrain) const
{
    Position depart { DECALAGEX, DECALAGEY };

    for ( int i = 0 ; i < d_hauteur ; ++i )
    {
        for ( int j = 0 ; j < d_longueur ; ++j )
        {
            traceCarre(depart);

            // tests pour verifier si un des cotes de la cases est un mur
            if ( terrain.terrain()[i][j].estMurHaut() )
            {
                changerEpaisseurTrait(5);

                line ( DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase,
                        DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase ) ;

                changerEpaisseurTrait(1);
            }

            if ( terrain.terrain()[i][j].estMurDroit() )
            {
                changerEpaisseurTrait(5);

                line ( DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase,
                        DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase ) ;

                changerEpaisseurTrait(1);
            }

            if ( terrain.terrain()[i][j].estMurBas() )
            {
                changerEpaisseurTrait(5);

                line ( DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase,
                        DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase ) ;

                changerEpaisseurTrait(1);
            }

            if ( terrain.terrain()[i][j].estMurGauche() )
            {
                changerEpaisseurTrait(5);

                line ( DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase,
                        DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase ) ;

                changerEpaisseurTrait(1);
            }


            // tests pour verifier si la cible est presente dans la case [i][j]
            if ( terrain.terrain()[i][j].valeur() == CIBLE )
            {
                changerCouleurTrait(GREEN);
                changerEpaisseurTrait(2);

                traceCible ( depart,2 ) ;

                changerEpaisseurTrait(1);
                changerCouleurTrait(WHITE);
            }

            depart.changerX ( depart.x() + d_tailleCase ) ;

        }

        depart.changerX(50);
        depart.changerY ( depart.y() + d_tailleCase ) ;
    }
}

//void Affichage::update(const Terrain &t) const
//{
//
//}

void Affichage::afficherMiroir(const Position &depart, const Position &arrivee) const
{
    changerCouleurTrait(GREEN);
    changerEpaisseurTrait(3);

    line(depart.x(), depart.y(), arrivee.x(), arrivee.y());

    changerEpaisseurTrait(1);
    changerCouleurTrait(WHITE);
}

void Affichage::afficherMiroirs(const Terrain &t) const
{
    for ( int i = 0 ; i < d_hauteur ; ++i)
    {
        for ( int j = 0 ; j < d_longueur ; ++j)
        {
            if ( t.terrain()[i][j].valeur() == MIROIR1 )
            {

                afficherMiroir ( Position { DECALAGEX + j * d_tailleCase, DECALAGEY + i * d_tailleCase },
                                Position { DECALAGEX + j * d_tailleCase + d_tailleCase, DECALAGEY + i * d_tailleCase + d_tailleCase } ) ;
            }

            else if ( t.terrain()[i][j].valeur() == MIROIR2 )
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
    changerCouleurTrait(RED);
    changerEpaisseurTrait(6);

    line(depart.x(), depart.y(), arrivee.x(), arrivee.y());

    changerEpaisseurTrait(1);
    changerCouleurTrait(WHITE);
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


