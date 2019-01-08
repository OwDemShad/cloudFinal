#include <fstream>
#include "../Headers/terrainMursFins.h"


TerrainMursFins::TerrainMursFins() : Terrain{}
{}

TerrainMursFins::TerrainMursFins(int longueur, int hauteur, int nbMiroirs, int nbSemiMiroirs, int nbCibles) : Terrain(longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles)
{}

void TerrainMursFins::charger(const std::string &nomFichier)
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

    std::vector<std::vector<Case>> tab (hauteur,std::vector<Case>(longueur));

        d_terrain = tab;

        bool haut, droite, bas, gauche;
        int valeurCase;

        while (!f.eof()) {
            f >> haut >> droite >> bas >> gauche >> valeurCase;

            Case c {haut, droite, bas, gauche, valeurCase};
            d_terrain[ligne][colonne] = c;
            ++colonne;

            if (colonne == longueur) {
                colonne = 0;
                ++ligne;
            }
        }
}

bool TerrainMursFins::caseSuivanteEstLibre(const Position &pos, int direction) const
{
    switch(direction)
    {
        case 0 :
            if(pos.y() == 0) return false;
            else return !estMurHaut(pos);

        case 1 :
            if(pos.x() == d_longueur) return false;
            else return !estMurDroit(pos);

        case 2 :
            if(pos.y() == d_hauteur) return false;
            else return !estMurBas(pos);

        case 3 :
            if(pos.x() == 0) return false;
            else return !estMurGauche(pos);

        default: break;
    }
}

void TerrainMursFins::placeElement(int element, const Position &pos) {
    Terrain::placeElement(element, pos);
}


bool TerrainMursFins::fin() const {
    return false;
}

bool TerrainMursFins::estMurHaut(const Position &pos) const
{
    return d_terrain[pos.y()][pos.x()].estMurHaut();
}

bool TerrainMursFins::estMurDroit(const Position &pos) const
{
    return d_terrain[pos.y()][pos.x()].estMurDroit();
}

bool TerrainMursFins::estMurBas(const Position &pos) const
{
    return d_terrain[pos.y()][pos.x()].estMurBas();
}

bool TerrainMursFins::estMurGauche(const Position &pos) const
{
    return d_terrain[pos.y()][pos.x()].estMurGauche();
}
