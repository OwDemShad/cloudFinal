#include <vector>
#include "../Headers/doctest.h"
#include "../../Headers/laser.h"
#include "../../Headers/terrainMursPleins.h"

TEST_CASE ("Les operations sur le laser fonctionnent parfaitement") {
    SUBCASE ("Le constructeur fonctionne correctement") {
        std::vector<Position> positions;
        std::vector<int> directions;

        Position p {2,3};
        positions.push_back(p);

        int direction = 1; // vers l'est
        directions.push_back(direction);

        Terrain *t = nullptr;

        Laser l {positions, directions, t};

        REQUIRE_EQ(l.position(0).x(), p.x());
        REQUIRE_EQ(l.position(0).y(), p.y());
        REQUIRE_EQ(l.direction(0), direction);
        REQUIRE_EQ(l.terrain(), t);
    }

    SUBCASE ("L'icrementation de points fonctionne") {
        int nbPoints = 0;

        Position p {2,3};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);

        Laser l {positions, directions, t};

        l.incrementePoint();

        REQUIRE_EQ(l.nbPoints(), nbPoints + 1);
    }


    //---------------------------- BUG -------------------------
    SUBCASE ("estSurCible fonctionne correctement") {
        Position p {5,7};
        int direction = 1; // vers l'est
        TerrainMursPleins *t = new TerrainMursPleins{};

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        t->charger("../testTerrainMursPleins1.txt");

        Laser l {positions, directions, t};

        REQUIRE_EQ(l.estSurCible(), true);    //---------------------------- BUG -------------------------
    }

    SUBCASE ("Le retour de la position est correct") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);

        Laser l {positions, directions, t};

        REQUIRE_EQ(l.position(0).x(), p.x());
        REQUIRE_EQ(l.position(0).y(), p.y());

    }

    SUBCASE ("La direction est correcte") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        Laser l {positions, directions, t};

        REQUIRE_EQ(l.direction(0), direction);
    }

    SUBCASE ("Le nombre de points est correct") {
        int nbPoints = 1;

        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        Laser l {positions, directions, t};
        l.incrementePoint();

        REQUIRE_EQ(l.nbPoints(), nbPoints);
    }

    SUBCASE ("Le retour du terrain est correct") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        Laser l {positions, directions, t};

        REQUIRE_EQ(l.terrain(), t);
    }

    SUBCASE ("Le deplacement vers le haut foncitonne") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        Laser l {positions, directions, t};

        l.deplacementHaut(0);

        REQUIRE_EQ(l.position(0).y(), p.y() - 1);
    }

    SUBCASE ("Le deplacement vers la droite foncitonne") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        Laser l {positions, directions, t};

        l.deplacementDroite(0);

        REQUIRE_EQ(l.position(0).x(), p.x() + 1);
    }

    SUBCASE ("Le deplacement vers le bas foncitonne") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        Laser l {positions, directions, t};

        l.deplacementBas(0);

        REQUIRE_EQ(l.position(0).y(), p.y() + 1);
    }

    SUBCASE ("Le deplacement vers le haut foncitonne") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        Laser l {positions, directions, t};

        l.deplacementGauche(0);

        REQUIRE_EQ(l.position(0).x(), p.x() - 1);
    }

    SUBCASE ("Le changement de position fonctionne correctement") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);


        Laser l {positions, directions, t};

        l.changerPosition(2,0);

        REQUIRE_EQ(l.position(0).y(), p.y() + 1);
    }

    SUBCASE ("Le changement de direction fonctionne correctement") {
        Position p {5,7};
        int direction = 1; // vers l'est
        Terrain *t = nullptr;

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);

        Laser l {positions, directions, t};

        l.changerDirection(2,0);

        REQUIRE_EQ(l.direction(0), 2);
    }

    SUBCASE ("peutAvancer fonctionne correctement") {
        Position p {0,0};
        int direction = 1; // vers l'est
        TerrainMursPleins *t = new TerrainMursPleins{};

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);

        t->charger("../testTerrainMursPleins1.txt");

        Laser l {positions, directions, t};

        REQUIRE_EQ(l.peutAvancer(), true);
    }

    SUBCASE ("La destruction de la cible fonctionne correctement") {
        Position p {5,7};
        int direction = 1; // vers l'est
        TerrainMursPleins *t = new TerrainMursPleins{};

        std::vector<Position> positions;
        std::vector<int> directions;

        positions.push_back(p);
        directions.push_back(direction);

        t->charger("../testTerrainMursPleins1.txt");

        Laser l {positions, directions, t};

        int nbCibles = l.terrain()->nbCibles();

        l.detruitCibles();

        REQUIRE_EQ(l.terrain()->estCible(l.position(0)), false);
        REQUIRE_EQ(l.terrain()->nbCibles(), nbCibles - 1);

    }

}
