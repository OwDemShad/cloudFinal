#include <iostream>
#include <fstream>
#include "Headers/terrain.h"
#include "Headers/terrainMursPleins.h"
#include "Headers/terrainMursFins.h"
#include "Headers/case.h"

void charger(const std::string& nomFichier, TerrainMursPleins &t)
{
    std::ifstream f (nomFichier);

    if ( !f) return;

    bool typeTerrain;
    int longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles;

    f >> typeTerrain >> hauteur >> longueur >> nbMiroirs >> nbSemiMiroirs >> nbCibles;

    int ligne = 0, colonne = 0;

    // terrain avec murs fins
    if ( typeTerrain )
    {
        // type fichier vaut 1

        std::vector<std::vector<Case>> tab (hauteur,std::vector<Case>(longueur));

        //t.terrain() = tab;

        bool haut, droite, bas, gauche;
        int valeurCase;

        while (!f.eof())
        {
            f >> haut >> droite >> bas >> gauche >> valeurCase;

            Case c {haut,bas,gauche,droite,valeurCase};
            t.terrain()[ligne][colonne] = c;
            ++colonne;

            if (colonne == longueur)
            {
                colonne = 0;
                ++ligne;
            }
        }
    }
    // terrain avec murs pleins
    else
    {
        // type fichier vaut 0

        t = {hauteur, longueur, nbMiroirs, nbSemiMiroirs, nbCibles};

        std::vector<std::vector<Element>> tab (hauteur,std::vector<Element>(longueur));

        t.terrain() = tab;

        int valeurCase;

        while (!f.eof())
        {
            f >> valeurCase;
            t.terrain()[ligne][colonne] = valeurCase;
            ++colonne;

            if (colonne == longueur)
            {
                colonne = 0;
                ++ligne;
            }
        }
    }
}


//int main() {
//
//    TerrainMursPleins t;
//    charger("../testTerrain1.txt", t);
//
//    t.print(std::cout);
//
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}