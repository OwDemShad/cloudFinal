#include "../Headers/doctest.h"
#include "../../Headers/terrainMursFins.h"

TEST_CASE("Les opérations du terrainMursFins sont correctes")
{
    SUBCASE("Le constructeur de terrainMursFins fonctionne") {
        int longueur = 2, hauteur = 3, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursFins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

        REQUIRE_EQ(t.longueur(), 2);
        REQUIRE_EQ(t.hauteur(), 3);
        REQUIRE_EQ(t.nbMiroirs(), 1);
        REQUIRE_EQ(t.nbSemiMiroirs(), 0);
        REQUIRE_EQ(t.nbCibles(), 1);


    }

    SUBCASE("position libre fonctionne") {
        TerrainMursFins t{};
        t.charger("../testTerrainMursFins1.txt");

        Position p{1,1};
        REQUIRE_EQ(t.positionLibre(p),true);
    }

    SUBCASE("position valide fonctionne") {
        TerrainMursFins t{};
        t.charger("../testTerrainMursFins1.txt");

        Position p{1,1};
        REQUIRE_EQ(t.positionValide(p),true);
        p = {4,4};
        REQUIRE_EQ(t.positionValide(p),false);
    }

    SUBCASE("le placement d'element est correct") {
        TerrainMursFins t{};
        t.charger("../testTerrainMursFins1.txt");

        Position position{1,0};
        Position position2{1,1};
        t.placeElement(MIROIR1,position);
        t.placeElement(CIBLE,position2);

        REQUIRE_EQ(t.typeMiroir(position), MIROIR1);
        REQUIRE_EQ(t.estCible(position2), true);
    }


    SUBCASE("destrucition cible marche") {

        TerrainMursFins t{};
        t.charger("../testTerrainMursFins1.txt");

        Position position{1,0};
        t.placeElement(CIBLE,position);
        t.detruitCible(position);

        REQUIRE_EQ(t.estCible(position),false);
    }

    SUBCASE("type miroir marche") {
        TerrainMursFins t{};
        t.charger("../testTerrainMursFins1.txt");

        Position position{1,0};
        t.placeElement(MUR,position);
        Position position2{1,1};
        t.placeElement(MIROIR1,position2);

        REQUIRE_EQ(t.typeMiroir(position),MUR);
        REQUIRE_EQ(t.typeMiroir(position2),MIROIR1);
    }


//    // --------------- A REFAIRE CAR COPIE COLLE DE TESTTERRAINMURSPLEINS -----------------
    SUBCASE("la methode charger fonctionne"){
        TerrainMursFins t{};
        t.charger("../testTerrainMursFins1.txt");

        REQUIRE_EQ(t.hauteur(),2);
        REQUIRE_EQ(t.longueur(),2);
        REQUIRE_EQ(t.nbMiroirs(),2);
        REQUIRE_EQ(t.nbSemiMiroirs(),0);
        REQUIRE_EQ(t.nbCibles(),1);

        Position p{0,0};
        REQUIRE_EQ(t.estMurHaut(p),false);
        REQUIRE_EQ(t.estMurDroit(p),false);
        REQUIRE_EQ(t.estMurBas(p),true);
        REQUIRE_EQ(t.estMurGauche(p),false);
        REQUIRE_EQ(t.positionLibre(p),true);
        REQUIRE_EQ(t.estCible(p),false);

        p = {0,1};
        REQUIRE_EQ(t.estMurHaut(p),true);
        REQUIRE_EQ(t.estMurDroit(p),false);
        REQUIRE_EQ(t.estMurBas(p),false);
        REQUIRE_EQ(t.estMurGauche(p),false);
        REQUIRE_EQ(t.positionLibre(p),false);
        REQUIRE_EQ(t.estCible(p),true);

        p = {1,0};
        REQUIRE_EQ(t.estMurHaut(p),false);
        REQUIRE_EQ(t.estMurDroit(p),false);
        REQUIRE_EQ(t.estMurBas(p),false);
        REQUIRE_EQ(t.estMurGauche(p),false);
        REQUIRE_EQ(t.positionLibre(p),true);
        REQUIRE_EQ(t.estCible(p),false);

        p = {1,1};
        REQUIRE_EQ(t.estMurHaut(p),false);
        REQUIRE_EQ(t.estMurDroit(p),false);
        REQUIRE_EQ(t.estMurBas(p),false);
        REQUIRE_EQ(t.estMurGauche(p),false);
        REQUIRE_EQ(t.positionLibre(p),true);
        REQUIRE_EQ(t.estCible(p),false);

     }

//    SUBCASE("saisir la position d'un mur fonctionne") {
//
//    }

}
