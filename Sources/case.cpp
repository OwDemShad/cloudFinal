//
//  case.cpp
//  Laser
//
//  Created by Thibaud B. on 14/11/2018.
//  Copyright © 2018 Thibaud B. All rights reserved.
//

#include "../Headers/case.h"
#include "../Headers/terrain.h"

Case::Case() : d_valeur{0}, d_murGauche{0}, d_murBas{0}, d_murDroit{0}, d_murHaut{0}
{

}

Case::Case(bool murHaut, bool murDroit, bool murBas, bool murGauche, int val) : d_valeur{val},d_murHaut{murHaut}, d_murDroit{murDroit},
                                                                       d_murBas{murBas}, d_murGauche{murGauche}
{}

Case::Case(int valeur) : d_valeur(valeur),d_murGauche{1}, d_murBas{1}, d_murDroit{1}, d_murHaut{1}
{
    if (d_valeur != MUR)
    {
        d_murGauche = false;
        d_murBas = false;
        d_murDroit = false;
        d_murHaut = false;
    }
}

bool Case::estMurHaut() const
{
    return d_murHaut;
}

bool Case::estMurDroit() const
{
    return d_murDroit;
}

bool Case::estMurBas() const
{
    return d_murBas;
}

bool Case::estMurGauche() const
{
    return d_murGauche;
}

void Case::changerValeur(int valeur) {
    d_valeur = valeur;
}

int Case::valeur() const {
    return d_valeur;
}
