//
// Created by OwDemShad on 04/12/2018.
//

#include "../Headers/element.h"

Element::Element() : d_valeur{0}
{}

Element::Element(int valeur) : d_valeur{valeur}
{}

int Element::valeur() const
{
    return d_valeur;
}

void Element::changerValeur(int valeur)
{
    d_valeur = valeur;
}
