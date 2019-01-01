//
// Created by OwDemShad on 04/12/2018.
//

#ifndef PROJETLASER_ELEMENT_H
#define PROJETLASER_ELEMENT_H


class Element
{
public:
    Element();
    Element (int valeur);
    ~Element();

    virtual void changerValeur(int valeur) ;
    virtual  int valeur() const ;

private:
    int d_valeur;
};


#endif //PROJETLASER_ELEMENT_H
