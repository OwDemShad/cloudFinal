#include "../Headers/doctest.h"
#include "../../Headers/case.h"

TEST_CASE ( "Les operations sur une case fonctionnent correctement" ) {
    SUBCASE ("Le constructeur vide fonctionne correctement") {
        Case c {};

        REQUIRE_EQ(c.valeur(), 0);
        REQUIRE_EQ(c.estMurHaut(), false);
        REQUIRE_EQ(c.estMurDroit(), false);
        REQUIRE_EQ(c.estMurBas(), false);
        REQUIRE_EQ(c.estMurGauche(), false);
    }

    SUBCASE ("Le constructeur avec toutes les valeurs des attributs en parametres fonctionne correctement") {
        int valeur = 0;
        bool murHaut = true;
        bool murDroit = false;
        bool murBas = false;
        bool murGauche = true;

        Case c { murHaut, murDroit, murBas, murGauche, valeur };

        REQUIRE_EQ(c.valeur(), valeur);
        REQUIRE_EQ(c.estMurHaut(), murHaut);
        REQUIRE_EQ(c.estMurDroit(), murDroit);
        REQUIRE_EQ(c.estMurBas(), murBas);
        REQUIRE_EQ(c.estMurGauche(), murGauche);
    }

    SUBCASE ("Le constructeur avec une valeur fonctionne correctement avec une valeur autre qu'un mur" ) {
        int valeur = 0;
        Case c {valeur};

        REQUIRE_EQ(c.valeur(), valeur);
        REQUIRE_EQ(c.estMurHaut(), false);
        REQUIRE_EQ(c.estMurDroit(), false);
        REQUIRE_EQ(c.estMurBas(), false);
        REQUIRE_EQ(c.estMurGauche(), false);
    }

    SUBCASE ("Le constructeur avec une valeur fonctionne correctement avec une valeur egale a un MUR") {
        int valeur = 1;
        Case c {valeur};

        REQUIRE_EQ(c.valeur(), valeur);
        REQUIRE_EQ(c.estMurHaut(), true);
        REQUIRE_EQ(c.estMurDroit(), true);
        REQUIRE_EQ(c.estMurBas(), true);
        REQUIRE_EQ(c.estMurGauche(), true);
    }

    SUBCASE ("estMurHaut fonctionne correctement") {
        bool murHaut = true;
        bool murDroit = false;
        bool murBas = false;
        bool murGauche = false;
        int valeur = 0;

        Case c1 {murHaut, murDroit, murBas, murGauche, valeur};
        Case c2 {!murHaut, murDroit, murBas, murGauche, valeur};

        REQUIRE_EQ(c1.estMurHaut(), murHaut);
        REQUIRE_EQ(c2.estMurHaut(), !murHaut);
    }

    SUBCASE ("estMurDroit fonctionne correctement") {
        bool murHaut = false;
        bool murDroit = true;
        bool murBas = false;
        bool murGauche = false;
        int valeur = 0;

        Case c1 {murHaut, murDroit, murBas, murGauche, valeur};
        Case c2 {murHaut, !murDroit, murBas, murGauche, valeur};

        REQUIRE_EQ(c1.estMurDroit(), murDroit);
        REQUIRE_EQ(c2.estMurDroit(), !murDroit);
    }

    SUBCASE ("estMurBas fonctionne correctement") {
        bool murHaut = false;
        bool murDroit = false;
        bool murBas = true;
        bool murGauche = false;
        int valeur = 0;

        Case c1 {murHaut, murDroit, murBas, murGauche, valeur};
        Case c2 {murHaut, murDroit, !murBas, murGauche, valeur};

        REQUIRE_EQ(c1.estMurBas(), murBas);
        REQUIRE_EQ(c2.estMurBas(), !murBas);
    }

    SUBCASE ("estMurGauche fonctionne correctement") {
        bool murHaut = false;
        bool murDroit = false;
        bool murBas = false;
        bool murGauche = true;
        int valeur = 0;

        Case c1 {murHaut, murDroit, murBas, murGauche, valeur};
        Case c2 {murHaut, murDroit, murBas, !murGauche, valeur};

        REQUIRE_EQ(c1.estMurGauche(), murGauche);
        REQUIRE_EQ(c2.estMurGauche(), !murGauche);
    }

    SUBCASE ("Le changement de valeur fonctionne correctement") {
        int valeur = 2;
        Case c {};

        c.changerValeur(valeur);

        REQUIRE_EQ(c.valeur(), valeur);
    }

    SUBCASE ("Le retour de valeur ( methode valeur() ) fonctionne correctement") {
        int valeur = 1;
        Case c{valeur};

        REQUIRE_EQ(c.valeur(), valeur);
    }

}
