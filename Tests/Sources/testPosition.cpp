#include "../Headers/doctest.h"
#include "../../Headers/laser.h"

TEST_CASE ("Les operations sur les positions fonctionnent correctement") {
    SUBCASE ("Le constructeur avec x et y en parametres fonctionne") {
        int x = 2;
        int y = 3;

        Position p {x,y};

        REQUIRE_EQ(p.x(), x);
        REQUIRE_EQ(p.y(), y);
    }

    SUBCASE ("Le constructeur par recopie fonctionne") {
        Position p1 {2,3};
        Position p2{p1};

        REQUIRE_EQ(p2.x(), p1.x());
        REQUIRE_EQ(p2.y(), p2.y());
    }

    SUBCASE ("Les retours de x et y sont corrects") {
        int x = 4;
        int y = 5;
        Position p{x,y};

        REQUIRE_EQ(p.x(), x);
        REQUIRE_EQ(p.y(), y);
    }

    SUBCASE ("Le changement de x fonctionne") {
        int x = 1;
        int y = 2;

        Position p{x,y};

        p.changerX(y);

        REQUIRE_EQ(p.x(), y);
    }

    SUBCASE ("Le changement de y fonctionne") {
        int x = 5;
        int y = 6;

        Position p{x,y};

        p.changerY(x);

        REQUIRE_EQ(p.y(), x);
    }
}