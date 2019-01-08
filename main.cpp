#include <iostream>
#include <fstream>
#include "Headers/terrain.h"
#include "Headers/terrainMursPleins.h"
#include "Headers/terrainMursFins.h"
#include "Headers/case.h"
#include "Headers/laser.h"
#include "Headers/affichage.h"
#include "Headers/graphics.h"

void run(Laser l,Terrain &t, Affichage &a)
{
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


int main() {


    // --------------------- Mur Plein ----------------------

    TerrainMursPleins *t = new TerrainMursPleins{};
    t->charger("../testTerrainMursPleins1.txt");



    // --------------------- Mur Fin ----------------------
    /*
    TerrainMursFins *t = new TerrainMursFins{};
    t->charger("../testTerrainMursFins2.txt");
    */

    t->print(std::cout);


    // ------------------------------------------------
    // creation et initialisation des tableau du laser
    //  --> tableau de positions et tableau de directions

    std::vector<Position> tableauDePositionsDuLaser;
    tableauDePositionsDuLaser.push_back( Position {0,0} );

    std::vector<int> tableauDeDirectionsDuLaser;
    tableauDeDirectionsDuLaser.push_back(1);


    // creation et initialisation du laser
    //  --> grace au constructeur du laser avec un tableau de positions, un tableau de directions et un terrain
    Laser l { tableauDePositionsDuLaser, tableauDeDirectionsDuLaser , t};

    Affichage a{t->longueur(), t->hauteur()};

    opengraphsize(1000,800);

    a.afficherTerrainMursPleins(*t);
    //a.afficherTerrainMursFins(*t);

    run(l, *t, a);

    getch();

    closegraph();


    delete t;

    return 0;
}
