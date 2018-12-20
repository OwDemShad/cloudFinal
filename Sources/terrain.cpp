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




    // -------------------- Methodes de rappel --------------------

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


    // -------------------- Methodes de changement --------------------

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


    // -------------------- Methodes de verification de l'etat du jeu --------------------

bool Terrain::positionLibre(Position &pos) const
{
    return d_terrain[pos.y()][pos.x()].valeur() == LIBRE ;
}

bool Terrain::positionValide(Position &pos) const
{
    return ( pos.x() < d_longueur && pos.y() < d_hauteur);
}

void Terrain::placeElement(int element, const Position &pos)
{
    d_terrain[pos.y()][pos.x()].changerValeur(element);
}

Position Terrain::saisirPositionMiroir()
{
    bool positionEstValide = false;
    int x, y;
    while (!positionEstValide)
    {
        std::cout << "Entrer x : " ;
        std::cin >> x;

        std::cout << "Entrer y : " ;
        std::cin >> y;
        Position pos{x,y};
        if (positionValide(pos) && positionLibre(pos))
        {
           positionEstValide = true;
            return pos;
        }
        else
        {
            std::cout << "Position invalide, veuillez choisir une position valide" << std::endl;
        }
    }

}

int Terrain::saisieTypeMiroir(bool typeMiroirSimple)
{
    int miroir= 0;
    bool estValide = false;
    if (typeMiroirSimple)
    {
        while (!estValide) {
            std::cout << "Saisir un type de miroir : " << std::endl << "1 = \\" << std::endl << "2 = /" << std::endl;
            std::cin >> miroir;
            if (miroir != 1 && miroir != 2) // on verifie si le type saisie est un miroir
            {
                std::cout << "Type de miroir invalide, ecrire 1 ou 2 " << std::endl;
            }else
            {
                estValide = true;
            }
        }
    }
    else
    {
        while (!estValide) {
            std::cout << "Saisir un type de semi miroir : " << std::endl << " 3 = \\" << std::endl << "4 = /" << std::endl;
            std::cin >> miroir;
            if (miroir != 3 && miroir != 4) // on verifie si le type saisie est un miroir
            {
                std::cout << "Type de miroir invalide, ecrire 1 ou 2 " << std::endl;
            }else
            {
                estValide = true;
            }
        }
    }
    return miroir;
}

void Terrain::placerMiroirs()
{
    int miroir;
    if (d_nbMiroirs > 0)
    {

        for (int i = 1; i <= d_nbMiroirs; ++i)
        {
            std::cout << "entrer la position du miroir : " << i << std::endl;
            Position pos = saisirPositionMiroir();
            miroir =saisieTypeMiroir(true);
            placeElement(miroir+1,pos);
            print(std::cout);
        }

    }
    if (d_nbSemiMiroirs > 0)
    {

        for (int i = 1; i <= d_nbSemiMiroirs; ++i)
        {
            std::cout << "entrer la position du semi miroir : " << i << std::endl;
            Position pos = saisirPositionMiroir();
            miroir =saisieTypeMiroir(false);
            placeElement(miroir+1,pos);
        }

    }
}

void Terrain::detruitCible(Position &pos)
{
    d_terrain[pos.y()][pos.x()] = LIBRE;
}



