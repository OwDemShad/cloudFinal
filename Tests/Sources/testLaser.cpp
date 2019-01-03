#include "../Headers/doctest.h"
#include "../../Headers/laser.h"

TEST_CASE ("Les operations sur le laser fonctionnent parfaitement") {
    SUBCASE ("Le constructeur fonctionne correctement") {
        Position p {2,3};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        REQUIRE_EQ(l.position(), p);
        REQUIRE_EQ(l.direction(), direction);
        REQUIRE_EQ(l.terrain(), t);
    }

    SUBCASE ("L'icrementation de points fonctionne") {
        int nbPoints = 0;

        Position p {2,3};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        l.incrementePoint();

        REQUIRE_EQ(l.nbPoints(), nbPoints + 1);
    }

    SUBCASE ("estSurCible fonctionne correctement") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        t->charger("testTerrainMursPleins1.txt");

        Laser l {p, direction, t};

        REQUIRE_EQ(l.estSurCible(), true);
    }

    SUBCASE ("Le retour de la position est correct") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        REQUIRE_EQ(l.position(), p);
    }

    SUBCASE ("La direction est correcte") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        REQUIRE_EQ(l.direction(), direction);
    }

    SUBCASE ("Le nombre de points est correct") {
        int nbPoints = 3;

        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        REQUIRE_EQ(l.nbPoints(), nbPoints);
    }

    SUBCASE ("Le retour du terrain est correct") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        REQUIRE_EQ(l.terrain(), t);
    }

    SUBCASE ("Le deplacement vers le haut foncitonne") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        l.deplacementHaut();

        REQUIRE_EQ(l.position().y(), p.y() - 1);
    }

    SUBCASE ("Le deplacement vers la droite foncitonne") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        l.deplacementDroite();

        REQUIRE_EQ(l.position().x(), p.x() + 1);
    }

    SUBCASE ("Le deplacement vers le bas foncitonne") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        l.deplacementBas();

        REQUIRE_EQ(l.position().y(), p.y() + 1);
    }

    SUBCASE ("Le deplacement vers le haut foncitonne") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        l.deplacementGauche();

        REQUIRE_EQ(l.position().x(), p.x() - 1);
    }

    SUBCASE ("Le changement de position fonctionne correctement") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        l.changerPosition(2);

        REQUIRE_EQ(l.position().y(), p.y() + 1);
    }

    SUBCASE ("Le changement de direction fonctionne correctement") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        Laser l {p, direction, t};

        l.changerDirection(2);

        REQUIRE_EQ(l.direction(), 2);
    }

    SUBCASE ("peutAvancer fonctionne correctement") {
        Position p {0,0};
        int direction = 1; // vers l'est
        Terrain *t;

        t->charger("testTerrainMursPleins1.txt");

        Laser l {p, direction, t};

        REQUIRE_EQ(l.peutAvancer(), true);
    }

    SUBCASE ("La destruction de la cible fonctionne correctement") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t;

        t->charger("testTerrainMursPleins1.txt");

        Laser l {p, direction, t};

        int nbCibles = l.terrain()->nbCibles();

        l.detruitCible();

        REQUIRE_EQ(l.terrain()->estCible(l.position()), false);
        REQUIRE_EQ(l.terrain()->nbCibles(), nbCibles - 1);

    }

}
