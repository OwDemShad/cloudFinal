//
// Created by Dorian on 01/12/2018.
//

#include "../Headers/terrainMursPleins.h"
#include <fstream>

TerrainMursPleins::TerrainMursPleins() : Terrain{}
{}

TerrainMursPleins::TerrainMursPleins(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles) : Terrain{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles}
{}

bool TerrainMursPleins::caseSuivanteEstLibre(const Position &pos, int direction) const
{
    switch(direction)
    {
        case 0 :
            if(pos.y() == 0) return false;
            else return !estMur(Position{pos.x(), pos.y() - 1});

        case 1 :
            if(pos.x() == d_longueur) return false;
            else return !estMur(Position{pos.x() + 1, pos.y()});

        case 2 :
            if(pos.y() == d_hauteur) return false;
            else return !estMur(Position{pos.x(), pos.y() + 1});

        case 3 :
            if(pos.x() == 0) return false;
            else return !estMur(Position{pos.x() - 1, pos.y()});

        default: break;
    }
}

void TerrainMursPleins::placeElement(int element, const Position &pos)
{
    d_terrain[pos.y()][pos.x()] = element;
}

bool TerrainMursPleins::estMur(const Position &pos) const
{
    return d_terrain[pos.y()][pos.x()].valeur() == MUR;
}

bool TerrainMursPleins::estCible(const Position &pos) const
{
    return d_terrain[pos.y()][pos.x()].valeur() == CIBLE;
}

int TerrainMursPleins::typeMiroir(const Position &pos) const
{
    return d_terrain[pos.y()][pos.x()].valeur();
}

bool TerrainMursPleins::fin() const
{

}

void TerrainMursPleins::charger(const std::string &nomFichier)
{
    std::ifstream f (nomFichier);

    if ( !f) return;

    bool typeTerrain;
    int longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles;

    f >> typeTerrain >> hauteur >> longueur >> nbMiroirs >> nbSemiMiroirs >> nbCibles;
    int ligne = 0, colonne = 0;

    d_longueur = longueur;
    d_hauteur = hauteur;
    d_nbMiroirs = nbMiroirs;
    d_nbSemiMiroirs = nbSemiMiroirs;
    d_nbCibles = nbCibles;

    std::vector<std::vector<Element>> tab (static_cast<unsigned int>(hauteur), std::vector<Element>(
            static_cast<unsigned int>(longueur)));

    this->terrain() = tab;

    int valeurCase;

    while (!f.eof())
    {
        f >> valeurCase;
        this->terrain()[ligne][colonne] = valeurCase;
        ++colonne;

        if (colonne == longueur)
        {
            colonne = 0;
            ++ligne;
        }
    }


}
