#include "../Headers/doctest.h"
#include "../../Headers/terrainMursPleins.h"

TEST_CASE("Les opérations du terrainMursPleins sont correctes")
{
    SUBCASE("Le constructeur de terrainMursPleins fonctionne")
    {
        int longueur = 2, hauteur = 3, nbMiroirs = 1, nbSemiMiroirs = 0, nbCibles = 1;
        TerrainMursPleins t{longueur, hauteur, nbMiroirs, nbSemiMiroirs, nbCibles};

        REQUIRE_EQ(t.longueur(), 2);
        REQUIRE_EQ(t.hauteur(), 3);
        REQUIRE_EQ(t.nbMiroirs(), 1);
        REQUIRE_EQ(t.nbSemiMiroirs(), 0);
        REQUIRE_EQ(t.nbCibles(), 1);


    }


}
