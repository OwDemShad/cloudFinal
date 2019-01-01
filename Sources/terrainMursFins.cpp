//
// Created by Dorian on 01/12/2018.
//

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

        //t.terrain() = tab;

        bool haut, droite, bas, gauche;
        int valeurCase;

        while (!f.eof()) {
            f >> haut >> droite >> bas >> gauche >> valeurCase;

            Case *c = new Case {haut, droite, bas, gauche, valeurCase};
            d_terrain[ligne][colonne] = c;
            ++colonne;

            if (colonne == longueur) {
                colonne = 0;
                ++ligne;
            }
        }
}

bool TerrainMursFins::caseSuivanteEstLibre(const Position &pos, int direction) const {
    return false;
}

void TerrainMursFins::placeElement(int element, const Position &pos) {
    Terrain::placeElement(element, pos);
}

bool TerrainMursFins::estMur(const Position &pos) const {
    return false;
}

bool TerrainMursFins::estCible(const Position &pos) const {
    return false;
}

int TerrainMursFins::typeMiroir(const Position &pos) const {
    return 0;
}

bool TerrainMursFins::fin() const {
    return false;
}
