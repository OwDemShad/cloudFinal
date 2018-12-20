#include <iostream>
#include <fstream>
#include "Headers/terrain.h"
#include "Headers/terrainMursPleins.h"
#include "Headers/terrainMursFins.h"
#include "Headers/case.h"
#include "Headers/laser.h"

void charger(const std::string& nomFichier, TerrainMursPleins &t)
{
    std::ifstream f (nomFichier);

    if ( !f) return;

    bool typeTerrain;

    f >> typeTerrain ;


    // terrain avec murs fins
    if ( typeTerrain )
    {
//        // type fichier vaut 1
//
//        std::vector<std::vector<Case>> tab (hauteur,std::vector<Case>(longueur));
//
//        //t.terrain() = tab;
//
//        bool haut, droite, bas, gauche;
//        int valeurCase;
//
//        while (!f.eof())
//        {
//            f >> haut >> droite >> bas >> gauche >> valeurCase;
//
//            Case c {haut,bas,gauche,droite,valeurCase};
//            t.terrain()[ligne][colonne] = c;
//            ++colonne;
//
//            if (colonne == longueur)
//            {
//                colonne = 0;
//                ++ligne;
//            }
//        }
    }
        // terrain avec murs pleins
    else
    {
        // type fichier vaut 0
        t.charger(nomFichier);

    }
}

void run(Laser l,TerrainMursPleins *t)
{
    //bool laserEstBloque = false;
    t->placerMiroirs();

    while ( l.peutAvancer())
    {
        l.avance();
    }
}


int main() {

    TerrainMursPleins *t = new TerrainMursPleins{};
    t->charger("../testTerrain1.txt");

    t->print(std::cout);

    Laser l { {0,0}, 1 , t};

    run(l, t);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
