#include "../Headers/doctest.h"
#include "../../Headers/terrainMursPleins.h"

TEST_CASE("Les opérations du terrainMursPleins sont correctes")
{
    SUBCASE("Le constructeur de terrainMursPleins fonctionne") {
        int longueur = 2, hauteur = 3, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursPleins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

        REQUIRE_EQ(t.longueur(), 2);
        REQUIRE_EQ(t.hauteur(), 3);
        REQUIRE_EQ(t.nbMiroirs(), 1);
        REQUIRE_EQ(t.nbSemiMiroirs(), 0);
        REQUIRE_EQ(t.nbCibles(), 1);


    }

    SUBCASE("position libre fonctionne") {

        TerrainMursPleins t{};
        t.charger("../testTerrainMursPleins1.txt");

        Position p{1,1};
        REQUIRE_EQ(t.positionLibre(p), false);

        p = {2,1};
        REQUIRE_EQ(t.positionLibre(p), true);
    }

    SUBCASE("position valide fonctionne") {
        TerrainMursPleins t{};
        t.charger("../testTerrainMursPleins1.txt");

        Position p{1,1};
        REQUIRE_EQ(t.positionValide(p),true);
        p = {8,0};
        REQUIRE_EQ(t.positionValide(p),false);
    }


    SUBCASE("le placement d'element est correct") {
        TerrainMursPleins t{};
        t.charger("../testTerrainMursPleins1.txt");

        Position position{1,0};
        Position position2{4,2};
        t.placeElement(MUR,position);
        t.placeElement(CIBLE,position2);

        REQUIRE_EQ(t.estMur(position),true);
        REQUIRE_EQ(t.estCible(position2),true);
    }


   //------------------------- A verifier les tests ----------------
//    SUBCASE("la prochaine case est correctement identifiee") {
//        TerrainMursPleins t{};
//        t.charger("../testTerrainMursPleins1.txt");
//
//        Position position{1,0};
//        Position position2{1,2};
//        t.placeElement(MUR,position);
//        t.placeElement(MIROIR2,position2);
//
//        REQUIRE_EQ(t.estMur(position), true);
//        REQUIRE_EQ(t.estMur(position2), false);
//        REQUIRE_EQ(t.typeMiroir(position2), MIROIR2);
//        REQUIRE_EQ(t.estMur( Position { 2,2 }), false);
//
//        Position p{1,1};
//        REQUIRE_EQ(t.caseSuivanteEstLibre(p,0),false);
//        REQUIRE_EQ(t.caseSuivanteEstLibre(p,1),true);
//        REQUIRE_EQ(t.caseSuivanteEstLibre(p,2),false);
//        REQUIRE_EQ(t.caseSuivanteEstLibre(p,3),true);
//    }
//
    SUBCASE("destrucition cible marche"){
        TerrainMursPleins t{};
        t.charger("../testTerrainMursPleins1.txt");

        Position position{1,0};
        t.placeElement(CIBLE,position);
        t.detruitCible(position);

        REQUIRE_EQ(t.estCible(position),false);
    }

    SUBCASE("type miroir marche"){
        TerrainMursPleins t{};
        t.charger("../testTerrainMursPleins1.txt");

        Position position{1,0};
        t.placeElement(1,position);
        Position position2{1,1};
        t.placeElement(2,position2);

        REQUIRE_EQ(t.typeMiroir(position),1);
        REQUIRE_EQ(t.typeMiroir(position2),2);
    }

//    SUBCASE("saisir la position d'un mur fonctionne"){
//
//    }
//
    SUBCASE("la methode charger fonctionne"){
        TerrainMursPleins t{};
        t.charger("../testTerrainMursPleins2.txt");

        REQUIRE_EQ(t.hauteur(),5);
        REQUIRE_EQ(t.longueur(),5);
        REQUIRE_EQ(t.nbMiroirs(),5);
        REQUIRE_EQ(t.nbSemiMiroirs(),0);
        REQUIRE_EQ(t.nbCibles(),1);

        Position p {4,0};

        REQUIRE_EQ(t.typeMiroir(p),1);

        p = {1,0};
        REQUIRE_EQ(t.typeMiroir(p),0);

        p = {1,1};
        REQUIRE_EQ(t.typeMiroir(p),1);

        p = {2,1};
        REQUIRE_EQ(t.typeMiroir(p),0);

        p = {2,2};
        REQUIRE_EQ(t.typeMiroir(p),1);

        p = {3,3};
        REQUIRE_EQ(t.typeMiroir(p),1);

        p = {2,3};
        REQUIRE_EQ(t.estCible(p),true);

    }
}


