#include "../Headers/doctest.h"
#include "../../Headers/terrainMursFins.h"

TEST_CASE("Les opérations du terrainMursFins sont correctes")
{

    SUBCASE("Le constructeur de terrainMursFins fonctionne")
    {
        int longueur = 2, hauteur = 3, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursFins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

                REQUIRE_EQ(t.longueur(), 2);
                REQUIRE_EQ(t.hauteur(), 3);
                REQUIRE_EQ(t.nbMiroirs(), 1);
                REQUIRE_EQ(t.nbSemiMiroirs(), 0);
                REQUIRE_EQ(t.nbCibles(), 1);


    }

    SUBCASE{"position libre fonctionne"}{
        int longueur = 2, hauteur = 3, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursFins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

        Position p{1,1};
                REQUIRE_EQ(t.positionLibre(p),true);
    }

    SUBCASE{"position valide fonctionne"}{
        int longueur = 2, hauteur = 3, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursFins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

        Position p{1,1};
                REQUIRE_EQ(t.positionValide(p),true);
        p{4,4};
                REQUIRE_EQ(t.positionValide(p),false);
    }


    // --------------- A REFAIRE CAR COPIE COLLE DE TESTTERRAINMURSPLEINS -----------------
    SUBCASE{"le placement d'element est correct"}{
        int longueur = 2, hauteur = 2, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursPleins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

        Position position{1,0};
        Position position2{4,2};
        t.placeElement(1,position);
        t.placeElement(4,position2);

        REQUIRE_EQ(t.estMur(position),true);
        REQUIRE_EQ(t.estCible(position2),true);
    }

    // --------------- A REFAIRE CAR COPIE COLLE DE TESTTERRAINMURSPLEINS -----------------
     SUBCASE{"la prochaine case est correctement identifie"}{
         int longueur = 2, hauteur = 2, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
         TerrainMursPleins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

         Position position{1,0};
         Position position2{1,2};
         t.placeElement(1,position);
         t.placeElement(1,position2);

         REQUIRE_EQ(t.estMur())

         Position p{1,1};
                 REQUIRE_EQ(t.caseSuivanteEstLibre(p,0),false);
                 REQUIRE_EQ(t.caseSuivanteEstLibre(p,1),true);
                 REQUIRE_EQ(t.caseSuivanteEstLibre(p,2),false);
                 REQUIRE_EQ(t.caseSuivanteEstLibre(p,3),true);
     }

    SUBCASE{"destrucition cible marche"}{
        int longueur = 2, hauteur = 2, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursFins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

        Position position{1,0};
        t.placeElement(4,position));
        t.detruitCible(position);

                REQUIRE_EQ(t.estCible(position),false);
    }

    SUBCASE{"type miroir marche"}{
        int longueur = 2, hauteur = 2, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursFins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

        Position position{1,0};
        t.placeElement(1,position);
        Position position2{1,1};
        t.placeElement(2,position2);

                REQUIRE_EQ(t.typeMiroir(position),1);
                REQUIRE_EQ(t.typeMiroir(position2),2);
    }

    SUBCASE{"saisir la position d'un mur fonctionne"}{

    }


    // --------------- A REFAIRE CAR COPIE COLLE DE TESTTERRAINMURSPLEINS -----------------
    SUBCASE{"la methode charger fonctionne"}{
            TerrainMursPleins t{};
            t.charger("../testTerrainMursPleins2.txt");

            REQUIRE_EQ(t.hauteur(),5)
            REQUIRE_EQ(t.longueur(),5)
            REQUIRE_EQ(t.nbMiroirs(),5)
            REQUIRE_EQ(t.nbSemiMiroirs(),0)
            REQUIRE_EQ(t.nbCibles(),1)

            Position p{0,4};
            REQUIRE_EQ(t.typeMiroir(p),1);
             p{1,0};
            REQUIRE_EQ(t.typeMiroir(p),1);
             p{1,1};
            REQUIRE_EQ(t.typeMiroir(p),1);
             p{2,1};
            REQUIRE_EQ(t.typeMiroir(p),1);
             p{2,2};
            REQUIRE_EQ(t.typeMiroir(p),1);
             p{3,3};
            REQUIRE_EQ(t.typeMiroir(p),1);
            p{3,2};
            REQUIRE_EQ(t.estCible(p),true);

     }

}
