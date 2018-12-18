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


Terrain::Terrain() : d_longueur{0}, d_hauteur{0}, d_nbMiroirs{0}, d_nbSemiMiroirs{0}, d_nbCibles{0}, d_terrain{}
{}

Terrain::Terrain(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles) :
    d_longueur{longueur}, d_hauteur{hauteur}, d_nbMiroirs{nbMiroirs}, d_nbSemiMiroirs{nbSemiMiroirs}, d_nbCibles{nbCibles},
    d_terrain{}
{

}


Terrain::~Terrain() {

}

std::vector<std::vector<Element>>& Terrain::terrain() {
    return d_terrain;
}


// TEST
void Terrain::print(std::ostream &ost) const
{
    ost << "Longueur : " << d_longueur << " Hauteur : " << d_hauteur << std::endl;
    ost << "Nb miroirs : " << d_nbMiroirs << " Nb semi miroirs : " << d_nbSemiMiroirs << std::endl;
    ost << "Nb cibles : " << d_nbCibles << std::endl;

    for(int i = 0; i < d_terrain.size(); ++i)
    {
        for(int j = 0; j < d_terrain[i].size(); ++j)
        {
            std::cout << d_terrain[i][j].valeur() << " ";
        }

        std::cout << std::endl;
    }
}

void Terrain::decrementeNombreDeCibles()
{
    --d_nbCibles;
}

int Terrain::longueur() const
{
    return d_longueur;
}

int Terrain::hauteur() const
{
    return d_hauteur;
}

int Terrain::nbMiroirs() const
{
    return d_nbMiroirs;
}

int Terrain::nbSemiMiroirs() const
{
    return d_nbSemiMiroirs;
}

int Terrain::nbCibles() const
{
    return d_nbCibles;
}

void Terrain::longueur(int longueur)
{
    d_longueur = longueur;
}

void Terrain::hauteur(int hauteur)
{
    d_hauteur = hauteur;
}

void Terrain::nbMiroirs(int nbMiroirs)
{
    d_nbMiroirs = nbMiroirs;
}

void Terrain::nbSemiMiroirs(int nbSemiMiroirs)
{
    d_nbSemiMiroirs = nbSemiMiroirs;
}

void Terrain::nbCibles(int nbCibles)
{
    d_nbCibles = nbCibles;
}

/*
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
*/

