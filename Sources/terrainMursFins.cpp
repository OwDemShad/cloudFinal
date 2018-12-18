//
// Created by Dorian on 01/12/2018.
//

#include <fstream>
#include "../Headers/terrainMursFins.h"


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

    this->longueur(longueur);
    this->hauteur(hauteur);
    this->nbMiroirs(nbMiroirs);
    this->nbSemiMiroirs(nbSemiMiroirs);
    this->nbCibles(nbCibles);

    std::vector<std::vector<Case>> tab (hauteur,std::vector<Case>(longueur));

        //t.terrain() = tab;

        bool haut, droite, bas, gauche;
        int valeurCase;

        while (!f.eof()) {
            f >> haut >> droite >> bas >> gauche >> valeurCase;

            Case c{haut, bas, gauche, droite, valeurCase};
            this->terrain()[ligne][colonne] = c;
            ++colonne;

            if (colonne == longueur) {
                colonne = 0;
                ++ligne;
            }
        }
}
