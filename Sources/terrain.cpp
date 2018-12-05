//
//  terrain.cpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include <fstream>
#include "../Headers/terrain.h"

#include "../Headers/case.h"




Terrain::Terrain(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles) :
    d_longueur{longueur}, d_hauteur{hauteur}, d_nbMiroirs{nbMiroirs}, d_nbSemiMiroirs{nbSemiMiroirs}, d_nbCibles{nbCibles},
    d_terrain{}
{

}


Terrain::~Terrain() {

}

void Terrain::charger(const std::string &nomFichier)
{
    std::ifstream f (nomFichier);
    if ( !f) return;
    bool typeFichier;
    int longueur, hauteur, nbMiroir, nbSemiMiroir, nbCible;
    f >> typeFichier >> hauteur >> longueur >> nbCible >> nbSemiMiroir >> nbCible;

    int ligne = 0, colonne = 0;

    if ( typeFichier )
    {
        std::vector<std::vector<Case>> tab (hauteur,std::vector<Case>(longueur));
        bool haut, droite, bas, gauche;
        int valeurCase;

        while (!f.eof())
        {
            f >> haut >> droite >> bas >> gauche >> valeurCase;

            Case c {haut,bas,gauche,droite,valeurCase};
            d_terrain[ligne][colonne] = c;
            ++colonne;
            if (colonne == longueur)
            {
                colonne = 0;
                ++hauteur;
            }
        }
    }
    else
    {
        std::vector<std::vector<Element>> tab (hauteur,std::vector<Element>(longueur));
        int valeurCase;

        while (!f.eof())
        {
            f >> valeurCase;
            d_terrain[ligne][colonne] = valeurCase;
            ++colonne;
            if (colonne == longueur)
            {
                colonne = 0;
                ++hauteur;
            }
        }
    }

}


