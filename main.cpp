#include <iostream>
#include <fstream>
#include "Headers/terrain.h"
#include "Headers/terrainMursPleins.h"
#include "Headers/terrainMursFins.h"
#include "Headers/case.h"
#include "Headers/laser.h"
#include "Headers/affichage.h"
#include "Headers/graphics.h"

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

void run(Laser l,Terrain &t, Affichage &a)
{
    //bool laserEstBloque = false;
    t.placerMiroirs();
    a.afficherMiroirs(t);
    a.afficherSemiMiroirs(t);
    a.afficherLaserPremierTraitGrille(l);

    while ( l.peutAvancer() )
    {
        a.afficherLaserPremierDemiTrait(l);
        a.afficherLaserDeuxiemeDemiTrait(l);
        l.avance();
    }
    std::cout << "Points : " << l.nbPoints() << std::endl;

}


//int main() {
//
//
//    // --------------------- Mur Plein ----------------------
//
//    TerrainMursPleins *t = new TerrainMursPleins{};
//    t->charger("../testTerrainMursPleinsAvecSemiMiroirs1.txt");
//
//
//
//    // --------------------- Mur Fin ----------------------
//    /*
//    TerrainMursFins *t = new TerrainMursFins{};
//    t->charger("../testTerrainMursFins2.txt");
//    */
//
//    t->print(std::cout);
//
//
//    // ------------------------------------------------
//    // creation et initialisation des tableau du laser
//    //  --> tableau de positions et tableau de directions
//
//    std::vector<Position> tableauDePositionsDuLaser;
//    tableauDePositionsDuLaser.push_back( Position {0,0} );
//
//    std::vector<int> tableauDeDirectionsDuLaser;
//    tableauDeDirectionsDuLaser.push_back(1);
//
//
//    // creation et initialisation du laser
//    //  --> grace au constructeur du laser avec un tableau de positions, un tableau de directions et un terrain
//    Laser l { tableauDePositionsDuLaser, tableauDeDirectionsDuLaser , t};
//
//    Affichage a{t->longueur(), t->hauteur()};
//
//    opengraphsize(1000,800);
//
//    a.afficherTerrainMursPleins(*t);
//    //a.afficherTerrainMursFins(*t);
//
//    run(l, *t, a);
//
//    getch();
//
//    closegraph();
//
//
//    delete t;
//
//    return 0;
//}
